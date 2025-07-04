#pragma once

#include <memory>
#include <functional>
#include <stdint.h>
#include <string>

namespace jac {

class KeyValueNamespace {
    KeyValueNamespace(KeyValueNamespace&) = delete;

public:
    enum DataType : uint8_t {
        INT64 = 0,
        FLOAT32 = 1,
        STRING = 2,

        NOT_FOUND = 0xFF,
    };

    KeyValueNamespace() {}

    virtual ~KeyValueNamespace() { }

    virtual bool erase(const std::string& name) = 0;
    virtual std::vector<std::string> keys() = 0;

    virtual void setInt(const std::string& name, int64_t value) = 0;
    virtual void setFloat(const std::string& name, float value) = 0;
    virtual void setString(const std::string& name, const std::string& value) = 0;

    virtual int64_t getInt(const std::string& name, int64_t def_value = 0) = 0;
    virtual float getFloat(const std::string& name, float def_value = 0.f) = 0;
    virtual std::string getString(const std::string& name, std::string def_value = "") = 0;

    virtual DataType getType(const std::string& name) = 0;
    bool exists(const std::string& name) {
        return getType(name) != NOT_FOUND;
    }

    virtual bool commit() = 0;
};

using KeyValueOpener = std::function<std::unique_ptr<KeyValueNamespace>(const std::string&)>;

} // namespace jac
