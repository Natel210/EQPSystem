#pragma once
#include <string>
#include <memory>
#include "ILog.h"
#include "CoreEntryDefine.h"

class DLL_API LogManager
{
public:
	static std::shared_ptr<ILog> CreateItem(const std::wstring name);
	static const bool DeleteItem(const std::wstring name);
	static std::shared_ptr<ILog> GetItem(const std::wstring name);
};

