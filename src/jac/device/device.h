#pragma once

#include <jac/link/mux.h>
#include <jac/link/router.h>
#include <jac/link/routerCommunicator.h>
#include "util/lock.h"

#include "controller.h"
#include "uploader.h"
#include "logger.h"
#include "util/machineCtrl.h"

#include <atomic>
#include <filesystem>
#include <optional>
#include <sstream>
#include <thread>


namespace jac {


template<class Machine>
class Device : public MachineCtrl {
    Router _router;

    std::optional<Uploader> _uploader;
    std::optional<Controller> _controller;

    TimeoutLock _lock;

    std::unique_ptr<Machine> _machine;
    std::vector<std::function<void(Machine&)>> _onConfigureMachine;
    std::atomic<bool> _machineRunning = false;
    std::thread _machineThread;

    struct MachineIO {
        std::unique_ptr<BufferedInputStreamCommunicator> in;
        std::unique_ptr<OutputStreamCommunicator> out;
        std::unique_ptr<OutputStreamCommunicator> err;
    } _machineIO;

    std::function<std::string()> _getMemoryStats;
    std::function<std::string()> _getStorageStats;

    std::filesystem::path _rootDir;

    void configureMachine() {
        _machine = nullptr;
        _machine = std::make_unique<Machine>();

        _machine->setCodeDir(_rootDir / "code");
        _machine->setWorkingDir(_rootDir / "data");

        _machine->setWatchdogHandler([this]() {
            std::string message = "machine watchdog triggered\n";
            this->_machineIO.err->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(message.data()), message.size()));
            return true;
        });
        _machine->setWatchdogTimeout(std::chrono::seconds(1));

        for (auto& f : _onConfigureMachine) {
            f(*_machine);
        }
        Logger::debug("machine configured");
    }

    void lockTimeout() {
        Logger::debug("lock timeout");

        _uploader->lockTimeout();
    }
public:

    Device(std::filesystem::path rootDir, std::function<std::string()> getMemoryStats, std::function<std::string()> getStorageStats):
        _lock(std::chrono::seconds(2), std::bind(&Device::lockTimeout, this)),
        _getMemoryStats(getMemoryStats),
        _getStorageStats(getStorageStats),
        _rootDir(rootDir.lexically_normal())
    {
        Logger::_errorStream = std::make_unique<TransparentOutputStreamCommunicator>(_router, 255, std::vector<int>{});
        Logger::_logStream = std::make_unique<TransparentOutputStreamCommunicator>(_router, 253, std::vector<int>{});
        Logger::_debugStream = std::make_unique<TransparentOutputStreamCommunicator>(_router, 251, std::vector<int>{});

        auto uploaderInput = std::make_unique<UnboundedBufferedInputPacketCommunicator>();
        auto uploaderOutput = std::make_unique<TransparentOutputPacketCommunicator>(_router, 1);
        _router.subscribeChannel(1, *uploaderInput);

        _uploader.emplace(std::move(uploaderInput), std::move(uploaderOutput), _lock, _rootDir);

        auto controllerInput = std::make_unique<UnboundedBufferedInputPacketCommunicator>();
        auto controllerOutput = std::make_unique<TransparentOutputPacketCommunicator>(_router, 0);
        _router.subscribeChannel(0, *controllerInput);

        _controller.emplace(std::move(controllerInput), std::move(controllerOutput), _lock, *this);

        auto _machineIn = std::make_unique<UnboundedBufferedInputStreamCommunicator>(std::set<int>{});
        _router.subscribeChannel(16, *_machineIn);
        _machineIO.in = std::move(_machineIn);
        _machineIO.out = std::make_unique<TransparentOutputStreamCommunicator>(_router, 16, std::vector<int>{});
        _machineIO.err = std::make_unique<TransparentOutputStreamCommunicator>(_router, 17, std::vector<int>{});
    }

    Device(const Device&) = delete;
    Device& operator=(const Device&) = delete;
    Device(Device&&) = delete;
    Device& operator=(Device&&) = delete;

    void start() {
        _uploader->start();
        _controller->start();
    }

    ~Device() {
        stopMachine();
    }

    Router& router() {
        return _router;
    }

    TimeoutLock& lock() {
        return _lock;
    }

    MachineIO& machineIO() {
        return _machineIO;
    }

    bool startMachine(std::string path) override;
    bool stopMachine() override;
    std::tuple<bool, int, std::string> getMachineStatus() override;

    void onConfigureMachine(std::function<void(Machine&)> f) {
        _onConfigureMachine.push_back(f);
    }
};

template<class Machine>
bool Device<Machine>::startMachine(std::string path) {
    if (_machineRunning) {
        return false;
    }
    if (_machineThread.joinable()) {
        _machineThread.join();
    }

    _machineThread = std::thread([this, path]() {
        Device<Machine>& self = *this;
        self._machineRunning = true;

        Logger::log("Starting machine");

        self.configureMachine();
        self._machine->initialize();
        try {
            self._machine->evalFile(path);
            self._machine->runEventLoop();
        }
        catch (jac::Exception& e) {
            std::string message = "Uncaught " + std::string(e.what()) + "\n";
            std::string stack = e.stackTrace();
            if (stack.size() > 0 && stack != "undefined") {
                message += stack + "\n";
            }
            this->_machineIO.err->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(message.data()), message.size()));
        }
        catch (const std::exception& e) {
            std::string message = "Internal error: " + std::string(e.what()) + "\n";
            this->_machineIO.err->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(message.data()), message.size()));
            Logger::log(message);
        }
        catch (...) {
            std::string message = "Unkown internal error\n";
            this->_machineIO.err->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(message.data()), message.size()));
            Logger::log(message);
        }

        {
            std::string message = "Machine exited with code " + std::to_string(self._machine->getExitCode()) + "\n";
            this->_machineIO.err->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(message.data()), message.size()));
        }

        self._machineRunning = false;
    });

    return true;
}

template<class Machine>
bool Device<Machine>::stopMachine() {
    if (!_machineRunning) {
        return false;
    }

    _machine->kill();

    if (_machineThread.joinable()) {
        _machineThread.join();
    }
    _machineThread = std::thread();

    return true;
}

template<class Machine>
std::tuple<bool, int, std::string> Device<Machine>::getMachineStatus() {
    bool running = _machineRunning;
    int code = _machine ? _machine->getExitCode() : 0;

    std::stringstream oss;
    oss << "Memory usage: " << _getMemoryStats() << std::endl;
    oss << "Storage usage: " << _getStorageStats() << std::endl;
    return {running, code, oss.str()};
}

} // namespace jac
