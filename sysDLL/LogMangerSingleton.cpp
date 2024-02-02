#include "LogMangerSingleton.h"
#include "Log.h"

std::shared_ptr<ILog> LogMangerSingleton::CreateItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_logDicMutex);
    auto findIter = _logDic.find(name);
    if (findIter != _logDic.end())
        return findIter->second;
    auto tempLog = std::make_shared<Log>();
    tempLog->Name(name);
    _logDic.insert(std::make_pair(name, tempLog));
    return tempLog;
}

const bool LogMangerSingleton::DeleteItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_logDicMutex);
    auto findIter = _logDic.find(name);
    if (findIter == _logDic.end())
        return false; // find key item none.
    _logDic.erase(name);
    return true;
}

std::shared_ptr<ILog> LogMangerSingleton::GetItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_logDicMutex);
    auto findIter = _logDic.find(name);
    if (findIter == _logDic.end())
        return nullptr;
    return findIter->second;
}

const std::wstring LogMangerSingleton::GetELogLeveltoString(const ELogLevel logLevel)
{
    switch (logLevel)
    {
    case ELogLevel::None:
        return L"None";
    case ELogLevel::Trace:
        return L"Trace";
    case ELogLevel::Debug:
        return L"Debug";
    case ELogLevel::Log:
        return L"Log";
    case ELogLevel::Info:
        return L"Info";
    case ELogLevel::Warning:
        return L"Warning";
    case ELogLevel::Error:
        return L"Error";
    case ELogLevel::Fatal:
        return L"Fatal";
    default:
        return L"Unknown";
    }
}
