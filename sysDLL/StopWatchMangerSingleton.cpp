#include "StopWatchMangerSingleton.h"
#include "StopWatch.h"

std::shared_ptr<IStopWatch> StopWatchMangerSingleton::CreateItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter != _itemDic.end())
        return findIter->second;
    auto tempLog = std::make_shared<StopWatch>();
    tempLog->Name(name);
    _itemDic.insert(std::make_pair(name, tempLog));
    return tempLog;
}

const bool StopWatchMangerSingleton::DeleteItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter == _itemDic.end())
        return false; // find key item none.
    _itemDic.erase(name);
    return true;
}

std::shared_ptr<IStopWatch> StopWatchMangerSingleton::GetItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter == _itemDic.end())
        return nullptr;
    return findIter->second;
}
