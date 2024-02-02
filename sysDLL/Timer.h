#pragma once
#include <chrono>
#include "ITimer.h"

class Timer : public ITimer
{
public:
	void Start() final;

	double ElapsedMilliseconds() const final;
	//{
	//	auto end = std::chrono::steady_clock::now();
	//	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - _start);
	//	return elapsed.count();
	//}

private:
	std::chrono::steady_clock::time_point _start;
};

