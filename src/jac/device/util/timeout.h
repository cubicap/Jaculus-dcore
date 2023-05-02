#pragma once

#include <chrono>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>


namespace jac {


class Timeout {
    std::function<void()> _callback;
    std::chrono::milliseconds _duration;
    std::chrono::steady_clock::time_point _endTime = std::chrono::steady_clock::time_point::max();
    bool _stop = false;
    bool _running = false;
    std::mutex _mutex;
    std::condition_variable _cv;
    std::thread _thread;
public:
    Timeout(std::chrono::milliseconds duration):
        _duration(duration)
    {
        _thread = std::thread([this]() {
            while (!_stop) {
                std::unique_lock<std::mutex> lock(_mutex);
                if (!_running) {
                    _cv.wait(lock);
                    continue;
                }
                if (std::chrono::steady_clock::now() >= _endTime) {
                    _running = false;
                    if (_callback) {
                        _callback();
                    }
                }
                _cv.wait_until(lock, _endTime);
            }
        });
    }

    Timeout(const Timeout&) = delete;
    Timeout(Timeout&&) = delete;
    Timeout& operator=(const Timeout&) = delete;
    Timeout& operator=(Timeout&&) = delete;

    void start(std::function<void()> callback) {
        std::unique_lock<std::mutex> lock(_mutex);
        _endTime = std::chrono::steady_clock::now() + _duration;
        _callback = callback;
        _running = true;
        _cv.notify_all();
    }

    void reset() {
        std::scoped_lock<std::mutex> lock(_mutex);
        _endTime = std::chrono::steady_clock::now() + _duration;
        _running = true;
        _cv.notify_all();
    }

    void stop() {
        std::unique_lock<std::mutex> lock(_mutex);
        _running = false;
        _cv.notify_all();
    }

    ~Timeout() {
        std::unique_lock<std::mutex> lock(_mutex);
        _stop = true;
        _running = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        lock.unlock();
        _cv.notify_all();
        _thread.join();
    }
};


} // namespace jac
