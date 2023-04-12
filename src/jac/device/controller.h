#pragma once

#include <jac/link/mux.h>
#include <jac/link/router.h>
#include <jac/link/routerCommunicator.h>
#include "util/lock.h"

#include "logger.h"
#include "util/machineCtrl.h"

#include <atomic>
#include <filesystem>
#include <optional>
#include <sstream>
#include <thread>


namespace jac {


class Controller {
    enum class Command : uint8_t {
        START = 0x01,
        STOP = 0x02,
        STATUS = 0x03,
        LOCK = 0x10,
        UNLOCK = 0x11,
        FORCE_UNLOCK = 0x12,
        OK = 0x20,
        ERROR = 0x21,
        LOCK_NOT_OWNED = 0x22,
    };

    std::unique_ptr<BufferedInputPacketCommunicator> _input;
    std::unique_ptr<OutputPacketCommunicator> _output;
    std::thread _controllerThread;
    std::atomic<bool> _controllerStop = false;

    void processPacket(int sender, std::span<const uint8_t> data);
    void processStart(int sender, std::span<const uint8_t> data);
    void processStop(int sender);
    void processStatus(int sender);
    void processLock(int sender);
    void processUnlock(int sender);
    void processForceUnlock(int sender);

    TimeoutLock& _devLock;
    MachineCtrl& _machineCtrl;

public:
    Controller(std::unique_ptr<BufferedInputPacketCommunicator> input, std::unique_ptr<OutputPacketCommunicator> output,
               TimeoutLock& lock, MachineCtrl& machineCtrl):
        _input(std::move(input)),
        _output(std::move(output)),
        _devLock(lock),
        _machineCtrl(machineCtrl)
    {}

    ~Controller() {
        _controllerStop = true;
        _input->cancelRead();
        if (_controllerThread.joinable()) {
            _controllerThread.join();
        }
    }

    void start() {
        _controllerThread = std::thread([this]() {
            while (!_controllerStop) {
                auto res = _input->get();
                if (!res) {
                    continue;
                }
                auto [sender, data] = *res;

                _devLock.stopTimeout(sender);  // does nothing if not locked by sender
                processPacket(sender, std::span(data.begin(), data.end()));
                _devLock.resetTimeout(sender);  // does nothing if not locked by sender
            }
        });
    }
};


} // namespace jac
