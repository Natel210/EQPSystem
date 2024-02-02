#pragma once
#include <mutex>
#include <string>
#include <memory>
#include <unordered_map>
#include "ILog.h"
#include "IItemManagerBase.h"
#include "SingletonTemplate.h"

class LogMangerSingleton : public SingletonTemplate<LogMangerSingleton>, public IItemManagerBase<ILog>
{
#pragma region interface
public:
	std::shared_ptr<ILog> CreateItem(const std::wstring& name) final;
	const bool DeleteItem(const std::wstring& name) final;
	std::shared_ptr<ILog> GetItem(const std::wstring& name) final;
#pragma endregion
public:
	static const std::wstring GetELogLeveltoString(const ELogLevel logLevel);
private:
	std::unordered_map <std::wstring, std::shared_ptr<ILog>> _itemDic;
	std::mutex _itemDicMutex;
};