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
    // 현재 시스템 시간을 얻습니다.
    auto now = std::chrono::system_clock::now();

    // 시간을 time_t 타입으로 변환합니다.
    auto now_c = std::chrono::system_clock::to_time_t(now);

    // 변환된 시간을 tm 구조체로 변환합니다.
    struct tm timeinfo;
    time_t rawtime;
    time(&rawtime);
    if (localtime_s(&timeinfo, &rawtime) == false)
        return timeinfo;
    return std::tm();
}
