#include "TimerManagerSingleton.h"
#include "Timer.h"

std::shared_ptr<ITimer> TimerManagerSingleton::CreateItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter != _itemDic.end())
        return findIter->second;
    auto tempLog = std::make_shared<Timer>();
    tempLog->Name(name);
    _itemDic.insert(std::make_pair(name, tempLog));
    return tempLog;
}

const bool TimerManagerSingleton::DeleteItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter == _itemDic.end())
        return false; // find key item none.
    _itemDic.erase(name);
    return true;
}

std::shared_ptr<ITimer> TimerManagerSingleton::GetItem(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_itemDicMutex);
    auto findIter = _itemDic.find(name);
    if (findIter == _itemDic.end())
        return nullptr;
    return findIter->second;
}
