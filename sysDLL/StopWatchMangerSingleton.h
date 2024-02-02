#pragma once
#include <mutex>
#include <string>
#include <memory>
#include <unordered_map>
#include "IStopWatch.h"
#include "IItemManagerBase.h"
#include "SingletonTemplate.h"

class StopWatchMangerSingleton : public SingletonTemplate<StopWatchMangerSingleton>, public IItemManagerBase<IStopWatch>
{
#pragma region interface
public:
	std::shared_ptr<IStopWatch> CreateItem(const std::wstring& name) final;
	const bool DeleteItem(const std::wstring& name) final;
	std::shared_ptr<IStopWatch> GetItem(const std::wstring& name) final;
#pragma endregion
private:
	std::unordered_map <std::wstring, std::shared_ptr<IStopWatch>> _itemDic;
	std::mutex _itemDicMutex;
};

