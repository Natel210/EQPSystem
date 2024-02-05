#include "StopWatch.h"

const std::wstring StopWatch::Name() const
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

void StopWatch::Name(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    if (_name.compare(name) == 0)
        return;
    _name = name;
}

const bool StopWatch::Active() const
{
    std::lock_guard<std::mutex> lock(_activeMutex);
    return _active;
}

void StopWatch::Active(const bool active)
{

    std::lock_guard<std::mutex> lock(_activeMutex);
    _active = active;
}

void StopWatch::Start(const std::chrono::steady_clock::time_point& startTime)
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    if (Active() == false)
        return;
    _startTime = startTime;
}

void StopWatch::Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime)
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    if (Active() == false)
        return;
    Interval(interval);
    _startTime = startTime;
}

void StopWatch::Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime)
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    if (Active() == false)
        return;
    Interval(interval);
    _startTime = startTime;
}

void StopWatch::End()
{
    if (Active() == false)
        return;
}

const std::chrono::milliseconds StopWatch::Interval() const
{
    std::lock_guard<std::mutex> lock(_intervalMutex);
    return std::chrono::milliseconds(_interval);
}

void StopWatch::Interval(const std::chrono::milliseconds& interval)
{
    std::lock_guard<std::mutex> lock(_intervalMutex);
    if (Active() == false)
        return;
    if (interval < std::chrono::milliseconds(0))
        return;
    _interval = interval;
}

void StopWatch::Interval(const long long& interval)
{
    std::lock_guard<std::mutex> lock(_intervalMutex);
    if (Active() == false)
        return;
    auto tempInterval = std::chrono::milliseconds(interval);
    if (tempInterval < std::chrono::milliseconds(0))
        return;
    _interval = tempInterval;
}

bool StopWatch::IsOver() const
{
    std::lock_guard<std::mutex> lock(_timeMutex);
    if (Active() == false)
        return false;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _startTime);
    return elapsed >= Interval();
}