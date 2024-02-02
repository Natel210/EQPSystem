#pragma once
#include "IStopWatch.h"

class StopWatch : public IStopWatch
{
#pragma region interface
public:
    [[nodiscard]] const std::wstring Name() const final;
    void Name(const std::wstring name) final;
public:
    void Start() final;
    void SetInterval(const std::chrono::milliseconds& interval) final;
    [[nodiscard]] bool IsOver() const final;
#pragma endregion

private:
    std::wstring _name = L"";
    std::chrono::steady_clock::time_point _startTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
    mutable std::mutex _nameMutex;
    mutable std::mutex _timeMutex;
};

