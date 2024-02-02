#include "TimeManager.h"
#include <chrono>
#include "TimerManagerSingleton.h"
#include "StopWatchMangerSingleton.h"


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
    // ���� �ý��� �ð��� ����ϴ�.
    auto now = std::chrono::system_clock::now();

    // �ð��� time_t Ÿ������ ��ȯ�մϴ�.
    auto now_c = std::chrono::system_clock::to_time_t(now);

    // ��ȯ�� �ð��� tm ����ü�� ��ȯ�մϴ�.
    return *std::localtime(&now_c);

}