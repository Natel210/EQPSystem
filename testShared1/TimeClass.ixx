export module TimeClass;

import ObjectClass;
import <chrono>;
namespace time_class
{
	export class IntervalCounter : public object_class::AObjectClass
	{
	public:
		inline bool Initialize() final
		{
			Interval(0LL);
			StartTime(std::chrono::steady_clock::now());
			RunTime(false);
			return true;
		}
		inline bool Release() final
		{
			return true;
		}
	public:
		inline const std::chrono::milliseconds Interval() const
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			return std::chrono::milliseconds(_interval.count());
		}
		inline void Interval(const std::chrono::milliseconds& interval)
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			_interval = interval;
		}
		inline void Interval(const long long& interval)
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			_interval = std::chrono::milliseconds(interval);
		}
	public:
		void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			StartTime(startTime);
			RunTime(true);
		}
		inline void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			Interval(interval);
			StartTime(startTime);
			RunTime(true);
		}
		inline void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			Interval(interval);
			StartTime(startTime);
			RunTime(true);
		}
		virtual void End()
		{
			RunTime(false);
		}

		virtual int Counter() const
		{
			if (RunTime() == false)
				return false;


			auto now = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - StartTime());
			auto interval = Interval();
			auto result = static_cast<int>(duration.count() / interval.count());
			return static_cast<int>(result);
		}

	public:
		inline const bool RunTime() const
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			return _runTime;
			
		}
	private:
		inline void RunTime(const bool runTimer)
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			_runTime = runTimer;
		}
	public:
		inline const std::chrono::steady_clock::time_point StartTime() const
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			return _startTime;
		}
	private:
		inline void StartTime(const std::chrono::steady_clock::time_point startTime)
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			_startTime = startTime;
		}
	public:
		IntervalCounter(std::wstring name) : object_class::AObjectClass(name, _classType) {}
		virtual ~IntervalCounter() = default;
	private:
		bool _runTime = false;
		mutable std::mutex _runTimeMutex;
		std::chrono::steady_clock::time_point _startTime;
		mutable std::mutex _startTimeMutex;
		std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
		mutable std::mutex _intervalMutex;
	public:
		static constexpr wchar_t _classType[] = L"IntervalCounter";
	};

	/// <summary>
	/// 특정 시간으로 부터 얼만큼 흘렀는지에 대해서 알려주는 클래스
	/// </summary>
	export class StopWatch : public object_class::AObjectClass
	{
	public:
		inline bool Initialize() final
		{
			return true;
		}
		inline bool Release() final
		{
			return true;
		}
	public:
		void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			StartTime(startTime);
			RunTime(true);
		}
		virtual void End()
		{
			RunTime(false);
		}
	public:
		std::chrono::years GetDuration_toYears(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::years>(GetDuration(nowTime));
		}
		std::chrono::months GetDuration_toMonths(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::months>(GetDuration(nowTime));
		}
		std::chrono::weeks GetDuration_toWeeks(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::weeks>(GetDuration(nowTime));
		}
		std::chrono::days GetDuration_toDay(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::days>(GetDuration(nowTime));
		}
		std::chrono::hours GetDuration_toHours(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::hours>(GetDuration(nowTime));
		}
		std::chrono::minutes GetDuration_toMinutes(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::minutes>(GetDuration(nowTime));
		}
		std::chrono::seconds GetDuration_toSeconds(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return std::chrono::duration_cast<std::chrono::seconds>(GetDuration(nowTime));
		}
		std::chrono::milliseconds GetDuration_toMilliseconds(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now())
		{
			return GetDuration(nowTime);
		}
	private:
		std::chrono::milliseconds GetDuration(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) const
		{
			if (RunTime() == false)
				return std::chrono::milliseconds(0);
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - StartTime());
			return duration;
		}
	public:
		inline const bool RunTime() const
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			return _runTime;
		}
	private:
		inline void RunTime(const bool runTimer)
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			_runTime = runTimer;
		}
	public:
		inline const std::chrono::steady_clock::time_point StartTime() const
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			return _startTime;
		}
	private:
		inline void StartTime(const std::chrono::steady_clock::time_point startTime)
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			_startTime = startTime;
		}
	public:
		StopWatch(std::wstring name) : object_class::AObjectClass(name, _classType) {}
		virtual ~StopWatch() = default;
	private:
		bool _runTime = false;
		mutable std::mutex _runTimeMutex;
		std::chrono::steady_clock::time_point _startTime;
		mutable std::mutex _startTimeMutex;
	public:
		static constexpr wchar_t _classType[] = L"StopWatch";
	};

	/// <summary>
	/// 특정 시간 지남에 유무를 알려주는 클래스
	/// </summary>
	export class Timer : public object_class::AObjectClass
	{
	public:
		inline bool Initialize() final
		{
			return true;
		}
		inline bool Release() final
		{
			return true;
		}
	public:
		inline const std::chrono::milliseconds Interval() const
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			return _interval;
		}
		inline void Interval(const std::chrono::milliseconds& interval)
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			_interval = interval;
		}
		inline void Interval(const long long& interval)
		{
			std::lock_guard<std::mutex> lock(_intervalMutex);
			_interval = std::chrono::milliseconds(interval);
		}
	public:
		inline void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			StartTime(startTime);
			RunTime(true);
		}
		inline void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			Interval(interval);
			StartTime(startTime);
			RunTime(true);
		}
		inline void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now())
		{
			Interval(interval);
			StartTime(startTime);
			RunTime(true);
		}
		inline void End()
		{
			RunTime(false);
		}
		inline bool IsOver()
		{
			if (RunTime() == false)
				return false;
			auto now = std::chrono::steady_clock::now();
			return now - StartTime() >= Interval();
		}
	public:
		inline const bool RunTime() const
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			return _runTime;
		}
	private:
		inline void RunTime(const bool runTimer)
		{
			std::lock_guard<std::mutex> lock(_runTimeMutex);
			_runTime = runTimer;
		}
	public:
		inline const std::chrono::steady_clock::time_point StartTime() const
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			return _startTime;
		}
	private:
		inline void StartTime(const std::chrono::steady_clock::time_point startTime)
		{
			std::lock_guard<std::mutex> lock(_startTimeMutex);
			_startTime = startTime;
		}
	public:
		Timer(std::wstring name) : object_class::AObjectClass(name, _classType) {}
		virtual ~Timer() = default;
	private:
		bool _runTime = false;
		mutable std::mutex _runTimeMutex;
		std::chrono::steady_clock::time_point _startTime;
		mutable std::mutex _startTimeMutex;
		std::chrono::milliseconds _interval = std::chrono::milliseconds(0);
		mutable std::mutex _intervalMutex;
	public:
		static constexpr wchar_t _classType[] = L"Timer";
	};

	namespace internal_class
	{
		class TimeClass_Manager
		{
		public:
			inline static TimeClass_Manager& Instance()
			{
				static TimeClass_Manager instance;
				return instance;
			}
		private:
			inline TimeClass_Manager() {}
			inline ~TimeClass_Manager() {}
		public:
			inline TimeClass_Manager(const TimeClass_Manager&) = delete;
			inline TimeClass_Manager& operator=(const TimeClass_Manager&) = delete;
		public:
			inline bool CreateIntervalCounter(const std::wstring& name)
			{
				auto intervalCounter = std::make_shared<IntervalCounter>(name);
				if (intervalCounter == nullptr)
					return false;
				if (intervalCounter->ClassType() != IntervalCounter::_classType)
					return false;
				if (object_class::CreateObject(name, intervalCounter) == false)
					return false;
				return true;
			}
			inline std::weak_ptr<IntervalCounter> GetIntervalCounter(const std::wstring& name)
			{
				auto getObject = object_class::GetObject<IntervalCounter>(name);
				if (getObject.expired() == true)
					return std::weak_ptr<IntervalCounter>();
				if (getObject.lock()->ClassType() != IntervalCounter::_classType)
					return std::weak_ptr<IntervalCounter>();
				return getObject;
			}
			inline void KillIntervalCounter(const std::wstring& name)
			{
				object_class::KillObject(name);
			}
		public:
			inline bool CreateStopWatch(const std::wstring& name)
			{
				auto stopWatch = std::make_shared<StopWatch>(name);
				if (stopWatch == nullptr)
					return false;
				if (stopWatch->ClassType() != StopWatch::_classType)
					return false;
				if (object_class::CreateObject(name, stopWatch) == false)
					return false;
				return true;
			}
			inline std::weak_ptr<StopWatch> GetStopWatch(const std::wstring& name)
			{
				auto getObject = object_class::GetObject<StopWatch>(name);
				if (getObject.expired() == true)
					return std::weak_ptr<StopWatch>();
				if (getObject.lock()->ClassType() != StopWatch::_classType)
					return std::weak_ptr<StopWatch>();
				return getObject;
			}
			inline void KillStopWatch(const std::wstring& name)
			{
				object_class::KillObject(name);
			}
		public:
			inline bool CreateTimer(const std::wstring& name)
			{
				auto timer = std::make_shared<Timer>(name);
				if (timer == nullptr)
					return false;
				if (timer->ClassType() != Timer::_classType)
					return false;
				if (object_class::CreateObject(name, timer) == false)
					return false;
				return true;
			}
			inline std::weak_ptr<Timer> GetTimer(const std::wstring& name)
			{
				auto getObject = object_class::GetObject<Timer>(name);
				if (getObject.expired() == true)
					return std::weak_ptr<Timer>();
				if (getObject.lock()->ClassType() != Timer::_classType)
					return std::weak_ptr<Timer>();
				return getObject;
			}
			inline void KillTimer(const std::wstring& name)
			{
				object_class::KillObject(name);
			}
		public:
			inline bool GetCurrentClock()
			{
				return true;
			}
		};
	}

	export bool CreateIntervalCounter(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().CreateIntervalCounter(name);
	}
	export std::weak_ptr<IntervalCounter> GetIntervalCounter(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().GetIntervalCounter(name);
	}
	export void KillIntervalCounter(const std::wstring& name)
	{
		internal_class::TimeClass_Manager::Instance().KillIntervalCounter(name);
	}
	export bool CreateStopWatch(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().CreateStopWatch(name);
	}
	export std::weak_ptr<StopWatch> GetStopWatch(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().GetStopWatch(name);
	}
	export void KillStopWatch(const std::wstring& name)
	{
		internal_class::TimeClass_Manager::Instance().KillStopWatch(name);
	}
	export bool CreateTimer(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().CreateTimer(name);
	}
	export std::weak_ptr<Timer> GetTimer(const std::wstring& name)
	{
		return internal_class::TimeClass_Manager::Instance().GetTimer(name);
	}
	export void KillTimer(const std::wstring& name)
	{
		internal_class::TimeClass_Manager::Instance().KillTimer(name);
	}
	export bool GetCurrentClock()
	{
		return  internal_class::TimeClass_Manager::Instance().GetCurrentClock();
	}
}
