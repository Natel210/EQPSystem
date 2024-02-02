#include "StopWatch.h"

const std::wstring StopWatch::Name() const
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

void StopWatch::Name(const std::wstring name)
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    if (_name.compare(name) == 0)
        return;
    _name = name;
}

void StopWatch::Start()
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    _startTime = std::chrono::steady_clock::now();
}

void StopWatch::SetInterval(const std::chrono::milliseconds& interval)
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    if (interval < std::chrono::milliseconds(0))
        _interval = std::chrono::milliseconds(0);
    else
        _interval = interval;
}

bool StopWatch::IsOver() const
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _startTime);
    return elapsed >= _interval;
}
