#pragma once
#include <chrono>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamLogEnum.h"
#include "dream/base/DreamComponentBase.h"
namespace dream::componet
{
#ifndef DECLARATION_DREAMINTERVALCOUNTERCOMPONENT
#define DECLARATION_DREAMINTERVALCOUNTERCOMPONENT
	class DreamIntervalCounterComponent : public base::DreamComponentBase
	{
	public:
		bool Initialize() final;
		bool Release() final;
	protected:
		std::shared_ptr<base::DreamObjectBase> Clone_ToObject() const override;
	public:
		std::shared_ptr<DreamIntervalCounterComponent> Clone();
	public:
		virtual const std::chrono::milliseconds Interval() const final;
		virtual void Interval(const std::chrono::milliseconds& interval) final;
		virtual void Interval(const long long& interval) final;
	public:
		virtual const bool RunTime() const final;
		virtual const std::chrono::steady_clock::time_point StartTime() const final;
	public:
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
		virtual void End() final;
	public:
		virtual const int Counter() const final;
	private:
		void RunTime(const bool runTimer);
		void StartTime(const std::chrono::steady_clock::time_point startTime);
	public:
		DreamIntervalCounterComponent(const std::string& name, const std::string& classType = "DreamIntervalCounterComponent");
		virtual ~DreamIntervalCounterComponent() = default;
		DreamIntervalCounterComponent(const DreamIntervalCounterComponent& other);
	private:
		bool _runTime = false;
		mutable std::mutex _runTimeMutex;
		std::chrono::steady_clock::time_point _startTime;
		mutable std::mutex _startTimeMutex;
		std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
		mutable std::mutex _intervalMutex;
	};

#endif // !DECLARATION_DREAMINTERVALCOUNTERCOMPONENT
}