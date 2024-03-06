#include "dream/component/DreamAlarmComponent.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMALARMCOMPONENT
#define DEFINITION_DREAMALARMCOMPONENT
#pragma endregion

bool DreamAlarmComponent::Initialize()
{
	_prevTimer = std::make_shared<DreamTimerComponet>("prevTimer");
	_afterTimer = std::make_shared<DreamTimerComponet>("afterTimer");
	_duration = std::make_shared<DreamStopWatchComponent>("duration");
	bool reverseResult = false;
	reverseResult |= !dream::base::DreamComponentBase::Initialize();
	if (_prevTimer->IsAlive() == false)
		reverseResult |= !_prevTimer->Initialize();
	if (_afterTimer->IsAlive() == false)
		reverseResult |= !_afterTimer->Initialize();
	if (_duration->IsAlive() == false)
		reverseResult |= !_duration->Initialize();
	if (!reverseResult == true)
		Alive();
	return !reverseResult;
}

bool DreamAlarmComponent::Release()
{
	bool reverseResult = false;
	if (_prevTimer != nullptr)
	{
		bool release_clear = true;
		if (_prevTimer->IsAlive() == true)
		{
			if (_prevTimer->Release() == true)
				_prevTimer->Kill();
			else
				release_clear = false;
		}
		if (release_clear == true)
		{
			_prevTimer.reset();
			_prevTimer = nullptr;
		}
		reverseResult |= release_clear;
	}
	if (_afterTimer != nullptr)
	{
		bool release_clear = true;
		if (_afterTimer->IsAlive() == true)
		{
			if (_afterTimer->Release() == true)
				_afterTimer->Kill();
			else
				release_clear = false;
		}
		if (release_clear == true)
		{
			_afterTimer.reset();
			_afterTimer = nullptr;
		}
		reverseResult |= release_clear;
	}
	if (_duration != nullptr)
	{
		bool release_clear = true;
		if (_duration->IsAlive() == true)
		{
			if (_duration->Release() == true)
				_duration->Kill();
			else
				release_clear = false;
		}
		if (release_clear == true)
		{
			_duration.reset();
			_duration = nullptr;
		}
		reverseResult |= release_clear;
	}
	for (auto& item : _logList)
	{
		item.second.reset();
		item.second = nullptr;
	}
	_logList.clear();

	reverseResult |= !dream::base::DreamComponentBase::Release();
	if (!reverseResult == true)
		Kill();
	return !reverseResult;
}

std::shared_ptr<dream::base::DreamObjectBase> DreamAlarmComponent::Clone_ToObject() const
{
	return std::make_shared<DreamAlarmComponent>(*this);
}

std::shared_ptr<DreamAlarmComponent> DreamAlarmComponent::Clone()
{
	return std::dynamic_pointer_cast<DreamAlarmComponent>(Clone_ToObject());
}

void DreamAlarmComponent::PrevTime(std::chrono::milliseconds interval)
{
	if (IsAlive() == false)
		return;
	_prevTimer->Interval(interval);
}

std::chrono::milliseconds DreamAlarmComponent::PrevTime() const
{
	if (IsAlive() == false)
		return std::chrono::milliseconds(0);
	return _prevTimer->Interval();
}

void DreamAlarmComponent::AfterTime(std::chrono::milliseconds interval)
{
	if (IsAlive() == false)
		return;
	_afterTimer->Interval(interval);
}

std::chrono::milliseconds DreamAlarmComponent::AfterTime() const
{
	if (IsAlive() == false)
		return std::chrono::milliseconds(0);
	return _afterTimer->Interval();
}

std::chrono::milliseconds DreamAlarmComponent::LastRaiseDuration() const
{

	if (IsAlive() == false)
		return std::chrono::milliseconds(0);
	return _duration->GetDuration_toMilliseconds();
}

void DreamAlarmComponent::AddLog(std::string name, std::shared_ptr<DreamLogComponet> log)
{
	std::lock_guard<std::mutex> lock(_logListMutex);
	if (log == nullptr)
		return;
	if (_logList.contains(name) != 0)
		return;
	_logList.insert(std::make_pair(name, log));
}

void DreamAlarmComponent::DelLog(std::string name)
{
	std::lock_guard<std::mutex> lock(_logListMutex);
	if (_logList.contains(name) == 0)
		return;
	_logList.erase(name);
}

void DreamAlarmComponent::ConditionFunc(std::function<bool()> conditionFunc)
{
	_conditionFunc = conditionFunc;
}

bool DreamAlarmComponent::IsRaising()
{
	if (IsAlive() == false)
		return false;
	if (_conditionFunc == nullptr)
		return false;
	bool currentRaise = _conditionFunc();
	bool isChangeRaise = _lastRaise.Get() == currentRaise;
	_lastRaise.Set(currentRaise); // 변화 갱신

	// 변화 유무에 따른 타이머 설정
	if (isChangeRaise == true) // 변화 O
	{
		if (currentRaise == true) // Raise 켜짐
		{
			if (_prevTimer->RunTime() == false)
			{
				_prevTimer->Start();
			}
			if (_afterTimer->RunTime() == true)
			{
				_afterTimer->End();
			}
			
		}
		else // Raise 꺼짐
		{
			if (_prevTimer->RunTime() == true)
			{
				_prevTimer->End();
			}
			if (_afterTimer->RunTime() == false)
			{
				_afterTimer->Start();
			}
		}
	}
	// 각 상황별에 따른 결과
	if (currentRaise == true) // Raise 켜짐
	{
		// 인터벌이 설정 되어있다.
		if (_prevTimer->Interval() != std::chrono::milliseconds(0))
		{
			if (_prevTimer->IsOver() == true)
			{
				if (_duration->RunTime() == false)
				{
					_duration->Start();
					for (auto& item : _logList)
					{
						item.second->AddLog("알람 켜짐");
					}
				}
				
				return true; // 기간 만료가 되었습니다. 발생이 확실합니다.
			}
			else
			{
				return false; // 기간 만료가 되지 않았습니다.
			}
		}
		else // 없다.
		{
			if (_duration->RunTime() == false)
			{
				_duration->Start();
				for (auto& item : _logList)
				{
					item.second->AddLog("알람 켜짐");
				}
			}
			return true; // 발생이 확실합니다.
		}
	}
	else // Raise 꺼짐
	{
		if (_afterTimer->Interval() != std::chrono::milliseconds(0))
		{
			if (_afterTimer->IsOver() == true)
			{
				if (_duration->RunTime() == true)
				{
					_duration->End();
					auto durationString = std::to_string(_duration->GetDuration_toMilliseconds().count());
					for (auto& item : _logList)
					{
						item.second->AddLog("알람기간 : " + durationString + "(ms)");
						item.second->AddLog("알람 꺼짐");
					}
				}
				return false; // 기간 만료가 되었습니다.  발생 종료가 확실합니다.
			}
			else
			{
				return true; // 기간 만료가 되지 않았습니다.
			}
		}
		else // 없다.
		{
			if (_duration->RunTime() == true)
			{
				_duration->End();
				auto durationString = std::to_string(_duration->GetDuration_toMilliseconds().count());
				for (auto& item : _logList)
				{
					item.second->AddLog("알람기간 : " + durationString + "(ms)");
					item.second->AddLog("알람 꺼짐");
				}
			}
			return false; // 발생이 종료 되었습니다.
		}
	}
	// 진입이 불가능하지만 만약 진입한다면 이전값으로...
	return _lastRaise.Get();
}

DreamAlarmComponent::DreamAlarmComponent(const std::string& name, const std::string& classType)
	: DreamComponentBase(name, classType)
{
}

DreamAlarmComponent::DreamAlarmComponent(const DreamAlarmComponent& other)
	: DreamComponentBase(other)
{
	_level.Set(other._level.Get());
	_conditionFunc = other._conditionFunc;
	// 나머지 것들은 클론으로 새롭게 제공받는다.
	if (other._prevTimer != nullptr)
		_prevTimer = other._prevTimer->Clone();
	if (other._afterTimer != nullptr)
		_afterTimer = other._afterTimer->Clone();
	if (other._duration != nullptr)
		_duration = other._duration->Clone();
	_logList.clear();
	for (auto& item : other._logList)
		_logList.insert(item);
}


#pragma region Avoid duplication
#endif // !DEFINITION_DREAMALARMCOMPONENT
#pragma endregion
#pragma region Namesapce
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion
