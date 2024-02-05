#include "TimeManager.h"
#include <chrono>
#include "TimerManagerSingleton.h"
#include "StopWatchMangerSingleton.h"
#include <time.h>

std::shared_ptr<ITimer> TimeManager::CreateTimer(const std::wstring name)
{
    return TimerManagerSingleton::Instance().CreateItem(name);
}

const bool TimeManager::DeleteTimer(const std::wstring name)
{
    return TimerManagerSingleton::Instance().DeleteItem(name);
}

std::shared_ptr<ITimer> TimeManager::GetTimer(const std::wstring name)
{
    return TimerManagerSingleton::Instance().GetItem(name);
}

std::shared_ptr<IStopWatch> TimeManager::CreateStopWatch(const std::wstring name)
{
    return StopWatchMangerSingleton::Instance().CreateItem(name);
}

const bool TimeManager::DeleteStopWatch(const std::wstring name)
{
    return StopWatchMangerSingleton::Instance().DeleteItem(name);
}

std::shared_ptr<IStopWatch> TimeManager::GetStopWatch(const std::wstring name)
{
    return StopWatchMangerSingleton::Instance().GetItem(name);
}

std::tm TimeManager::GetCurrentSystemTime()
{
    struct tm timeinfo;
    time_t rawtime;
    time(&rawtime);
    if (localtime_s(&timeinfo, &rawtime) == false)
        return timeinfo;
    return std::tm();
}
