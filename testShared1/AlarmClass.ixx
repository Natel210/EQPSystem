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
			if (_judgmentFunction != nullptr) // �Ǵ� �Լ��� �����Ǿ����� Ȯ��
				currentJudgment = _judgmentFunction(); // ���� �˶� ���� �Ǵ�
			if (currentJudgment == true) // �˶��� �ö�����
			{
				if (_alarmPrevTimer != nullptr) // ���� Ÿ�̸Ӱ� �ִ� ���
				{
					if (_alarmPrevTimer->RunTime() == false) // ���� Ÿ�̸Ӱ� ���� ���� ���
						_alarmPrevTimer->Start();
					else // �̹� ���� �ִ� ���
					{
						if (_alarmPrevTimer->IsOver() == true) // �ð� �ʰ�
						{
							if (_alarmStopWatch != nullptr)
								_alarmStopWatch.Start();
							_atLastJudgment = currentJudgment;
						}
					}
				}
				else // ���� ���
				{
					if (_alarmStopWatch != nullptr)
						_alarmStopWatch.Start();
					_atLastJudgment = currentJudgment;
				}

				// ���� Ÿ�̸Ӱ� �ִ°�� ��ž
				if (_alarmAfterTimer != nullptr)
					_alarmAfterTimer->Stop();
			}
			else // �˶��� ��������
			{
				if (_alarmAfterTimer != nullptr) // ���� Ÿ�̸Ӱ� �ִ� ���
				{
					if (_alarmAfterTimer->RunTime() == false) // ���� Ÿ�̸Ӱ� ���� ���� ���
						_alarmAfterTimer->Start();
					else // �̹� ���� �ִ� ���
					{
						if (_alarmAfterTimer->IsOver() == true) // �ð� �ʰ�
							_atLastJudgment = currentJudgment;
					}
				}
				else // ���°��
					_atLastJudgment = currentJudgment;

				// ���� Ÿ�̸Ӱ� �ִ°�� ��ž
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
		// true �߻� false �̹߻�
		bool _atLastJudgment = false;
		std::function<bool()> _judgmentFunction = nullptr;
		// ù �߻� �� �Ⱓ �ȿ� ���� �߻� �Ǵ���
		std::shared_ptr<time_class::Timer> _alarmPrevTimer = nullptr;
		// ù �ذ� �� �Ⱓ �ȿ� ���� �ذ� �Ǵ���
		std::shared_ptr<time_class::Timer> _alarmAfterTimer = nullptr;
		// �߻� �Ⱓ
		std::shared_ptr<time_class::StopWatch> _alarmStopWatch = nullptr;
		std::shared_ptr<log_class::ALogClass> _alarmLog = nullptr;
	public:
		static constexpr wchar_t _classType[] = L"Alarm";

	};
}