#pragma once
#include <iostream>
#include <format>
#include <string>
#include <conio.h>

#include "../sysDLL/LogManager.h"

#include <chrono>
#include "../sysDLL/TimeManager.h"

void TestLog()
{
    auto ilog = LogManager::CreateItem(L"test1");
    ilog->Level(ELogLevel::Debug);
    ilog->Add(L"TEST1");
    ilog->Level(ELogLevel::Warning);
    ilog->Add(L"TEST2");
    ilog->Level(ELogLevel::Fatal);
    ilog->AddRange({ L"TEST31",L"TEST32" });



    auto a = ilog->List();
    for (auto item : *a)
    {
        std::wcout << item.c_str() << std::endl;
    }

    std::cout << "===============" << std::endl;

    auto b = ilog->Return();
    for (auto item : *b)
    {
        std::wcout << item.c_str() << std::endl;
    }

    std::cout << "===============" << std::endl;

    auto c = ilog->Return();
    for (auto item : *c)
    {
        std::wcout << "get>>" << item.c_str() << std::endl;
    }
    system("pause");
    system("cls");
}


void TestTimeLog()
{
    auto ilog = LogManager::CreateItem(L"test1");
    ilog->Level(ELogLevel::Debug);
    ilog->Add(L"TEST1");
    ilog->Level(ELogLevel::Warning);
    ilog->Add(L"TEST2");
    ilog->Level(ELogLevel::Fatal);
    ilog->AddRange({ L"TEST31",L"TEST32" });



    auto a = ilog->List();
    for (auto item : *a)
    {
        std::wcout << item.c_str() << std::endl;
    }

    std::cout << "===============" << std::endl;

    auto b = ilog->Return();
    for (auto item : *b)
    {
        std::wcout << item.c_str() << std::endl;
    }

    std::cout << "===============" << std::endl;

    auto c = ilog->Return();
    for (auto item : *c)
    {
        std::wcout << "get>>" << item.c_str() << std::endl;
    }

}


void TestCurrentSystemTime()
{
    static std::tm currentTime = TimeManager::GetCurrentSystemTime();

    std::wstring timer1 = L"Timer1_TestCurrentSystemTime1";
    TimeManager::CreateTimer(timer1);
    auto tiemr1 = TimeManager::GetTimer(timer1);
    tiemr1->Start();
    bool run = true;
    while (run)
    {
        if(_kbhit() != 0)
        {
            auto inputKey = _getch();
            if (inputKey == 'X' || inputKey == 'x')
                run = false;
        }
        // 현재 시간
        auto tm = TimeManager::GetCurrentSystemTime();
        if (currentTime.tm_year != tm.tm_year || currentTime.tm_mon != tm.tm_mon || currentTime.tm_mday != tm.tm_mday
            || currentTime.tm_hour != tm.tm_hour|| currentTime.tm_min!= tm.tm_min|| currentTime.tm_sec != tm.tm_sec)
        {
            currentTime = tm;

            system("cls");

            auto formatString = std::format(L"현재시간 : {}_{}_{} {}:{}:{}", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                tm.tm_hour, tm.tm_min, tm.tm_sec);
            std::wcout << formatString << std::endl;

            {
                std::wcout << L"년 : " << tiemr1->DurationSince_Year() << std::endl;
                std::wcout << L"월 : " << tiemr1->DurationSince_Month() << std::endl;
                std::wcout << L"일 : " << tiemr1->DurationSince_Day() << std::endl;
                std::wcout << L"시 : " << tiemr1->DurationSince_Hour() << std::endl;
                std::wcout << L"분 : " << tiemr1->DurationSince_Minute() << std::endl;
                std::wcout << L"초 : " << tiemr1->DurationSince_Seconds() << std::endl;
                std::wcout << L"밀리초 : " << tiemr1->DurationSince_Milliseconds() << std::endl;
            }
        }
        
    }
}

void TestTimer()
{
    auto tm = TimeManager::GetCurrentSystemTime();
    auto formatString = std::format(L"{}_{}_{} {}:{}:{}", tm.tm_year + 1900 , tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec);
    std::wcout << formatString << std::endl;

    auto nowTime = std::chrono::steady_clock::now();
    
    std::wstring stopWatchString1 = L"StopWatch1_TestTimer1";
    std::wstring timerString1 = L"Timer1_TestTimer1";

    TimeManager::CreateStopWatch(stopWatchString1);
    TimeManager::CreateTimer(timerString1);

    auto StopWatch1 = TimeManager::GetStopWatch(stopWatchString1);
    auto tiemr1 = TimeManager::GetTimer(timerString1);
    tiemr1->Start(nowTime);
    StopWatch1->Interval(std::chrono::milliseconds(1000));
    StopWatch1->Start(nowTime);

    int count = 0;

    while (count < 100)
    {
        if (StopWatch1->IsOver() == true)
        {
            StopWatch1->Start();
            std::wcout << tiemr1->DurationSince_Milliseconds() << std::endl;
            ++count;
        }
    }

    auto tm2 = TimeManager::GetCurrentSystemTime();
    auto formatString2 = std::format(L"{}_{}_{}_{}:{}:{}", tm2.tm_year + 1900, tm2.tm_mon, tm2.tm_mday,
        tm2.tm_hour, tm2.tm_min, tm2.tm_sec);
    std::wcout << formatString2 << std::endl;


    system("pause");
    system("cls");

}