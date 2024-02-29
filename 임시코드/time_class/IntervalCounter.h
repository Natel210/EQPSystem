#pragma once
#include <chrono>
#include "Shared/obejct_class/backend/AObjectClass.h"
namespace time_class
{
#ifndef DECLARE_IINTERVALCOUNTER
#define DECLARE_IINTERVALCOUNTER
	class IntervalCounter : public object_class::backend::AObjectClass
	{
	public:
		bool Initialize() final;
		bool Release() final;
	public:
		virtual const std::chrono::milliseconds Interval() const final;
		virtual void Interval(const std::chrono::milliseconds& interval) final;
		virtual void Interval(const long long& interval) final;
	public:
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void End() final;
	public:
		virtual const int Counter() const final;
	public:
		virtual const bool RunTime() const final;
		virtual const std::chrono::steady_clock::time_point StartTime() const final;
	public:
		IntervalCounter(std::wstring name);
		virtual ~IntervalCounter() = default;
	private:
		bool _runTime = false;
		mutable std::mutex _runTimeMutex;
		std::chrono::steady_clock::time_point _startTime;
		mutable std::mutex _startTimeMutex;
		std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
		mutable std::mutex _intervalMutex;
	private:
		static constexpr wchar_t _classType[] = L"IntervalCounter";
	};
#endif // !DECLARE_IINTERVALCOUNTER

}



