#pragma once
#include "IStopWatch.h"

class StopWatch : public IStopWatch
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
	/// <param name="startTime"> -> Default : Now</param>
	void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	/// <summary>
	/// Marking Time Start Point, Able Time Tracking.
	/// </summary>
	/// <param name="interval"> -> Default : Different for each type </param>
	/// <param name="startTime"> -> Default : Now</param>
	void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	/// <summary>
	/// Marking Time Start Point, Able Time Tracking.
	/// </summary>
	/// <param name="interval"> -> Default : Different for each type </param>
	/// <param name="startTime"> -> Default : Now</param>
	void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	/// <summary>
	/// Disable Time Tracking.
	/// </summary>
	void End() final;
	/// <summary>
	/// Get Interval.
	/// </summary>
	const std::chrono::milliseconds Interval() const final;
	/// <summary>
	/// Set Interval.
	/// </summary>
	void Interval(const std::chrono::milliseconds& interval) final;
	/// <summary>
	/// Set Interval.
	/// </summary>
	void Interval(const long long& interval) final;
	/// <summary>
	/// Time Over Chack
	/// </summary>
	/// <returns>True -> Over<para/> Fasle -> Remains</returns>
	bool IsOver() const final;
#pragma endregion

#pragma endregion
private:
	
private:
    std::wstring _name = L"";
	bool _active = false;
    std::chrono::steady_clock::time_point _startTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
    mutable std::mutex _nameMutex;
	mutable std::mutex _activeMutex;
    mutable std::mutex _timeMutex;
	mutable std::mutex _intervalMutex;
};

