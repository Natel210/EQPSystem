#pragma once
#include <string>
#include <memory>
#include "ITimer.h"
#include "IStopWatch.h"
#include "CoreEntryDefine.h"
class TimeManager
{
public:
	static std::shared_ptr<ITimer> CreateTimer(const std::wstring name);
	static const bool DeleteTimer(const std::wstring name);
	static std::shared_ptr<ITimer> GetTimer(const std::wstring name);
public:
	static std::shared_ptr<IStopWatch> CreateStopWatch(const std::wstring name);
	static const bool DeleteStopWatch(const std::wstring name);
	static std::shared_ptr<IStopWatch> GetStopWatch(const std::wstring name);
public:
	static std::tm GetCurrentSystemTime();
};

