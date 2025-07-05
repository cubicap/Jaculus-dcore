

# File keyvalueFeature.h

[**File List**](files.md) **>** [**features**](dir_6f95e06b732314161804ab1ef73c9681.md) **>** [**keyvalueFeature.h**](keyvalueFeature_8h.md)

[Go to the documentation of this file](keyvalueFeature_8h.md)


```C++
#pragma once

#include <jac/machine/machine.h>
#include <jac/machine/functionFactory.h>
#include <jac/machine/class.h>
#include <jac/device/keyvalue.h>

#include <noal_func.h>
#include <memory>


namespace jac {


struct KeyValueNamespaceProtoBuilder : public jac::ProtoBuilder::Opaque<jac::KeyValueNamespace>, public jac::ProtoBuilder::Properties {
    static jac::Value get(jac::ContextRef ctx, jac::ValueWeak thisVal, std::string key) {
        using namespace jac;
        using DT = KeyValueNamespace::DataType;

        auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx, thisVal);
        switch(self.getType(key)) {
            case DT::INT64:
                return Value::from(ctx, self.getInt(key));
            case DT::FLOAT32:
                return Value::from(ctx, self.getFloat(key));
            case DT::STRING:
                return Value::from(ctx, self.getString(key));
            default:
                return Value::null(ctx);
        }
    }

    static void addProperties(JSContext* ctx, jac::Object proto) {
        jac::FunctionFactory ff(ctx);

        proto.defineProperty("get", ff.newFunctionThis(std::function(&get)), jac::PropFlags::Enumerable);

        proto.defineProperty("getString", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal, std::string key) {
            auto res = get(ctx_, thisVal, key);
            if(JS_IsString(res.getVal())) {
                return res;
            }
            return jac::Value::null(ctx_);
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("getNumber", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal, std::string key) {
            auto res = get(ctx_, thisVal, key);
            if(JS_IsNumber(res.getVal())) {
                return res;
            }
            return jac::Value::null(ctx_);
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("set", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal, std::string key, jac::Value value) {
            using namespace jac;

            if(key.length() > 15) {
                throw Exception::create(Exception::Type::TypeError, "key is too long (max 15 chars)");
            }

            auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx_, thisVal);
            auto tag = JS_VALUE_GET_TAG(value.getVal());
            if(tag == JS_TAG_INT) {
                self.setInt(key, value.to<int64_t>());
            } else if(JS_TAG_IS_FLOAT64(tag)) {
                self.setFloat(key, value.to<double>());
            } else if(tag == JS_TAG_STRING) {
                self.setString(key, value.to<std::string>());
            } else {
                throw Exception::create(Exception::Type::TypeError, "value has wrong type");
            }
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("erase", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal, std::string key) {
            auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx_, thisVal);
            self.erase(key);
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("exists", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal, std::string key) {
            auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx_, thisVal);
            return self.exists(key);
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("commit", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal) {
            using namespace jac;
            auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx_, thisVal);
            if(!self.commit()) {
                throw Exception::create(Exception::Type::InternalError, "NVS saving failed");
            }
        }), jac::PropFlags::Enumerable);

        proto.defineProperty("keys", ff.newFunctionThis([](jac::ContextRef ctx_, jac::ValueWeak thisVal) {
            auto& self = *KeyValueNamespaceProtoBuilder::getOpaque(ctx_, thisVal);
            auto keys = self.keys();
            auto arr = jac::Array::create(ctx_);

            auto atom = jac::Atom::create(ctx_, "push");
            for(const auto& key : keys) {
                arr.invoke<void>(atom, key);
            }
            return arr;
        }), jac::PropFlags::Enumerable);
    }
};


template<class Next>
class KeyValueFeature : public Next {
public:
    using KvClass = jac::Class<KeyValueNamespaceProtoBuilder>;

    jac::KeyValueOpener kvOpener;

    KeyValueFeature() {
        KvClass::init("KeyValueNamespace");
    }

    void initialize() {
        using namespace jac;

        Next::initialize();

        FunctionFactory ff(this->context());
        Module& mod = this->newModule("keyvalue");

        mod.addExport("open", ff.newFunction(noal::function([this](std::string nsname) {
            if(!kvOpener) {
                throw Exception::create(Exception::Type::InternalError, "KeyValueFeature not set up");
            }

            if(nsname.length() > 15) {
                throw Exception::create(Exception::Type::TypeError, "namespace is too long (max 15 chars)");
            }

            if(nsname == "wifi_net") {
                throw Exception::create(Exception::Type::InternalError, "this namespace is protected");
            }

            auto nsHandle = kvOpener(nsname);
            if(!nsHandle) {
                throw Exception::create(Exception::Type::InternalError, "failed to open namespace");
            }
            return KvClass::createInstance(this->context(), nsHandle.release());
        })));
    }
};


} // namespace jac
```


