#include "dream/actor/DreamLogActor.h"
namespace dream::actor
{
#ifndef DEFINITION_DREAMLOGACTOR
#define DEFINITION_DREAMLOGACTOR
	
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

	std::shared_ptr<base::DreamObjectBase> DreamLogActor::Clone_ToObject() const
	{
		return std::make_shared<DreamLogActor>(*this);
	}

	std::shared_ptr<DreamLogActor> DreamLogActor::Clone()
	{
		return std::dynamic_pointer_cast<DreamLogActor>(Clone_ToObject());
	}

	bool DreamLogActor::LogComponent(std::shared_ptr<componet::DreamLogComponet> component)
	{
		return SwapComponent(_logComponentName, component);
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

#endif // !DEFINITION_DREAMLOGACTOR
}