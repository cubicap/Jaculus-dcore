#include <jac/machine/machine.h>
#include <jac/machine/values.h>
#include <jac/features/eventLoopFeature.h>
#include <jac/features/eventQueueFeature.h>
#include <jac/features/timersFeature.h>
#include <jac/features/yieldFeature.h>
#include <jac/features/moduleLoaderFeature.h>
#include <jac/features/filesystemFeature.h>
#include <jac/features/basicStreamFeature.h>
#include <jac/features/stdioFeature.h>

#include <jac/device/device.h>
#include <jac/device/logger.h>

#include <jac/link/mux.h>
#include <jac/link/encoders/cobs.h>

#include <string>
#include <filesystem>

#include <jac/features/linkIoFeature.h>

#include "util.h"


int main() {
    using Machine =
        EventLoopTerminal<
        TimersFeature<
        YieldFeature<
        EventLoopFeature<
        ModuleLoaderFeature<
        FilesystemFeature<
        LinkIoFeature<
        StdioFeature<
        BasicStreamFeature<
        EventQueueFeature<
        jac::MachineBase
    >>>>>>>>>>;

    using Mux_t = jac::Mux<jac::CobsPacketizer, jac::CobsSerializer>;

    // create Device
    jac::Device<Machine> device(
        "./test_files",
        []() { // get memory stats
            return "not implemented";
        },
        []() { // get storage stats
            return "not implemented";
        }
    );

    // configure communication interface
    auto mockStream = std::make_unique<MockDuplex>();
    std::unique_ptr<jac::Duplex> stream = std::move(mockStream);

    Mux_t muxMock(std::move(stream));

    muxMock.setErrorHandler([](Mux_t::Error error, std::vector<int> ctx) {
        std::string message = "Mux error: " + std::to_string(static_cast<int>(error)) + ", ctx: [";
        for (auto c : ctx) {
            message += std::to_string(c) + ", ";
        }
        message += "]";
        jac::Logger::log(message);
    });

    // connect communication interface to the Device
    auto handle = device.router().subscribeTx(1, muxMock);
    muxMock.bindRx(std::make_unique<decltype(handle)>(std::move(handle)));

    // set machine configuration procedure
    device.onConfigureMachine([&](Machine &machine) {
        device.machineIO().in->clear();

        machine.stdio.out = std::make_unique<Machine::LinkWritable>(device.machineIO().out.get());
        machine.stdio.err = std::make_unique<Machine::LinkWritable>(device.machineIO().err.get());
        machine.stdio.in = std::make_unique<Machine::LinkReadable>(&machine, device.machineIO().in.get());
    });

    // start Device services
    device.start();

    // run javascript code from default entry point
    jac::Logger::debug("starting machine");
    device.startMachine("index.js");

    std::jthread t([&]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            muxMock.receive();
        }
    });
}
