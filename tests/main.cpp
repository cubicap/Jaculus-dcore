#include <jac/machine/machine.h>
#include <jac/features/eventLoopFeature.h>
#include <jac/features/eventQueueFeature.h>
#include <jac/features/timersFeature.h>
#include <jac/features/yieldFeature.h>
#include <jac/features/moduleLoaderFeature.h>
#include <jac/features/filesystemFeature.h>
#include <jac/features/basicStreamFeature.h>
#include <jac/features/stdioFeature.h>
#include <jac/machine/values.h>


#include <jac/link/mux.h>
#include <jac/link/encoders/cobs.h>

#include <string>
#include <filesystem>

#include <jac/device/controller.h>
#include <jac/device/uploader.h>
#include <jac/device/logger.h>

#include <jac/features/linkIoFeature.h>

#include "util.h"

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

jac::Controller<Machine> controller([]() { // get memory stats
    return "not implemented";
}, []() { // get storage stats
    return "not implemented";
});

using Mux_t = jac::Mux<jac::CobsPacketizer, jac::CobsSerializer>;
std::unique_ptr<Mux_t> muxMock;


int main() {
    auto mockStream = std::make_unique<MockDuplex>();
    std::unique_ptr<jac::Duplex> stream = std::move(mockStream);

    muxMock = std::make_unique<Mux_t>(std::move(stream));
    muxMock->setErrorHandler([](Mux_t::Error error, std::vector<int> ctx) {
        std::string message = "Mux error: " + std::to_string(static_cast<int>(error)) + ", ctx: [";
        for (auto c : ctx) {
            message += std::to_string(c) + ", ";
        }
        message += "]";
        jac::Logger::log(message);
    });
    auto handle = controller.router().subscribeTx(1, *muxMock);
    muxMock->bindRx(std::make_unique<decltype(handle)>(std::move(handle)));


    controller.onConfigureMachine([&](Machine &machine) {
        controller.machineIO().in->clear();

        machine.stdio.out = std::make_unique<Machine::LinkWritable>(controller.machineIO().out.get());
        machine.stdio.err = std::make_unique<Machine::LinkWritable>(controller.machineIO().err.get());
        machine.stdio.in = std::make_unique<Machine::LinkReadable>(&machine, controller.machineIO().in.get());
    });

    if (std::filesystem::exists("/data/index.js")) {
        controller.startMachine("/data/index.js");
    }
}
