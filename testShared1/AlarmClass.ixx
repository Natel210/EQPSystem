export module AlarmClass;

import ObjectClass;
import LogClass;
import TimeClass;
import <functional>;
namespace alarm_class
{
	export enum class EAlarmLevel
	{
		None,
		Notify,
		Light,
		Heavy
	};

	export class AlarmClass : public object_class::AObjectClass
	{
	public:
		bool Initialize() final
		{
			return true;
		}
		bool Release() final
		{
			ResetAlarmPrevTimer();
			ResetAlarmLog();
			return true;
		}
	public:
		virtual inline [[nodiscard]] const EAlarmLevel Level() const final
		{
			std::lock_guard<std::mutex> lock(_levelMutex);
			return _level;
		}
		virtual inline void Level(const EAlarmLevel& leval) final
		{
			std::lock_guard<std::mutex> lock(_levelMutex);
			_level = leval;
		}
	public:
		inline void JudgmentFunction(std::function<bool()> judgmentFunction)
		{
			_judgmentFunction = judgmentFunction;
		}
		inline bool Judgment()
		{
			bool currentJudgment = false;
			if (_judgmentFunction != nullptr) // 판단 함수가 설정되었는지 확인
				currentJudgment = _judgmentFunction(); // 현재 알람 상태 판단
			if (currentJudgment == true) // 알람이 올라갔을때
			{
				if (_alarmPrevTimer != nullptr) // 사전 타이머가 있는 경우
				{
					if (_alarmPrevTimer->RunTime() == false) // 사전 타이머가 돌지 않은 경우
						_alarmPrevTimer->Start();
					else // 이미 돌고 있는 경우
					{
						if (_alarmPrevTimer->IsOver() == true) // 시간 초과
						{
							if (_alarmStopWatch != nullptr)
								_alarmStopWatch.Start();
							_atLastJudgment = currentJudgment;
						}
					}
				}
				else // 없는 경우
				{
					if (_alarmStopWatch != nullptr)
						_alarmStopWatch.Start();
					_atLastJudgment = currentJudgment;
				}

				// 사후 타이머가 있는경우 스탑
				if (_alarmAfterTimer != nullptr)
					_alarmAfterTimer->Stop();
			}
			else // 알람이 내려갈떄
			{
				if (_alarmAfterTimer != nullptr) // 사후 타이머가 있는 경우
				{
					if (_alarmAfterTimer->RunTime() == false) // 사전 타이머가 돌지 않은 경우
						_alarmAfterTimer->Start();
					else // 이미 돌고 있는 경우
					{
						if (_alarmAfterTimer->IsOver() == true) // 시간 초과
							_atLastJudgment = currentJudgment;
					}
				}
				else // 없는경우
					_atLastJudgment = currentJudgment;

				// 사전 타이머가 있는경우 스탑
				if (_alarmPrevTimer != nullptr) 
					_alarmPrevTimer->Stop();
			}

			return _atLastJudgment;
		}
	public:
		inline void AddAlarmPrevTimer(std::shared_ptr<time_class::Timer> timer)
		{
			ResetAlarmPrevTimer();
			_alarmPrevTimer = timer;
		}
		inline void ResetAlarmPrevTimer()
		{
			_alarmPrevTimer.reset();
		}
		inline void AddAlarmAfterTimer(std::shared_ptr<time_class::Timer> timer)
		{
			ResetAlarmAfterTimer();
			_alarmAfterTimer = timer;
		}
		inline void ResetAlarmAfterTimer()
		{
			_alarmAfterTimer.reset();
		}
		inline void AddStopWatch(std::shared_ptr<time_class::StopWatch> stopWatch)
		{
			ResetStopWatch();
			_alarmStopWatch = stopWatch;
		}
		inline void ResetStopWatch()
		{
			_alarmStopWatch.reset();
		}
		inline void AddAlarmLog(std::shared_ptr<log_class::ALogClass> log)
		{
			ResetAlarmPrevTimer();
			_alarmLog = log;
		}
		inline void ResetAlarmLog()
		{
			_alarmLog.reset();
		}
	private:
		EAlarmLevel _level = EAlarmLevel::None;
		mutable std::mutex _levelMutex;
	private:
		// true 발생 false 미발생
		bool _atLastJudgment = false;
		std::function<bool()> _judgmentFunction = nullptr;
		// 첫 발생 후 기간 안에 지속 발생 되는지
		std::shared_ptr<time_class::Timer> _alarmPrevTimer = nullptr;
		// 첫 해결 후 기간 안에 지속 해결 되는지
		std::shared_ptr<time_class::Timer> _alarmAfterTimer = nullptr;
		// 발생 기간
		std::shared_ptr<time_class::StopWatch> _alarmStopWatch = nullptr;
		std::shared_ptr<log_class::ALogClass> _alarmLog = nullptr;
	public:
		static constexpr wchar_t _classType[] = L"Alarm";

	};
}