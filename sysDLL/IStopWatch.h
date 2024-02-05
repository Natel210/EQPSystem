#pragma once
#include <string>
#include <chrono>
#include "CoreEntryDefine.h"
#include "IObjectClass.h"

class DLL_API IStopWatch : public IObjectClass
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
	/// <param name="startTime"> -> Default : Now</param>
	virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;

    /// <summary>
    /// Marking Time Start Point, Able Time Tracking.
    /// </summary>
    /// <param name="interval"> -> Default : Different for each type </param>
    /// <param name="startTime"> -> Default : Now</param>
    virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;

	/// <summary>
	/// Marking Time Start Point, Able Time Tracking.
	/// </summary>
	/// <param name="interval"> -> Default : Different for each type </param>
	/// <param name="startTime"> -> Default : Now</param>
	virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;

	/// <summary>
	/// Disable Time Tracking.
	/// </summary>
	virtual void End() = 0;

	/// <summary>
	/// Get Interval.
	/// </summary>
	virtual const std::chrono::milliseconds Interval() const = 0;

    /// <summary>
    /// Set Interval.
    /// </summary>
    virtual void Interval(const std::chrono::milliseconds& interval) = 0;

	/// <summary>
	/// Set Interval.
	/// </summary>
	virtual void Interval(const long long& interval) = 0;

    /// <summary>
    /// Time Over Chack
    /// </summary>
    /// <returns>True -> Over<para/> Fasle -> Remains</returns>
    virtual bool IsOver() const = 0;

#pragma endregion

public:
	/// <summary>
	/// virtual destructor.
	/// </summary>
	virtual ~IStopWatch() = default;
};