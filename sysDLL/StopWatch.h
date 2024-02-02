#pragma once
#include <chrono>
#include "IStopWatch.h"

class StopWatch : public IStopWatch
{
public:
    void Start() final;
    void SetInterval(const std::chrono::milliseconds& interval) final;
    bool IsOver() const final;

private:
    
    std::chrono::steady_clock::time_point _startTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
};

