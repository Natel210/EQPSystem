#include "dream/actor/DreamLogActor.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::actor {
#else
namespace dream { namespace actor {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMLOGACTOR
#define DEFINITION_DREAMLOGACTOR
#pragma endregion
	
#if _HAS_CXX17
#else
const char* DreamLogActor::_logComponentName = "logComponent";
#endif //_HAS_CXX17

bool DreamLogActor::Initialize()
{
	bool result = base::DreamActorBase::Initialize();
	if (result == true)
		Alive();
	return result;
}

bool DreamLogActor::Release()
{
	bool result = base::DreamActorBase::Release();
	if (result == true)
		Kill();
	return result;
}

std::shared_ptr<base::ObjectBase> DreamLogActor::Clone_ToObject() const
{
	return std::make_shared<DreamLogActor>(*this);
}

std::shared_ptr<DreamLogActor> DreamLogActor::Clone()
{
	return std::dynamic_pointer_cast<DreamLogActor>(Clone_ToObject());
}

bool DreamLogActor::LogComponent(std::shared_ptr<componet::DreamLogComponet> component)
{
	auto tempComponent = component;
	if (tempComponent == nullptr)
		tempComponent = std::make_shared<componet::DreamLogComponet>(_logComponentName);
	return SwapComponent(_logComponentName, tempComponent);
}

std::shared_ptr<componet::DreamLogComponet> DreamLogActor::LogComponent()
{
	return std::dynamic_pointer_cast<componet::DreamLogComponet>(GetComponent(_logComponentName));
}

std::shared_ptr<componet::DreamLogComponet> DreamLogActor::LogComponent() const
{
	return std::dynamic_pointer_cast<componet::DreamLogComponet>(GetComponent(_logComponentName));
}

DreamLogActor::DreamLogActor(const std::string& name, const std::string& classType)
	: DreamActorBase(name, classType)
{
	AddComponent(_logComponentName, std::make_shared<componet::DreamLogComponet>(_logComponentName));
}

DreamLogActor::DreamLogActor(const DreamLogActor& other)
	: DreamActorBase(other)
{
	LogComponent(other.LogComponent()->Clone());
}

#pragma region Avoid duplication
#endif // !DEFINITION_DREAMLOGACTOR
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion