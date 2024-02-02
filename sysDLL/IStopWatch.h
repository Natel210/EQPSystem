#pragma once
#include <chrono>
class IStopWatch
{
public:
    virtual void Start() = 0;
    virtual void SetInterval(const std::chrono::milliseconds& interval) = 0;
    virtual bool IsOver() const = 0;
};