#include "dream/component/DreamIntervalCounterComponent.h"
namespace dream::componet
{
#ifndef DEFINITION_DREAMINTERVALCOUNTERCOMPONENT
#define DEFINITION_DREAMINTERVALCOUNTERCOMPONENT

    bool DreamIntervalCounterComponent::Initialize()
    {
        bool result = dream::base::DreamComponentBase::Initialize();
        if (result == true)
            Alive();
        return result;
    }

    bool DreamIntervalCounterComponent::Release()
    {
        bool result = dream::base::DreamComponentBase::Release();
        if (result == true)
            Kill();
        return result;
    }

    std::shared_ptr<base::DreamObjectBase> DreamIntervalCounterComponent::Clone_ToObject() const
    {
        return std::make_shared<DreamIntervalCounterComponent>(*this);
    }

    std::shared_ptr<DreamIntervalCounterComponent> DreamIntervalCounterComponent::Clone()
    {
        return std::dynamic_pointer_cast<DreamIntervalCounterComponent>(Clone_ToObject());
    }

    const std::chrono::milliseconds DreamIntervalCounterComponent::Interval() const
    {
        std::lock_guard<std::mutex> lock(_intervalMutex);
        return std::chrono::milliseconds(_interval.count());
    }

    void DreamIntervalCounterComponent::Interval(const std::chrono::milliseconds& interval)
    {
        std::lock_guard<std::mutex> lock(_intervalMutex);
        _interval = interval;
    }

    void DreamIntervalCounterComponent::Interval(const long long& interval)
    {
        std::lock_guard<std::mutex> lock(_intervalMutex);
        _interval = std::chrono::milliseconds(interval);
    }

    const bool DreamIntervalCounterComponent::RunTime() const
    {
        std::lock_guard<std::mutex> lock(_runTimeMutex);
        return _runTime;
    }

    const std::chrono::steady_clock::time_point DreamIntervalCounterComponent::StartTime() const
    {
        std::lock_guard<std::mutex> lock(_startTimeMutex);
        return _startTime;
    }

    void DreamIntervalCounterComponent::Start(const std::chrono::steady_clock::time_point& startTime)
    {
        StartTime(startTime);
        RunTime(true);
    }

    void DreamIntervalCounterComponent::Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime)
    {
        Interval(interval);
        StartTime(startTime);
        RunTime(true);
    }

    void DreamIntervalCounterComponent::Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime)
    {
        Interval(interval);
        StartTime(startTime);
        RunTime(true);
    }

    void DreamIntervalCounterComponent::End()
    {
        RunTime(false);
    }

    const int DreamIntervalCounterComponent::Counter() const
    {
        if (RunTime() == false)
            return 0;
        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - StartTime());
        auto interval = Interval();
        auto result = static_cast<int>(duration.count() / interval.count());
        return static_cast<int>(result);
    }

    void DreamIntervalCounterComponent::RunTime(const bool runTimer)
    {
        std::lock_guard<std::mutex> lock(_runTimeMutex);
        _runTime = runTimer;
    }

    void DreamIntervalCounterComponent::StartTime(const std::chrono::steady_clock::time_point startTime)
    {
        std::lock_guard<std::mutex> lock(_startTimeMutex);
        _startTime = startTime;
    }

    DreamIntervalCounterComponent::DreamIntervalCounterComponent(const std::string& name, const std::string& classType)
        : DreamComponentBase(name, classType)
    {
    }

    DreamIntervalCounterComponent::DreamIntervalCounterComponent(const DreamIntervalCounterComponent& other)
        : DreamComponentBase(other)
    {
        RunTime(other.RunTime());
        StartTime(other.StartTime());
        Interval(other.Interval());
    }

#endif // !DEFINITION_DREAMINTERVALCOUNTERCOMPONENT
}