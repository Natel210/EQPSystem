#pragma once
#pragma region Include
#include <chrono>
#include <functional>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamMutexValue.h"
#include "dream/base/DreamComponentBase.h"
#include "dream/component/DreamTimerComponet.h"
#include "dream/component/DreamStopWatchComponent.h"
#include "dream/component/DreamLogComponet.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream {
	namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMALARMCOMPONENT
#define DECLARATION_DREAMALARMCOMPONENT
#pragma endregion

class DREAM_API DreamAlarmComponent : public base::DreamComponentBase
{
public:
	bool Initialize() final;
	bool Release() final;
protected:
	_NODISCARD std::shared_ptr<dream::base::DreamObjectBase> Clone_ToObject() const override;
public:
	_NODISCARD std::shared_ptr<DreamAlarmComponent> Clone();
public:
	/// <summary> Inactive timer if parameter is set to 0s or none. </summary>
	void PrevTime(std::chrono::milliseconds interval = std::chrono::milliseconds(0)) ;
	std::chrono::milliseconds PrevTime() const;
	/// <summary> Inactive timer if parameter is set to 0s or none. </summary>
	void AfterTime(std::chrono::milliseconds interval = std::chrono::milliseconds(0));
	std::chrono::milliseconds AfterTime() const;
	std::chrono::milliseconds LastRaiseDuration() const;
public:
	void AddLog(std::string name, std::shared_ptr<DreamLogComponet> log);
	void DelLog(std::string name);

public:
	void ConditionFunc(std::function<bool()> conditionFunc);
public:
	_NODISCARD bool IsRaising();
public:
	DreamAlarmComponent(const std::string& name, const std::string& classType = "DreamAlarmComponent");
	virtual ~DreamAlarmComponent() = default;
	DreamAlarmComponent(const DreamAlarmComponent& other);

private:
	MutexValue<std::string> _level = "";
	std::function<bool()> _conditionFunc = nullptr;
	MutexValue<bool> _lastRaise = false;
	std::shared_ptr<DreamTimerComponet> _prevTimer = nullptr;
	std::shared_ptr<DreamTimerComponet> _afterTimer = nullptr;
	std::shared_ptr<DreamStopWatchComponent> _duration = nullptr;
	std::unordered_map<std::string, std::shared_ptr<DreamLogComponet>> _logList;
	mutable std::mutex _logListMutex;
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMALARMCOMPONENT
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
	}
#else
}}
#endif // _HAS_CXX17
#pragma endregion