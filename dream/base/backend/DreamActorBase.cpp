#include "dream/base/DreamActorBase.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::base {
#else
namespace dream { namespace base {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMACTORBASE
#define DEFINITION_DREAMACTORBASE
#pragma endregion

bool DreamActorBase::Initialize()
{
	bool reverseCheck = false;
	for (auto item : _componentList)
		reverseCheck |= !item.second->Initialize();
	reverseCheck |= !ObjectBase::Initialize();
	if (!reverseCheck == true)
		Alive();
	return !reverseCheck;
}

bool DreamActorBase::Release()
{
	bool reverseCheck = false;
	for (auto item : _componentList)
		reverseCheck |= !item.second->Release();
	reverseCheck |= !ObjectBase::Release();
	if (!reverseCheck == true)
		Kill();
	return !reverseCheck;
}

std::shared_ptr<ObjectBase> DreamActorBase::Clone_ToObject() const
{
	return std::make_shared<DreamActorBase>(*this);
}

std::shared_ptr<DreamActorBase> DreamActorBase::Clone()
{
	return std::dynamic_pointer_cast<DreamActorBase>(Clone_ToObject());
}

void DreamActorBase::PrevUpdate()
{
}

void DreamActorBase::Update()
{
}

void DreamActorBase::AfterUpdate()
{
}

void DreamActorBase::Trans_PrevUpdate()
{
}

void DreamActorBase::Trans()
{
}

void DreamActorBase::Trans_AfterUpdate()
{
}

void DreamActorBase::Collision_PrevUpdate()
{
}

void DreamActorBase::Collision()
{
}

void DreamActorBase::Collision_AfterUpdate()
{
}

void DreamActorBase::Render_PrevUpdate()
{
}

void DreamActorBase::Render()
{
}

void DreamActorBase::Render_AfterUpdate()
{
}

void DreamActorBase::Progress_PrevUpdate()
{
	if (IsAlive() == false)
		return;
	PrevUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->PrevUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Update()
{
	if (IsAlive() == false)
		return;
	Update();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Update();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_AfterUpdate()
{
	if (IsAlive() == false)
		return;
	AfterUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->AfterUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Trans_PrevUpdate()
{
	if (IsAlive() == false)
		return;
	Trans_PrevUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Trans_PrevUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Trans()
{
	if (IsAlive() == false)
		return;
	Trans();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Trans();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Trans_AfterUpdate()
{
	if (IsAlive() == false)
		return;
	Trans_AfterUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Trans_AfterUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Collision_PrevUpdate()
{
	if (IsAlive() == false)
		return;
	Collision_PrevUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Collision_PrevUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Collision()
{
	if (IsAlive() == false)
		return;
	Collision();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Collision();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Collision_AfterUpdate()
{
	if (IsAlive() == false)
		return;
	Collision_AfterUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Collision_AfterUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Render_PrevUpdate()
{
	if (IsAlive() == false)
		return;
	Render_PrevUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Render_PrevUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Render()
{
	if (IsAlive() == false)
		return;
	Render();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Render();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::Progress_Render_AfterUpdate()
{
	if (IsAlive() == false)
		return;
	Render_AfterUpdate();
	CleanupComponent();
	_componentListMutex.lock();
	try
	{
		for (auto item : _componentList)
		{
			auto temp = std::dynamic_pointer_cast<dream::ILogic>(item.second);
			if (temp == nullptr)
				continue;
			temp->Render_AfterUpdate();
		}
	}
	catch (const std::exception&) {}
	_componentListMutex.unlock();
}

void DreamActorBase::AddComponent(std::string name, std::shared_ptr<DreamComponentBase>component)
{
	std::lock_guard<std::mutex> lock(_componentListMutex);
	if (component == nullptr)
		return;
	_componentList.insert(std::make_pair(name, component));
}

bool DreamActorBase::SwapComponent(std::string name, std::shared_ptr<DreamComponentBase> component)
{
	if (component == nullptr)
		return false;
	bool exist = ExistComponent(name);
	try
	{
		_componentListMutex.lock();
		if (exist == true)
			_componentList[name].swap(component);
		else // 이행동은 다음과 같이 볼수있다. nullptr에서 지정된것으로...
			AddComponent(name, component);
		_componentListMutex.unlock();
	}
	catch (const std::exception&)
	{
		_componentListMutex.unlock();
	}
	return true;
}

void DreamActorBase::DelComponent(std::string name)
{
	std::lock_guard<std::mutex> lock(_componentListMutex);
	if (_componentList.find(name) != _componentList.end())
		_componentList.erase(name);
}

void DreamActorBase::ClearComponent()
{
	std::lock_guard<std::mutex> lock(_componentListMutex);
	_componentList.clear();
}

bool DreamActorBase::ExistComponent(std::string name) const
{
	std::lock_guard<std::mutex> lock(_componentListMutex);
	auto count = _componentList.count(name);
	if (count != 0)
		return true;
	else
		return false;
}

std::shared_ptr<DreamComponentBase> DreamActorBase::GetComponent(std::string name)
{
	if (ExistComponent(name) == false)
		return nullptr;
	_componentListMutex.lock();
	auto tempComponent = _componentList.at(name);
	_componentListMutex.unlock();
	return tempComponent;
}

std::shared_ptr<DreamComponentBase> DreamActorBase::GetComponent(std::string name) const
{
	if (ExistComponent(name) == false)
		return nullptr;
	_componentListMutex.lock();
	auto tempComponent = _componentList.at(name);
	_componentListMutex.unlock();
	return tempComponent;
}

void DreamActorBase::CleanupComponent()
{
	std::lock_guard<std::mutex> lock(_componentListMutex);
	std::vector<std::string> deadNameList;
	for (auto item : _componentList)
	{
		if (item.second == nullptr)
		{
			deadNameList.push_back(item.first);
			continue;
		}
		if (item.second->IsAlive() == false)
		{
			deadNameList.push_back(item.first);
			continue;
		}
	}

	for (auto item : deadNameList)
		_componentList.erase(item);
}

DreamActorBase::DreamActorBase(const std::string& name, const std::string& classType)
	: ObjectBase(name, classType)
{
}

DreamActorBase::DreamActorBase(const DreamActorBase& other)
	: ObjectBase(other)
{

}

#pragma region Avoid duplication
#endif // !DEFINITION_DREAMACTORBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion