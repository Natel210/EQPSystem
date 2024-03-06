#include "dream/component/DreamStopWatchComponent.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMSTOPWATCHCOMPONENT
#define DEFINITION_DREAMSTOPWATCHCOMPONENT
#pragma endregion

bool DreamStopWatchComponent::Initialize()
{
	bool result = dream::base::DreamComponentBase::Initialize();
	if (result == true)
		Alive();
	return result;
}

bool DreamStopWatchComponent::Release()
{
	bool result = dream::base::DreamComponentBase::Release();
	if (result == true)
		Kill();
	return result;
}

std::shared_ptr<base::DreamObjectBase> DreamStopWatchComponent::Clone_ToObject() const
{
	return std::make_shared<DreamStopWatchComponent>(*this);
}

std::shared_ptr<DreamStopWatchComponent> DreamStopWatchComponent::Clone()
{
	return std::dynamic_pointer_cast<DreamStopWatchComponent>(Clone_ToObject());
}

const bool DreamStopWatchComponent::RunTime() const
{
	return _runTime.Get();
}

const std::chrono::steady_clock::time_point DreamStopWatchComponent::StartTime() const
{
	return _startTime.Get();
}

void DreamStopWatchComponent::Start(const std::chrono::steady_clock::time_point& startTime)
{
	_startTime.Set(startTime);
	_runTime.Set(true);
}

void DreamStopWatchComponent::End()
{
	if (_runTime.Get() == false)
		return;
	_lastTime.Set(std::chrono::steady_clock::now());
	_runTime.Set(false);
}

#if _HAS_CXX20

std::chrono::years DreamStopWatchComponent::GetDuration_toYears(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::years>(GetDuration(nowTime));
}

std::chrono::months DreamStopWatchComponent::GetDuration_toMonths(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::months>(GetDuration(nowTime));
}

std::chrono::weeks DreamStopWatchComponent::GetDuration_toWeeks(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::weeks>(GetDuration(nowTime));
}

std::chrono::days DreamStopWatchComponent::GetDuration_toDay(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::days>(GetDuration(nowTime));
}

#endif // _HAS_CXX20

std::chrono::hours DreamStopWatchComponent::GetDuration_toHours(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::hours>(GetDuration(nowTime));
}

std::chrono::minutes DreamStopWatchComponent::GetDuration_toMinutes(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::minutes>(GetDuration(nowTime));
}

std::chrono::seconds DreamStopWatchComponent::GetDuration_toSeconds(std::chrono::steady_clock::time_point nowTime)
{
	return std::chrono::duration_cast<std::chrono::seconds>(GetDuration(nowTime));
}

std::chrono::milliseconds DreamStopWatchComponent::GetDuration_toMilliseconds(std::chrono::steady_clock::time_point nowTime)
{
	return GetDuration(nowTime);
}

std::chrono::milliseconds DreamStopWatchComponent::GetDuration(std::chrono::steady_clock::time_point nowTime) const
{
	std::chrono::milliseconds duration = std::chrono::milliseconds(0);
	if (RunTime() == true)
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - StartTime());
	else
		duration = std::chrono::duration_cast<std::chrono::milliseconds>(_lastTime.Get() - StartTime());
	return duration;
}

DreamStopWatchComponent::DreamStopWatchComponent(const std::string& name, const std::string& classType)
	: DreamComponentBase(name, classType)
{
}

DreamStopWatchComponent::DreamStopWatchComponent(const DreamStopWatchComponent& other)
	: DreamComponentBase(other)
{
	_runTime.Set(other._runTime.Get());
	_startTime.Set(other._startTime.Get());
	_lastTime.Set(other._lastTime.Get());
}

#pragma region Avoid duplication
#endif 	// !DEFINITION_DREAMSTOPWATCHCOMPONENT
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion