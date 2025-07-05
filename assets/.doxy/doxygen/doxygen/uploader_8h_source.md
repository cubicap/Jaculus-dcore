

# File uploader.h

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**uploader.h**](uploader_8h.md)

[Go to the documentation of this file](uploader_8h.md)


```C++
#pragma once

#include <jac/link/router.h>
#include <jac/link/routerCommunicator.h>

#include <atomic>
#include <deque>
#include <filesystem>
#include <fstream>
#include <memory.h>

#include "util/lock.h"


namespace jac {


class Uploader {
public:
    enum class Command : uint8_t {
        READ_FILE = 0x01,
        WRITE_FILE = 0x02,
        DELETE_FILE = 0x03,
        LIST_DIR = 0x04,
        CREATE_DIR = 0x05,
        DELETE_DIR = 0x06,
        FORMAT_STORAGE = 0x07,
        LIST_RESOURCES = 0x08,
        READ_RESOURCE = 0x09,
        HAS_MORE_DATA = 0x10,
        LAST_DATA = 0x11,
        OK = 0x20,
        ERROR = 0x21,
        NOT_FOUND = 0x22,
        CONTINUE = 0x23,
        LOCK_NOT_OWNED = 0x24,
        GET_DIR_HASHES = 0x25,
    };

    enum class Error : uint8_t {
        UNKNOWN_COMMAND = 0x01,
        FILE_OPEN_FAILED = 0x02,
        FILE_DELETE_FAILED = 0x03,
        DIR_OPEN_FAILED = 0x04,
        DIR_CREATE_FAILED = 0x05,
        DIR_DELETE_FAILED = 0x06,
        INVALID_FILENAME = 0x07,
    };
private:
    enum class State {
        NONE,
        WAITING_FOR_DATA
    };

    State _state = State::NONE;
    std::fstream _file;
    std::function<bool(std::span<const uint8_t>)> _onData;
    std::function<bool()> _onDataComplete;

    std::unique_ptr<InputPacketCommunicator> _input;
    std::unique_ptr<OutputPacketCommunicator> _output;

    bool processPacket(int sender, std::span<const uint8_t> data);
    bool processReadFile(int sender, std::span<const uint8_t> data);
    bool processWriteFile(int sender, std::span<const uint8_t> data);
    bool processDeleteFile(int sender, std::span<const uint8_t> data);
    bool processListDir(int sender, std::span<const uint8_t> data);
    bool processCreateDir(int sender, std::span<const uint8_t> data);
    bool processDeleteDir(int sender, std::span<const uint8_t> data);
    bool processFormatStorage(int sender, std::span<const uint8_t> data);
    bool processGetHashes(int sender, std::span<const uint8_t> data);
    bool processListResources(int sender, std::span<const uint8_t> data);
    bool processReadResource(int sender, std::span<const uint8_t> data);

    std::thread _thread;
    std::atomic<bool> _stop = false;

    TimeoutLock& _devLock;

    std::filesystem::path _rootDir;
    std::function<void(std::filesystem::path)> _formatFS;

    std::unordered_map<std::string, std::span<const uint8_t>> _resources;
public:
    Uploader(
        std::unique_ptr<InputPacketCommunicator> input,
        std::unique_ptr<OutputPacketCommunicator> output,
        TimeoutLock& lock,
        std::filesystem::path rootDir,
        std::function<void(std::filesystem::path)> formatFS,
        std::unordered_map<std::string, std::span<const uint8_t>> resources
    ):
        _input(std::move(input)),
        _output(std::move(output)),
        _devLock(lock),
        _rootDir(std::move(rootDir)),
        _formatFS(std::move(formatFS)),
        _resources(std::move(resources))
    {}

    Uploader(const Uploader&) = delete;
    Uploader(Uploader&&) = delete;
    Uploader& operator=(const Uploader&) = delete;
    Uploader& operator=(Uploader&&) = delete;

    void lockTimeout();

    void start() {
        _thread = std::thread([this]() {
            while (!_stop) {
                auto res = _input->get();
                if (!res) {
                    continue;
                }
                auto [sender, data] = *res;

                _devLock.stopTimeout(sender);  // does nothing if not locked by sender
                processPacket(sender, std::span<const uint8_t>(data.begin(), data.end()));
                _devLock.resetTimeout(sender);  // does nothing if not locked by sender
            }
        });
    }

    ~Uploader() {
        _stop = true;
        _input->cancelRead();
        if (_thread.joinable()) {
            _thread.join();
        }
    }
};


} // namespace jac
```


