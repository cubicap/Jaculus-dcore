#include <jac/machine/machine.h>
#include <jac/machine/values.h>
#include <jac/features/eventLoopFeature.h>
#include <jac/features/eventQueueFeature.h>
#include <jac/features/timersFeature.h>
#include <jac/features/moduleLoaderFeature.h>
#include <jac/features/filesystemFeature.h>
#include <jac/features/basicStreamFeature.h>
#include <jac/features/stdioFeature.h>

#include <jac/device/device.h>
#include <jac/device/logger.h>

#include <jac/link/mux.h>
#include <jac/link/encoders/cobs.h>

#include <any>
#include <string>
#include <filesystem>

#include <jac/features/util/linkIo.h>

#include "util.h"


using Mux_t = jac::Mux<jac::CobsEncoder>;


void reportMuxError(jac::MuxError error, std::any ctx) {
    std::string message = "Mux error: ";
    switch (error) {
        case jac::MuxError::INVALID_RECEIVE:
            {
                auto& ref = std::any_cast<std::tuple<int, uint8_t>&>(ctx);
                message += "INVALID_RECEIVE " + std::to_string(std::get<0>(ref));
                message += " [" + std::to_string(std::get<1>(ref)) + "]";
                jac::Logger::debug(message);
            }
            break;
        case jac::MuxError::PACKETIZER:
            {
                auto& ref = std::any_cast<int&>(ctx);
                message += "PACKETIZER_ERROR " + std::to_string(ref);
                jac::Logger::debug(message);
            }
            break;
        case jac::MuxError::PROCESSING:
            {
                auto& ref = std::any_cast<std::string&>(ctx);
                message += "PROCESSING_ERROR '" + ref + "'";
                jac::Logger::error(message);
            }
            break;
    }
}


int main() {
    using Machine = jac::ComposeMachine<
        jac::MachineBase,
        jac::EventQueueFeature,
        jac::BasicStreamFeature,
        jac::StdioFeature,
        jac::FilesystemFeature,
        jac::ModuleLoaderFeature,
        jac::EventLoopFeature,
        jac::TimersFeature,
        jac::EventLoopTerminal
    >;

    // create Device
    jac::Device<Machine> device(
        "./test_files",
        []() { // get memory stats
            return "not implemented";
        },
        []() { // get storage stats
            return "not implemented";
        },
        {{ "test", "0.0.1" }} // version info
    );

    // configure communication interface
    auto mockStream = std::make_unique<DummyDuplex>();
    std::unique_ptr<jac::Duplex> stream = std::move(mockStream);

    Mux_t muxMock(std::move(stream));

    muxMock.setErrorHandler(reportMuxError);

    // connect communication interface to the Device
    auto handle = device.router().subscribeTx(1, muxMock);
    muxMock.bindRx(std::make_unique<decltype(handle)>(std::move(handle)));

    // set machine configuration procedure
    device.onConfigureMachine([&](Machine &machine) {
        device.machineIO().in->clear();

        machine.stdio.out = std::make_unique<jac::LinkWritable>(device.machineIO().out.get());
        machine.stdio.err = std::make_unique<jac::LinkWritable>(device.machineIO().err.get());
        machine.stdio.in = std::make_unique<jac::LinkReadable<Machine>>(&machine, device.machineIO().in.get());
    });

    // start Device services
    device.start();

    // run javascript code from default entry point
    device.startMachine("index.js");

    std::jthread t([&]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });
}
