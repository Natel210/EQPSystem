#pragma once
#include <string>
#include <chrono>
#include "CoreEntryDefine.h"
#include "IObjectClass.h"

class DLL_API ITimer : public IObjectClass
{

#pragma region Super

#pragma region Name
public:
	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] const std::wstring Name() const override = 0;
	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	void Name(const std::wstring& name) override = 0;
#pragma endregion

#pragma region Active
public:
	/// <summary>
	/// Get Active.
	/// </summary>
	[[nodiscard]] const bool Active() const override = 0;
protected:
	/// <summary>
	/// Set Active.
	/// </summary>
	void Active(const bool active) override = 0;
#pragma endregion

#pragma endregion

#pragma region Time Tracking
public:
	/// <summary>
	/// Marking Time Start Point, Able Time Tracking.
	/// </summary>
	virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
	/// <summary>
	/// Disable Time Tracking.
	/// </summary>
	virtual void End() = 0;
#pragma endregion

#pragma region Durations
public:
	[[nodiscard]] virtual int DurationSince_Year() const = 0;
	[[nodiscard]] virtual int DurationSince_Month() const = 0;
	[[nodiscard]] virtual int DurationSince_Week() const = 0;
	[[nodiscard]] virtual int DurationSince_Day() const = 0;
	[[nodiscard]] virtual int DurationSince_Hour() const = 0;
	[[nodiscard]] virtual int DurationSince_Minute() const = 0;
	[[nodiscard]] virtual long long DurationSince_Seconds() const = 0;
	[[nodiscard]] virtual long long DurationSince_Milliseconds() const = 0;
#pragma endregion
public:
	/// <summary>
	/// virtual destructor.
	/// </summary>
	virtual ~ITimer() = default;
};