#pragma once
#pragma region Include
#include <string>
#include <mutex>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamMutexValue.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::object_frame {
#else
namespace dream { namespace object_frame {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_OBJECTBASE
#define DECLARATION_OBJECTBASE
#pragma endregion

/// <summary> 오브젝트의 최소 기능 </summary>
class DREAM_API ObjectBase
{
public:
	virtual _NODISCARD const std::string Name() const final;
	virtual void Name(const std::string name) final;
	virtual _NODISCARD const std::string ClassType() const final;
	virtual _NODISCARD const bool IsAlive() const final;
	virtual void Kill() final;
protected:
	virtual _NODISCARD void Alive() final;
protected:
	virtual _NODISCARD std::shared_ptr<ObjectBase> Clone_ToObject() const;
public:
	_NODISCARD std::shared_ptr<ObjectBase> Clone();
public:
	ObjectBase(const std::string& name, const std::string& classType = "ObjectBase");
	virtual ~ObjectBase() = default;
	ObjectBase(const ObjectBase& other);
private:
	MutexValue<std::string> _name = "";
	MutexValue<std::string> _classType = "";
	MutexValue<bool> _alive = false;
};

#pragma region Avoid duplication
#endif // !DECLARATION_OBJECTBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion