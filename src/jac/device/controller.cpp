#include "controller.h"


namespace jac {


void Controller::processPacket(int sender, std::span<const uint8_t> data) {
    if (data.size() == 0) {
        return;
    }
    auto begin = data.begin();
    Command cmd = static_cast<Command>(data[0]);
    begin++;

    switch (cmd) {
        case Command::LOCK:
            processLock(sender);
            return;
        case Command::UNLOCK:
            processUnlock(sender);
            return;
        case Command::FORCE_UNLOCK:
            processForceUnlock(sender);
            return;
        case Command::STATUS:
            processStatus(sender);
            return;
        case Command::VERSION:
            processVersion(sender);
            return;
        default:
            break;
    }

    if (!_devLock.ownedBy(sender)) {
        Logger::debug("Controller: lock not owned by sender " + std::to_string(sender));
        auto response = this->_output->buildPacket({sender});
        response->put(static_cast<uint8_t>(Command::LOCK_NOT_OWNED));
        response->send();
        return;
    }

    switch (cmd) {
        case Command::START:
            processStart(sender, std::span<const uint8_t>(begin, data.end()));
            break;
        case Command::STOP:
            processStop(sender);
            break;
        case Command::CONFIG_SET:
            processConfigSet(sender, std::span<const uint8_t>(begin, data.end()));
            break;
        case Command::CONFIG_GET:
            processConfigGet(sender, std::span<const uint8_t>(begin, data.end()));
            break;
        case Command::CONFIG_ERASE:
            processConfigErase(sender, std::span<const uint8_t>(begin, data.end()));
        default:
            break;
    }
}

void Controller::processStart(int sender, std::span<const uint8_t> data) {
    std::string filename(data.begin(), data.end());

    auto result = Command::OK;

    if (!_machineCtrl.startMachine(filename)) {
        result = Command::ERROR;
    }

    auto response = this->_output->buildPacket({sender});
    response->put(static_cast<uint8_t>(result));
    response->send();
}

void Controller::processStop(int sender) {
    auto result = Command::OK;

    if (!_machineCtrl.stopMachine()) {
        result = Command::ERROR;
    }

    auto response = this->_output->buildPacket({sender});
    response->put(static_cast<uint8_t>(result));
    response->send();
}

void Controller::processStatus(int sender) {
    auto response = this->_output->buildPacket({sender});
    response->put(static_cast<uint8_t>(Command::STATUS));

    auto [running, code, status] = _machineCtrl.getMachineStatus();

    response->put(static_cast<uint8_t>(running));
    response->put(static_cast<uint8_t>(code));

    response->put(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(status.data()), status.size()));
    response->send();
}

void Controller::processVersion(int sender) {
    auto response = this->_output->buildPacket({sender});
    response->put(static_cast<uint8_t>(Command::VERSION));

    std::string version;
    for (auto& [name, ver] : _versionInfo) {
        version += name + "@" + ver + "\n";
    }

    response->put(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(version.data()), version.size()));
    response->send();
}

void Controller::processLock(int sender) {
    auto response = this->_output->buildPacket({sender});

    if (_devLock.ownedBy(sender)) {
        response->put(static_cast<uint8_t>(Command::ERROR));
    }
    else if (_devLock.lock(sender)) {
        response->put(static_cast<uint8_t>(Command::OK));
    }
    else {
        response->put(static_cast<uint8_t>(Command::ERROR));
    }

    response->send();
}

void Controller::processUnlock(int sender) {
    auto response = this->_output->buildPacket({sender});

    if (_devLock.unlock(sender)) {
        response->put(static_cast<uint8_t>(Command::OK));
    }
    else {
        response->put(static_cast<uint8_t>(Command::ERROR));
    }

    response->send();
}

void Controller::processForceUnlock(int sender) {
    auto response = this->_output->buildPacket({sender});

    _devLock.forceUnlock();

    response->put(static_cast<uint8_t>(Command::OK));
}

