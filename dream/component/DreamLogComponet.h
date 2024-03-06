#pragma once
#pragma region Include
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
#ifndef DECLARATION_DREAMLOGCOMPONET
#define DECLARATION_DREAMLOGCOMPONET
#pragma endregion

class DREAM_API DreamLogComponet : public base::DreamComponentBase
{
public:
	bool Initialize() final;
	bool Release() final;
protected:
	_NODISCARD std::shared_ptr<dream::base::DreamObjectBase> Clone_ToObject() const override;
public:
	_NODISCARD std::shared_ptr<DreamLogComponet> Clone();
public:
	virtual void AddLog(const std::string& comment) final;
	virtual void AddLogsRange(const std::vector<std::string>& commentList) final;
	virtual _NODISCARD const std::shared_ptr<const std::vector<std::string>> List() const final;
	virtual void Clear() final;
public: 
	/// <summary> 문자열 포멧에 관해서 변경이 필요할 때 해당 함수 상속 구현 </summary>
	virtual _NODISCARD const std::string Format(const std::string& comment);
public:
	DreamLogComponet(const std::string& name, const std::string& classType = "DreamLogComponet");
	virtual ~DreamLogComponet() = default;
	DreamLogComponet(const DreamLogComponet& other);
private:
	std::vector<std::string> _logList;
	mutable std::mutex _logListMutex;
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMLOGCOMPONET
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion