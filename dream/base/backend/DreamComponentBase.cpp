#include "dream/base/DreamComponentBase.h"
namespace dream::base
{
#ifndef DEFINITION_DREAMCOMPONENTBASE
#define DEFINITION_DREAMCOMPONENTBASE

	bool DreamComponentBase::Initialize()
	{
		return true;
	}

	bool DreamComponentBase::Release()
	{
		return true;
	}

	std::shared_ptr<DreamObjectBase> DreamComponentBase::Clone_ToObject() const
	{
		return std::make_shared<DreamComponentBase>(*this);
	}

	std::shared_ptr<DreamComponentBase> DreamComponentBase::Clone()
	{
		return std::dynamic_pointer_cast<DreamComponentBase>(Clone_ToObject());
	}

	void DreamComponentBase::PrevUpdate()
	{
	}

	void DreamComponentBase::Update()
	{
	}

	void DreamComponentBase::AfterUpdate()
	{
	}

	void DreamComponentBase::Trans_PrevUpdate()
	{
	}

	void DreamComponentBase::Trans()
	{
	}

	void DreamComponentBase::Trans_AfterUpdate()
	{
	}

	void DreamComponentBase::Collision_PrevUpdate()
	{
	}

	void DreamComponentBase::Collision()
	{
	}

	void DreamComponentBase::Collision_AfterUpdate()
	{
	}

	void DreamComponentBase::Render_PrevUpdate()
	{
	}

	void DreamComponentBase::Render()
	{
	}

	void DreamComponentBase::Render_AfterUpdate()
	{
	}

	DreamComponentBase::DreamComponentBase(const std::string& name, const std::string& classType)
		: DreamObjectBase(name,classType)
	{
	}

	DreamComponentBase::DreamComponentBase(const DreamComponentBase& other)
		: DreamObjectBase(other)
	{
	}

#endif // !DEFINITION_DREAMCOMPONENTBASE
}

