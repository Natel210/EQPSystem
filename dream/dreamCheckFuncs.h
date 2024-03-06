#pragma once
#include <conio.h>
#include <iostream>
#include <cstdint> // std::uintptr_t 정의를 위해 필요
#include <memory>
#include "dream/actor/DreamLogActor.h"
#include "dream/component/DreamIntervalCounterComponent.h"
#include "dream/component/DreamStopWatchComponent.h"
#include "dream/component/DreamTimerComponet.h"
#include "dream/component/DreamAlarmComponent.h"

void CheckCreation()
{
    auto a = std::make_shared<dream::componet::DreamLogComponet>("testLog");
    a->AddLog("TESTS");
    auto b = std::dynamic_pointer_cast<dream::base::DreamObjectBase>(a);

    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    for (auto strings : *(a->List()))
    {
        std::cout << strings << std::endl;
    }
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;

    b->Initialize();

    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;

    auto c = b->Clone();
    auto d = std::dynamic_pointer_cast<dream::componet::DreamLogComponet>(c);


    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << d->Name() << std::endl;
    std::cout << "D 객체 포인터" << reinterpret_cast<std::uintptr_t>(d.get()) << std::endl;
    std::cout << "D 이름 포인터" << reinterpret_cast<std::uintptr_t>(d->Name().c_str()) << std::endl;

    d->AddLog("이건테스트아니다");

    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << d->Name() << std::endl;
    std::cout << "D 객체 포인터" << reinterpret_cast<std::uintptr_t>(d.get()) << std::endl;
    std::cout << "D 이름 포인터" << reinterpret_cast<std::uintptr_t>(d->Name().c_str()) << std::endl;


    d->Release();

    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << d->Name() << std::endl;
    std::cout << "D 객체 포인터" << reinterpret_cast<std::uintptr_t>(d.get()) << std::endl;
    std::cout << "D 이름 포인터" << reinterpret_cast<std::uintptr_t>(d->Name().c_str()) << std::endl;

    b->Release();

    std::cout << "============" << std::endl;
    std::cout << a->Name() << std::endl;
    std::cout << "A 객체 포인터" << reinterpret_cast<std::uintptr_t>(a.get()) << std::endl;
    std::cout << "A 이름 포인터" << reinterpret_cast<std::uintptr_t>(a->Name().c_str()) << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << d->Name() << std::endl;
    std::cout << "D 객체 포인터" << reinterpret_cast<std::uintptr_t>(d.get()) << std::endl;
    std::cout << "D 이름 포인터" << reinterpret_cast<std::uintptr_t>(d->Name().c_str()) << std::endl;

    std::cout << "-생성 및 캐스팅 테스트종료-" << std::endl;
    system("pause");
}

void CheckLog()
{
    auto dreamLogActor = std::make_shared<dream::actor::DreamLogActor>("TestActor");
    auto logCom = dreamLogActor->LogComponent();
    logCom->AddLog("1");
    logCom->AddLog("2");
    logCom->AddLog("가");
    logCom->AddLog("나");
    logCom->AddLog("다");
    logCom->AddLogsRange({ "A","B","C" });
    auto list1 = logCom->List();
    for (auto item : *(list1.get()))
        std::cout << item << std::endl;
    std::cout << "==============" << std::endl;
    logCom->Clear();
    auto list2 = logCom->List();
    for (auto item : *(list1.get()))
        std::cout << item << std::endl;
    std::cout << "---------------" << std::endl;
    for (auto item : *(list2.get()))
        std::cout << item << std::endl;
    std::cout << "==============" << std::endl;

    std::cout << "-로그 테스트종료-" << std::endl;
    system("pause");
}

void CheckIntevalCounter()
{
    auto testIntervalCounterComponent = std::make_shared<dream::componet::DreamIntervalCounterComponent>("testIntervalCounterComponent");
    testIntervalCounterComponent->Start(1000);
    bool running = true;
    int lastCounter = -1;
    while (running)
    {
        if (_kbhit())
        {
            running = false;
        }
        int curCount = testIntervalCounterComponent->Counter();
        if (lastCounter != curCount)
        {
            system("cls");
            std::cout << curCount << std::endl;
            lastCounter = curCount;
        }
    }

    std::cout << "-인터벌카운터 테스트종료-" << std::endl;
    system("pause");
}

void CheckStopWatch()
{
    auto testStopWatchComponent = std::make_shared<dream::componet::DreamStopWatchComponent>("testStopWatchComponent");
    testStopWatchComponent->Start();
    bool running = true;
    std::chrono::milliseconds lastCounter = std::chrono::milliseconds(-1);
    while (running)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'q':
                running = false;
                break;
            case 's':
                testStopWatchComponent->End();
                break;
            case 'r':
                testStopWatchComponent->Start();
                break;
            default:
                break;
            }
        }
        auto curCount = testStopWatchComponent->GetDuration_toMilliseconds();
        if (lastCounter != curCount)
        {
            system("cls");
            std::cout << "q:나가기 s:스톱 r:리스타트" << std::endl;
            std::cout << curCount.count() << std::endl;
            lastCounter = curCount;
        }
    }

    std::cout << "-스톱워치 테스트종료-" << std::endl;
    system("pause");
}

void CheckTimer()
{
    auto testTimerComponet = std::make_shared<dream::componet::DreamTimerComponet>("testTimerComponet");
    testTimerComponet->Interval(1000);
    auto checkStartTime = std::chrono::steady_clock::now();
    testTimerComponet->Start();
    bool running = true;
    while (running)
    {
        if (testTimerComponet->IsOver())
        {
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - checkStartTime);
            std::cout << "경과 시간 : " << duration.count() << std::endl;
            running = false;
        }
    }
    std::cout << "-타이머 테스트종료-" << std::endl;
    system("pause");
}

void CheckAlarm()
{
    auto test = std::make_shared<dream::actor::DreamLogActor>("test");
    test->Progress_AfterUpdate();

    auto testAlarmComponet = std::make_shared<dream::componet::DreamAlarmComponent>("testAlarmComponet");
    testAlarmComponet->Initialize();
    auto testStopWatchComponent = std::make_shared<dream::componet::DreamStopWatchComponent>("testStopWatchComponent");
    testStopWatchComponent->Initialize();
    testStopWatchComponent->Start();
    auto testLogCom = std::make_shared<dream::componet::DreamLogComponet>("testLogCom");
    testLogCom->Initialize();
    testAlarmComponet->AddLog(testLogCom->Name(), testLogCom);
//    std::cout << "경과 시간(ms) : " << testStopWatchComponent->GetDuration_toMilliseconds().count() << std::endl;


    testAlarmComponet->PrevTime(std::chrono::milliseconds(5000));
    testAlarmComponet->AfterTime(std::chrono::milliseconds(10000));
    bool running = true;
    auto rasieStart = std::chrono::system_clock::now();
    while (running)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'q':
                running = false;
                break;
            case 'w':
                testAlarmComponet->ConditionFunc([]()->bool {return true; });
                break;
            case 'e':
                testAlarmComponet->ConditionFunc([]()->bool {return false; });
                break;
            default:
                break;
            }
        }
        system("cls");
        std::cout << "경과 시간(ms) : " << testStopWatchComponent->GetDuration_toMilliseconds().count() << std::endl;
        std::cout << "마지막 알람경과시간(ms) : " << testAlarmComponet->LastRaiseDuration().count() << std::endl;
        std::cout << "알람 유무 : " << testAlarmComponet->IsRaising() << std::endl;
        std::cout << "----------------" << std::endl;

        auto a = testLogCom->List();
        for (auto item : (*(a.get())))
        {
            std::cout << item << std::endl;
        }
        std::cout << "----------------" << std::endl;
    }
    

    
}