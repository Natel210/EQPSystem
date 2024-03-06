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
#ifndef DECLARATION_DREAMTIMERCOMPONET
#define DECLARATION_DREAMTIMERCOMPONET
#pragma endregion

/// <summary> 특정 기간을 오버했는지 </summary>
class DREAM_API DreamTimerComponet : public base::DreamComponentBase
{
public:
	bool Initialize() final;
	bool Release() final;
protected:
	_NODISCARD std::shared_ptr<dream::base::DreamObjectBase> Clone_ToObject() const override;
public:
	_NODISCARD std::shared_ptr<DreamTimerComponet> Clone();
public:
	virtual _NODISCARD const bool RunTime() const final;
public:
	virtual _NODISCARD const std::chrono::steady_clock::time_point StartTime() const final;
public:
	virtual _NODISCARD const std::chrono::milliseconds Interval() const final;
	virtual void Interval(const std::chrono::milliseconds& interval) final;
	virtual void Interval(const long long& interval) final;
public:
	virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) final;
	virtual void End() final;
	virtual _NODISCARD bool IsOver() final;
	virtual _NODISCARD const std::chrono::milliseconds RemainTime() final;
public:
	DreamTimerComponet(const std::string& name, const std::string& classType = "DreamTimerComponet");
	virtual ~DreamTimerComponet() = default;
	DreamTimerComponet(const DreamTimerComponet& other);
private:
	MutexValue<bool> _runTime = false;
	MutexValue<std::chrono::steady_clock::time_point> _startTime = std::chrono::steady_clock::now();
	MutexValue<std::chrono::milliseconds> _interval = std::chrono::milliseconds(0);
};

#pragma region Avoid duplication
#endif //!DECLARATION_DREAMTIMERCOMPONET
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion