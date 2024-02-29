#include "dream/base/DreamObjectBase.h"
namespace dream::base
{
#ifndef DEFINITION_DREAMOBJECTBASE
#define DEFINITION_DREAMOBJECTBASE

	const std::string DreamObjectBase::Name() const
	{
		std::lock_guard<std::mutex> lock(_nameMutex);
		return _name;
	}

	const std::string DreamObjectBase::ClassType() const
	{
		std::lock_guard<std::mutex> lock(_classTypeMutex);
		return _classType;
	}

	const bool DreamObjectBase::IsAlive() const
	{
		std::lock_guard<std::mutex> lock(_aliveMutex);
		return _alive;
	}

	void DreamObjectBase::Kill()
	{
		std::lock_guard<std::mutex> lock(_aliveMutex);
		_alive = false;
	}

	void DreamObjectBase::Alive()
	{
		std::lock_guard<std::mutex> lock(_aliveMutex);
		_alive = true;
	}

	bool DreamObjectBase::Initialize()
	{
		return true;
	}

	bool DreamObjectBase::Release()
	{
		return true;
	}

	std::shared_ptr<DreamObjectBase> DreamObjectBase::Clone()
	{
		return Clone_ToObject();
	}

	std::shared_ptr<DreamObjectBase> DreamObjectBase::Clone_ToObject() const
	{
		return std::make_shared<DreamObjectBase>(*this);
	}

	DreamObjectBase::DreamObjectBase(const std::string& name, const std::string& classType)
		: _name(name), _classType(classType), _alive(false)
	{
	}

	DreamObjectBase::DreamObjectBase(const DreamObjectBase& other)
		: _name(other.Name()), _classType(other.ClassType()), _alive(other.IsAlive())
	{
	}

#endif // !DEFINITION_DREAMOBJECTBASE
}