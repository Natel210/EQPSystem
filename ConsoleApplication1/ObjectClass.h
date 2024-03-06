#pragma once
#include <string>
#include <memory>
#include "MutexValue.h"

class ObjectClass
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
	virtual _NODISCARD std::shared_ptr<ObjectClass> Clone_ToRootClass() const;
public:
	_NODISCARD std::shared_ptr<ObjectClass> Clone();
public:
	ObjectClass(const std::string& name, const std::string& classType = "ObjectBase");
	virtual ~ObjectClass() = default;
	ObjectClass(const ObjectClass& other);
private:
	MutexValue<std::string> _name = "";
	MutexValue<std::string> _classType = "";
	MutexValue<bool> _alive = false;
};