void Controller::processConfigSet(int sender, std::span<const uint8_t> data) {
    using DataType = jac::KeyValueNamespace::DataType;

    auto response = this->_output->buildPacket({sender});

    // 0: namespace
    auto stringEnd = std::find(data.begin(), data.end(), '\0');
    std::string nsname(data.begin(), stringEnd);
    auto dataIt = stringEnd+1;
    if(dataIt == data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    auto kv = _machineCtrl.openKeyValue(nsname);
    if(!kv) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    // 1: name
    stringEnd = std::find(dataIt, data.end(), '\0');
    std::string name(dataIt, stringEnd);
    dataIt = stringEnd+1;
    if(dataIt == data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    // 2: data type
    DataType dtype = static_cast<DataType>(*dataIt);
    ++dataIt;

    // 3: value
    switch(dtype) {
        case DataType::INT64: {
            if(data.end() - dataIt < 8) {
                response->put(static_cast<uint8_t>(Command::ERROR));
                response->send();
                return;
            }
            const auto intView = std::span<const uint8_t>(dataIt, dataIt+8);
            kv->setInt(name, *static_cast<const int64_t*>(static_cast<const void*>(intView.data())));
            break;
        }
        case DataType::FLOAT32: {
            if(data.end() - dataIt < 4) {
                response->put(static_cast<uint8_t>(Command::ERROR));
                response->send();
                return;
            }
            const auto floatView = std::span<const uint8_t>(dataIt, dataIt+4);
            kv->setFloat(name, *static_cast<const int64_t*>(static_cast<const void*>(floatView.data())));
            break;
        }
        case DataType::STRING: {
            if(data.end() - dataIt < 1) {
                response->put(static_cast<uint8_t>(Command::ERROR));
                response->send();
                return;
            }
            stringEnd = std::find(dataIt, data.end(), '\0');
            std::string value(dataIt, stringEnd);
            kv->setString(name, value);
            break;
        }
        default:
            Logger::error("Unknown config data type: " + std::to_string(dtype));
            response->put(static_cast<uint8_t>(Command::ERROR));
            response->send();
            return;
    }

    if(kv->commit()) {
        response->put(static_cast<uint8_t>(Command::OK));
        _machineCtrl.emitKeyValueModified(nsname, name);
    } else {
        response->put(static_cast<uint8_t>(Command::ERROR));
    }

    response->send();
}

void Controller::processConfigGet(int sender, std::span<const uint8_t> data) {
    using DataType = jac::KeyValueNamespace::DataType;

    auto response = this->_output->buildPacket({sender});

    // 0: namespace
    auto stringEnd = std::find(data.begin(), data.end(), '\0');
    std::string nsname(data.begin(), stringEnd);
    auto dataIt = stringEnd+1;
    if(dataIt == data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    auto kv = _machineCtrl.openKeyValue(nsname);
    if(!kv) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    // 1: name
    stringEnd = std::find(dataIt, data.end(), '\0');
    std::string name(dataIt, stringEnd);
    dataIt = stringEnd+1;
    if(dataIt == data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    // 2: data type
    DataType dtype = static_cast<DataType>(*dataIt);
    ++dataIt;

    response->put(static_cast<uint8_t>(Command::CONFIG_GET));
    response->put(dtype);

    switch(dtype) {
        case DataType::INT64: {
            int64_t value = kv->getInt(name);
            uint8_t *value_ptr = static_cast<uint8_t*>(static_cast<void*>(&value));
            std::span<const uint8_t> view(value_ptr, value_ptr+8);
            response->put(view);
            break;
        }
        case DataType::FLOAT32: {
            float value = kv->getFloat(name);
            uint8_t *value_ptr = static_cast<uint8_t*>(static_cast<void*>(&value));
            std::span<const uint8_t> view(value_ptr, value_ptr+4);
            response->put(view);
            break;
        }
        case DataType::STRING: {
            auto value = kv->getString(name);
            response->put(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(value.data()), value.size() + 1));
            break;
        }
        default:
            Logger::error("Unknown config data type: " + std::to_string(dtype));
            response->put(static_cast<uint8_t>(Command::ERROR));
            response->send();
            return;
    }

    response->send();
}

void Controller::processConfigErase(int sender, std::span<const uint8_t> data) {
    auto response = this->_output->buildPacket({sender});

    // 0: namespace
    auto stringEnd = std::find(data.begin(), data.end(), '\0');
    std::string nsname(data.begin(), stringEnd);
    auto dataIt = stringEnd+1;
    if(dataIt == data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    auto kv = _machineCtrl.openKeyValue(nsname);
    if(!kv) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    // 1: name
    stringEnd = std::find(dataIt, data.end(), '\0');
    std::string name(dataIt, stringEnd);
    dataIt = stringEnd+1;
    if(dataIt != data.end()) {
        response->put(static_cast<uint8_t>(Command::ERROR));
        response->send();
        return;
    }

    kv->erase(name);

    if(kv->commit()) {
        response->put(static_cast<uint8_t>(Command::OK));
        _machineCtrl.emitKeyValueModified(nsname, name);
    } else {
        response->put(static_cast<uint8_t>(Command::ERROR));
    }

    response->send();
}


} // namespace jac
