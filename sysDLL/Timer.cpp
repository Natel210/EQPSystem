#include "Timer.h"

const std::wstring Timer::Name() const
{
	std::lock_guard<std::mutex> lock(_nameMutex);
	return _name;
}

void Timer::Name(const std::wstring& name)
{
	std::lock_guard<std::mutex> lock(_nameMutex);
	if (_name.compare(name) == 0)
		return;
	_name = name;
}

const bool Timer::Active() const
{
	std::lock_guard<std::mutex> lock(_activeMutex);
	return _active;
}

void Timer::Active(const bool active)
{
	std::lock_guard<std::mutex> lock(_activeMutex);
	_active = active;
}

void Timer::Start(const std::chrono::steady_clock::time_point& startTime)
{
	std::lock_guard<std::mutex> lock(_timeMutex);
	_startTime = startTime;
	Active(true);
}

void Timer::End()
{
	std::lock_guard<std::mutex> lock(_timeMutex);
	Active(false);
}

int Timer::DurationSince_Year() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::years>(end - _startTime);
	return elapsed.count();
}

int Timer::DurationSince_Month() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::months>(end - _startTime);
	return elapsed.count();
}

int Timer::DurationSince_Week() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::weeks>(end - _startTime);
	return elapsed.count();
}

int Timer::DurationSince_Day() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::days>(end - _startTime);
	return elapsed.count();
}

int Timer::DurationSince_Hour() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::hours>(end - _startTime);
	return elapsed.count();
}

int Timer::DurationSince_Minute() const
{
	if (Active() == false)
		return 0;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::minutes>(end - _startTime);
	return elapsed.count();
}

long long Timer::DurationSince_Seconds() const
{
	if (Active() == false)
		return 0LL;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - _startTime);
	return elapsed.count();
}

long long Timer::DurationSince_Milliseconds() const
{
	if (Active() == false)
		return 0LL;
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - _startTime);
	return elapsed.count();
}

