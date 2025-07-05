

# File controller.h

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**controller.h**](controller_8h.md)

[Go to the documentation of this file](controller_8h.md)


```C++
#pragma once

#include <jac/link/mux.h>
#include <jac/link/router.h>
#include <jac/link/routerCommunicator.h>
#include "util/lock.h"

#include "logger.h"
#include "keyvalue.h"
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
        VERSION = 0x04,
        LOCK = 0x10,
        UNLOCK = 0x11,
        FORCE_UNLOCK = 0x12,
        OK = 0x20,
        ERROR = 0x21,
        LOCK_NOT_OWNED = 0x22,
        CONFIG_SET = 0x30,
        CONFIG_GET = 0x31,
        CONFIG_ERASE = 0x32,
    };

    std::unique_ptr<InputPacketCommunicator> _input;
    std::unique_ptr<OutputPacketCommunicator> _output;
    std::thread _thread;
    std::atomic<bool> _stop = false;

    void processPacket(int sender, std::span<const uint8_t> data);
    void processStart(int sender, std::span<const uint8_t> data);
    void processStop(int sender);
    void processStatus(int sender);
    void processVersion(int sender);
    void processLock(int sender);
    void processUnlock(int sender);
    void processForceUnlock(int sender);
    void processConfigSet(int sender, std::span<const uint8_t> data);
    void processConfigGet(int sender, std::span<const uint8_t> data);
    void processConfigErase(int sender, std::span<const uint8_t> data);

    TimeoutLock& _devLock;
    MachineCtrl& _machineCtrl;
    std::vector<std::pair<std::string, std::string>>& _versionInfo;

public:
    Controller(std::unique_ptr<InputPacketCommunicator> input, std::unique_ptr<OutputPacketCommunicator> output,
               TimeoutLock& lock, MachineCtrl& machineCtrl, std::vector<std::pair<std::string, std::string>>& versionInfo) :
        _input(std::move(input)),
        _output(std::move(output)),
        _devLock(lock),
        _machineCtrl(machineCtrl),
        _versionInfo(versionInfo)
    {}

    ~Controller() {
        _stop = true;
        _input->cancelRead();
        if (_thread.joinable()) {
            _thread.join();
        }
    }

    void start() {
        _thread = std::thread([this]() {
            while (!_stop) {
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
```


