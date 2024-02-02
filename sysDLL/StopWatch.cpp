#include "StopWatch.h"

void StopWatch::Start()
{
    _startTime = std::chrono::steady_clock::now();
}

void StopWatch::SetInterval(const std::chrono::milliseconds& interval)
{
    _interval = interval;
}

bool StopWatch::IsOver() const
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _startTime);
    return elapsed >= _interval;
}
