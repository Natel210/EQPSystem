#pragma once
#include <chrono>
#include "ITimer.h"

class Timer : public ITimer
{
#pragma region interface

#pragma region Name
public:
	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] const std::wstring Name() const final;
	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	void Name(const std::wstring& name) final;
#pragma endregion

#pragma region Active
public:
	/// <summary>
	/// Get Active.
	/// </summary>
	[[nodiscard]] const bool Active() const final;
protected:
	/// <summary>
	/// Set Active.
	/// </summary>
	void Active(const bool active) final;
#pragma endregion


#pragma region Time Tracking
public:
	/// <summary>
	/// Marking Time Start Point, Able Time Tracking.
	/// </summary>
	void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	/// <summary>
	/// Disable Time Tracking.
	/// </summary>
	void End() final;
#pragma endregion

#pragma region Durations
public:
	[[nodiscard]] int DurationSince_Year() const final;
	[[nodiscard]] int DurationSince_Month() const final;
	[[nodiscard]] int DurationSince_Week() const final;
	[[nodiscard]] int DurationSince_Day() const final;
	[[nodiscard]] int DurationSince_Hour() const final;
	[[nodiscard]] int DurationSince_Minute() const final;
	[[nodiscard]] long long DurationSince_Seconds() const final;
	[[nodiscard]] long long DurationSince_Milliseconds() const final;
#pragma endregion

#pragma endregion
private:
	std::wstring _name = L"";
	bool _active = false;
	std::chrono::steady_clock::time_point _startTime = std::chrono::steady_clock::now();
	mutable std::mutex _nameMutex;
	mutable std::mutex _activeMutex;
	mutable std::mutex _timeMutex;
};

