#pragma once
#pragma region Include
#include <chrono>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamMutexValue.h"
#include "dream/base/DreamComponentBase.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMSTOPWATCHCOMPONENT
#define DECLARATION_DREAMSTOPWATCHCOMPONENT
#pragma endregion

class DREAM_API DreamStopWatchComponent : public base::DreamComponentBase
{
public:
	bool Initialize() final;
	bool Release() final;
protected:
	_NODISCARD std::shared_ptr<dream::base::DreamObjectBase> Clone_ToObject() const override;
public:
	_NODISCARD std::shared_ptr<DreamStopWatchComponent> Clone();
public:
	virtual _NODISCARD const bool RunTime() const final;
	virtual _NODISCARD const std::chrono::steady_clock::time_point StartTime() const final;
public:
	virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	virtual void End() final;
#if _HAS_CXX20
public:
	virtual _NODISCARD std::chrono::years GetDuration_toYears(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::months GetDuration_toMonths(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::weeks GetDuration_toWeeks(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::days GetDuration_toDay(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
#endif // _HAS_CXX20
	virtual _NODISCARD std::chrono::hours GetDuration_toHours(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::minutes GetDuration_toMinutes(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::seconds GetDuration_toSeconds(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
	virtual _NODISCARD std::chrono::milliseconds GetDuration_toMilliseconds(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) final;
private:
	virtual std::chrono::milliseconds GetDuration(std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now()) const final;
public:
	DreamStopWatchComponent(const std::string& name, const std::string& classType = "DreamStopWatchComponent");
	virtual ~DreamStopWatchComponent() = default;
	DreamStopWatchComponent(const DreamStopWatchComponent& other);
private:
	MutexValue<bool> _runTime = false;
	MutexValue<std::chrono::steady_clock::time_point> _startTime;
	MutexValue<std::chrono::steady_clock::time_point> _lastTime;
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMSTOPWATCHCOMPONENT
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion