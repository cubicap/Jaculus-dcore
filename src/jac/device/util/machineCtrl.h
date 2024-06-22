#pragma once

#include <string>
#include <tuple>
#include "../keyvalue.h"

namespace jac {


class MachineCtrl {
public:
    virtual bool startMachine(std::string path) = 0;
    virtual bool stopMachine() = 0;
    virtual std::tuple<bool, int, std::string> getMachineStatus() = 0;

    virtual std::unique_ptr<KeyValueNamespace> openKeyValue(const std::string& nsname) const = 0;
    virtual void emitKeyValueModified(const std::string& nsname, const std::string& key) = 0;
};


} // namespace jac
