#include <jac/link/stream.h>
#include <iostream>


class DummyDuplex : public jac::Duplex {
public:

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

};
