#include <jac/link/stream.h>


class MockDuplex : public jac::Duplex {
public:

    int get() override {
        return -1;
    }

    size_t read(std::span<uint8_t> data) override {
        return 0;
    }

    bool put(uint8_t c) override {
        return true;
    }

    size_t write(std::span<const uint8_t> data) override {
        return data.size();
    }

    bool flush() override {
        return true;
    }

};
