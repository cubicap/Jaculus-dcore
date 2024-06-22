

# File linkIo.h

[**File List**](files.md) **>** [**features**](dir_6f95e06b732314161804ab1ef73c9681.md) **>** [**util**](dir_8745a1fa89e3088deda48338e7669502.md) **>** [**linkIo.h**](linkIo_8h.md)

[Go to the documentation of this file](linkIo_8h.md)


```C++
#pragma once

#include <jac/machine/machine.h>
#include <jac/features/types/streams.h>

#include <atomic>
#include <vector>
#include <thread>


namespace jac {


class LinkWritable : public Writable {
    jac::OutputStreamCommunicator* _comm;
public:
    LinkWritable(jac::OutputStreamCommunicator* comm): _comm(std::move(comm)) {}

    void write(std::string data) override {
        _comm->write(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(data.data()), data.size()));
    }
};

template<class Machine>
class LinkReadable : public Readable {
    Machine* _machine;
    jac::InputStreamCommunicator* _comm;
    std::thread _thread;
    std::atomic<bool> _running = false;

    bool startRead(auto callback) {
        if (_running) {
            return false;
        }
        if (_thread.joinable()) {
            _thread.join();
        }
        _running = true;

        _thread = std::thread(std::move(callback));

        return true;
    }
public:
    LinkReadable(Machine* machine, jac::InputStreamCommunicator* comm): _machine(machine), _comm(std::move(comm)) {}
    LinkReadable(LinkReadable&) = delete;
    LinkReadable(LinkReadable&&) = delete;

    bool get(std::function<void(char)> callback) override {
        return startRead([this, callback = std::move(callback)]() mutable {
            int res = _comm->get();

            if (res != 0) {
                _machine->scheduleEvent([callback = std::move(callback), res]() mutable {
                    callback(static_cast<char>(res));
                });
            }

            _running = false;
        });
    }

    bool read(std::function<void(std::string)> callback) override {
        return startRead([this, callback = std::move(callback)]() mutable {
            std::string buffer;
            buffer.resize(256);

            auto count = _comm->read(std::span<uint8_t>(reinterpret_cast<uint8_t*>(buffer.data()), buffer.size()));

            buffer.resize(count);
            _machine->scheduleEvent([callback = std::move(callback), buffer = std::move(buffer)]() mutable {
                callback(std::move(buffer));
            });

            _running = false;
        });
    }

    ~LinkReadable() override {
        if (_running) {
            _comm->cancelRead();
        }
        if (_thread.joinable()) {
            _thread.join();
        }
    }
};


} // namespace jac
```


