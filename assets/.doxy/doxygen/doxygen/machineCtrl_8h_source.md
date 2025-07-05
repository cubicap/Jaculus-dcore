

# File machineCtrl.h

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**util**](dir_5f36e4b8294e45bcbbea85a29a4cc9c0.md) **>** [**machineCtrl.h**](machineCtrl_8h.md)

[Go to the documentation of this file](machineCtrl_8h.md)


```C++
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
```


