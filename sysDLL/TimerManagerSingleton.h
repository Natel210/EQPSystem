#pragma once
#include <mutex>
#include <string>
#include <memory>
#include <unordered_map>
#include "ITimer.h"
#include "IItemManagerBase.h"
#include "SingletonTemplate.h"

class TimerManagerSingleton : public SingletonTemplate<TimerManagerSingleton>, public IItemManagerBase<ITimer>
{
#pragma region interface
public:
	std::shared_ptr<ITimer> CreateItem(const std::wstring& name) final;
	const bool DeleteItem(const std::wstring& name) final;
	std::shared_ptr<ITimer> GetItem(const std::wstring& name) final;
#pragma endregion
private:
	std::unordered_map <std::wstring, std::shared_ptr<ITimer>> _itemDic;
	std::mutex _itemDicMutex;
};

