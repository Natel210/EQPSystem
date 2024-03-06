#include "dream/object_frame/DreamObjectBase.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::object_frame {
#else
namespace dream { namespace object_frame {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_OBJECTBASE
#define DEFINITION_OBJECTBASE
#pragma endregion

const std::string ObjectBase::Name() const
{
	return _name.Get();
}

void ObjectBase::Name(const std::string name)
{
	_name.Set(name);
}

const std::string ObjectBase::ClassType() const
{
	return _classType.Get();
}

const bool ObjectBase::IsAlive() const
{
	return _alive.Get();
}

void ObjectBase::Kill()
{
	_alive.Set(false);
}

void ObjectBase::Alive()
{
	_alive.Set(true);
}

std::shared_ptr<ObjectBase> ObjectBase::Clone()
{
	return Clone_ToObject();
}

std::shared_ptr<ObjectBase> ObjectBase::Clone_ToObject() const
{
	return std::make_shared<ObjectBase>(*this);
}

ObjectBase::ObjectBase(const std::string& name, const std::string& classType)
	: _name(name), _classType(classType), _alive(false)
{
	Alive();
}

ObjectBase::ObjectBase(const ObjectBase& other)
	: _name(other.Name()), _classType(other.ClassType()), _alive(other.IsAlive())
{
	Alive(); // 복제를 한다면 새로운 생명체이기 떄문에...
}

#pragma region Avoid duplication
#endif // !DEFINITION_OBJECTBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion