#include "Timer.h"

void Timer::Start()
{
	_start = std::chrono::steady_clock::now();
}

double Timer::ElapsedMilliseconds() const
{
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - _start);
	return elapsed.count();
}
