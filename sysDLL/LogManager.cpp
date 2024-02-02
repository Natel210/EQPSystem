#include "LogManager.h"
#include "ILog.h"
#include "LogMangerSingleton.h"

std::shared_ptr<ILog> LogManager::CreateItem(const std::wstring name)
{
    return LogMangerSingleton::Instance().CreateItem(name);
}

const bool LogManager::DeleteItem(const std::wstring name)
{
    return LogMangerSingleton::Instance().DeleteItem(name);
}

std::shared_ptr<ILog> LogManager::GetItem(const std::wstring name)
{
    return LogMangerSingleton::Instance().GetItem(name);
}
