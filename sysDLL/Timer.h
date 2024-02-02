#pragma once
#include <chrono>
#include "ITimer.h"

class Timer : public ITimer
{
#pragma region interface
public:
	[[nodiscard]] const std::wstring Name() const final;
	void Name(const std::wstring name) final;
public:
	void Start() final;
	[[nodiscard]] double ElapsedMilliseconds() const final;
#pragma endregion

private:
	std::wstring _name = L"";
	std::chrono::steady_clock::time_point _startTime = std::chrono::steady_clock::now();
	mutable std::mutex _nameMutex;
	mutable std::mutex _timeMutex;
};

