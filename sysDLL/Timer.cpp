#include "Timer.h"

const std::wstring Timer::Name() const
{
	std::lock_guard<std::mutex> lock(_nameMutex);
	return _name;
}

void Timer::Name(const std::wstring name)
{
	std::lock_guard<std::mutex> lock(_nameMutex);
	if (_name.compare(name) == 0)
		return;
	_name = name;
}

void Timer::Start()
{
	std::lock_guard<std::mutex> lock(_timeMutex);
	_startTime = std::chrono::steady_clock::now();
}

double Timer::ElapsedMilliseconds() const
{
	std::lock_guard<std::mutex> lock(_timeMutex);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - _startTime);
	return elapsed.count();
}
