#include "dream/component/DreamIntervalCounterComponent.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMINTERVALCOUNTERCOMPONENT
#define DEFINITION_DREAMINTERVALCOUNTERCOMPONENT
#pragma endregion

bool DreamIntervalCounterComponent::Initialize()
{
    bool result = dream::base::DreamComponentBase::Initialize();
    if (result == true)
        Alive();
    return result;
}

bool DreamIntervalCounterComponent::Release()
{
    _runTime.Set(false);
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

const bool DreamIntervalCounterComponent::RunTime() const
{
    if (IsAlive() == false)
        return false;
    return _runTime.Get();
}

const std::chrono::steady_clock::time_point DreamIntervalCounterComponent::StartTime() const
{
    if (IsAlive() == false)
        return std::chrono::steady_clock::time_point();
    return _startTime.Get();
}

const std::chrono::milliseconds DreamIntervalCounterComponent::Interval() const
{
    if (IsAlive() == false)
        return std::chrono::milliseconds(0);
    return std::chrono::milliseconds(_interval.Get().count());
}

void DreamIntervalCounterComponent::Interval(const std::chrono::milliseconds& interval)
{
    if (IsAlive() == false)
        return;
    _interval.Set(interval);
}

void DreamIntervalCounterComponent::Interval(const long long& interval)
{
    if (IsAlive() == false)
        return;
    _interval.Set(std::chrono::milliseconds(interval));
}

void DreamIntervalCounterComponent::Start(const std::chrono::steady_clock::time_point& startTime)
{
    if (IsAlive() == false)
        return;
    _startTime.Set(startTime);
    _runTime.Set(true);
}

void DreamIntervalCounterComponent::Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime)
{
    if (IsAlive() == false)
        return;
    Interval(interval);
    _startTime.Set(startTime);
    _runTime.Set(true);
}

void DreamIntervalCounterComponent::Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime)
{
    if (IsAlive() == false)
        return;
    Interval(interval);
    _startTime.Set(startTime);
    _runTime.Set(true);
}

void DreamIntervalCounterComponent::End()
{
    if (IsAlive() == false)
        return;
    _runTime.Set(false);
}

const int DreamIntervalCounterComponent::Counter() const
{
    if (IsAlive() == false)
        return 0;
    if (RunTime() == false)
        return 0;
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - StartTime());
    auto interval = Interval();
    auto result = static_cast<int>(duration.count() / interval.count());
    return static_cast<int>(result);
}

DreamIntervalCounterComponent::DreamIntervalCounterComponent(const std::string& name, const std::string& classType)
    : DreamComponentBase(name, classType)
{
}

DreamIntervalCounterComponent::DreamIntervalCounterComponent(const DreamIntervalCounterComponent& other)
    : DreamComponentBase(other)
{
    _runTime.Set(other._runTime.Get());
    _startTime.Set(other._startTime.Get());
    _interval.Set(other._interval.Get());
}

#pragma region Avoid duplication
#endif // !DEFINITION_DREAMINTERVALCOUNTERCOMPONENT
#pragma endregion
#pragma region Namesapce
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion