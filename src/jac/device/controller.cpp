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


} // namespace jac
