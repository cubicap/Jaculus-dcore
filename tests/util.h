#include <jac/link/stream.h>
#include <functional>
#include <iostream>
#include <thread>


class DummyDuplex : public jac::Duplex {
    std::function<void(void)> _onData;
    std::jthread _thread;
public:
    void start() {
        _thread = std::jthread([&]() {
            while (true) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                if (_onData) {
                    _onData();
                }
            }
        });
    }

    int get() override {
        return -1;
    }

    size_t read(std::span<uint8_t> data) override {
        return 0;
    }

    bool put(uint8_t c) override {
        std::cout << c;
        return true;
    }

    size_t write(std::span<const uint8_t> data) override {
        std::cout.write(reinterpret_cast<const char*>(data.data()), data.size());
        std::cout.flush();
        return data.size();
    }

    bool flush() override {
        return true;
    }

    void onData(std::function<void(void)> onData) override {
        _onData = std::move(onData);
    }
};
