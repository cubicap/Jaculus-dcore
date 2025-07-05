

# File lock.h

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**util**](dir_5f36e4b8294e45bcbbea85a29a4cc9c0.md) **>** [**lock.h**](lock_8h.md)

[Go to the documentation of this file](lock_8h.md)


```C++
#pragma once

#include <atomic>
#include <optional>
#include "timeout.h"


namespace jac {


class TimeoutLock {
    Timeout _timeout;
    bool _locked = false;
    int _owner = 0;
    std::mutex _mutex;
    int _stops = 0;
    std::function<void()> _callback;
public:
    TimeoutLock(std::chrono::milliseconds duration, std::function<void()> callback):
        _timeout(duration),
        _callback(callback)
    {}

    TimeoutLock(const TimeoutLock&) = delete;
    TimeoutLock(TimeoutLock&&) = delete;
    TimeoutLock& operator=(const TimeoutLock&) = delete;
    TimeoutLock& operator=(TimeoutLock&&) = delete;

    void init() {
        _timeout.init();
    }

    bool lock(int who) {
        std::scoped_lock<std::mutex> _(_mutex);

        if (_locked && _owner == who) {
            throw std::runtime_error("Lock already locked, reset() should be used to reset the timeout");
        }

        if (!_locked) {
            _locked = true;
            _owner = who;
            _timeout.start([this]() {
                std::scoped_lock<std::mutex> __(_mutex);
                if (_callback) {
                    _callback();
                }
                _locked = false;
            });

            return true;
        }
        return false;
    }

    void resetTimeout(int who) {
        std::scoped_lock<std::mutex> _(_mutex);

        if (!_locked || _owner != who) {
            return;
        }

        _stops = _stops > 0 ? _stops - 1 : 0;

        if (_stops == 0) {
            _timeout.reset();
        }
    }

    void stopTimeout(int who) {
        std::scoped_lock<std::mutex> _(_mutex);

        if (!_locked || _owner != who) {
            return;
        }

        _timeout.stop();
        _stops++;
    }

    bool unlock(int who) {
        std::scoped_lock<std::mutex> _(_mutex);

        if (_owner != who) {
            return false;
        }

        _timeout.stop();
        _locked = false;
        return true;
    }

    void forceUnlock() {
        std::scoped_lock<std::mutex> _(_mutex);

        _timeout.stop();
        _locked = false;
    }

    bool ownedBy(int who) {
        std::scoped_lock<std::mutex> _(_mutex);
        return _locked && _owner == who;
    }

    ~TimeoutLock() {
        _timeout.stop();
    }
};


} // namespace jac
```


