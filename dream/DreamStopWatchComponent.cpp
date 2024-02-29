#include "DreamStopWatchComponent.h"
namespace dream::componet
{
#ifndef DEFINITION_DREAMSTOPWATCHCOMPONENT
#define DEFINITION_DREAMSTOPWATCHCOMPONENT

	bool DreamStopWatchComponent::Initialize()
	{
		bool result = dream::base::DreamComponentBase::Initialize();
		if (result == true)
			Alive();
		return result;
	}

	bool DreamStopWatchComponent::Release()
	{
		bool result = dream::base::DreamComponentBase::Release();
		if (result == true)
			Kill();
		return result;
	}

	std::shared_ptr<base::DreamObjectBase> DreamStopWatchComponent::Clone_ToObject() const
	{
		return std::make_shared<DreamStopWatchComponent>(*this);
	}

	std::shared_ptr<DreamStopWatchComponent> DreamStopWatchComponent::Clone()
	{
		return std::dynamic_pointer_cast<DreamStopWatchComponent>(Clone_ToObject());
	}

	DreamStopWatchComponent::DreamStopWatchComponent(const std::string& name, const std::string& classType)
		: DreamComponentBase(name, classType)
	{
	}

	DreamStopWatchComponent::DreamStopWatchComponent(const DreamStopWatchComponent& other)
		: DreamComponentBase(other)
	{
	}

#endif 	// !DEFINITION_DREAMSTOPWATCHCOMPONENT
}