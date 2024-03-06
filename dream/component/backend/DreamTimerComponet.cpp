#include "dream/component/DreamTimerComponet.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMTIMERCOMPONET
#define DEFINITION_DREAMTIMERCOMPONET
#pragma endregion

bool DreamTimerComponet::Initialize()
{
	bool result = dream::base::DreamComponentBase::Initialize();
	if (result == true)
		Alive();
	return result;
}

bool DreamTimerComponet::Release()
{
	bool result = dream::base::DreamComponentBase::Release();
	if (result == true)
		Kill();
	return result;
}

std::shared_ptr<dream::base::DreamObjectBase> DreamTimerComponet::Clone_ToObject() const
{
	return std::shared_ptr<dream::base::DreamObjectBase>();
}

std::shared_ptr<DreamTimerComponet> DreamTimerComponet::Clone()
{
	return std::shared_ptr<DreamTimerComponet>();
}

const bool DreamTimerComponet::RunTime() const
{
	return _runTime.Get();
}

const std::chrono::steady_clock::time_point DreamTimerComponet::StartTime() const
{
	return _startTime.Get();
}

const std::chrono::milliseconds DreamTimerComponet::Interval() const
{
	return std::chrono::milliseconds(_interval.Get().count());
}

void DreamTimerComponet::Interval(const std::chrono::milliseconds& interval)
{
	_interval.Set(interval);
}

void DreamTimerComponet::Interval(const long long& interval)
{
	_interval.Set(std::chrono::milliseconds(interval));
}

void DreamTimerComponet::Start(const std::chrono::steady_clock::time_point& startTime)
{
	_startTime.Set(startTime);
	_runTime.Set(true);
}

void DreamTimerComponet::Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime)
{
	Interval(interval);
	_startTime.Set(startTime);
	_runTime.Set(true);
}

void DreamTimerComponet::Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime)
{
	Interval(interval);
	_startTime.Set(startTime);
	_runTime.Set(true);
}

void DreamTimerComponet::End()
{
	_runTime.Set(false);
}

bool DreamTimerComponet::IsOver()
{
	if (RunTime() == false)
		return false;
	auto now = std::chrono::steady_clock::now();
	return now - StartTime() >= Interval();
}

const std::chrono::milliseconds DreamTimerComponet::RemainTime()
{
	if (RunTime() == false)
		return std::chrono::milliseconds(0);
	auto now = std::chrono::steady_clock::now();
	return std::chrono::milliseconds((now - StartTime()).count());
}

DreamTimerComponet::DreamTimerComponet(const std::string& name, const std::string& classType)
	: DreamComponentBase(name, classType)
{
}

DreamTimerComponet::DreamTimerComponet(const DreamTimerComponet& other)
	: DreamComponentBase(other)
{
}

#pragma region Avoid duplication
#endif // !DEFINITION_DREAMTIMERCOMPONET
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion