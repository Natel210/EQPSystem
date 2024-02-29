// Shared4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <conio.h>
#include <iostream>
#include "dream/actor/DreamLogActor.h"
#include "dream/component/DreamIntervalCounterComponent.h"
int main()
{
#pragma region MyRegion
    //auto a = std::make_shared<dream::componet::Dream_LogComponet>("testLog");
    //a->SetString("TESTS");
    //auto b = std::dynamic_pointer_cast<dream::base::DreamObjectBase>(a);

    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;

    //b->Initialize();

    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;

    //auto c = b->Clone();
    //auto d = std::dynamic_pointer_cast<dream::componet::Dream_LogComponet>(c);


    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;
    //std::cout << "-----------" << std::endl;
    //std::cout << d->GetString() << std::endl;
    //std::cout << d->GetStringPointerAddr() << std::endl;
    //std::cout << d->GetThisPointerAddr() << std::endl;

    //d->SetString("이건테스트아니다");

    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;
    //std::cout << "-----------" << std::endl;
    //std::cout << d->GetString() << std::endl;
    //std::cout << d->GetStringPointerAddr() << std::endl;
    //std::cout << d->GetThisPointerAddr() << std::endl;


    //d->Release();

    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;
    //std::cout << "-----------" << std::endl;
    //std::cout << d->GetString() << std::endl;
    //std::cout << d->GetStringPointerAddr() << std::endl;
    //std::cout << d->GetThisPointerAddr() << std::endl;

    //b->Release();

    //std::cout << "============" << std::endl;
    //std::cout << a->GetString() << std::endl;
    //std::cout << a->GetStringPointerAddr() << std::endl;
    //std::cout << a->GetThisPointerAddr() << std::endl;
    //std::cout << "-----------" << std::endl;
    //std::cout << d->GetString() << std::endl;
    //std::cout << d->GetStringPointerAddr() << std::endl;
    //std::cout << d->GetThisPointerAddr() << std::endl;
#pragma endregion

#pragma region Log
    //auto dreamLogActor = std::make_shared<dream::actor::DreamLogActor>("TestActor");
    //auto logCom = dreamLogActor->LogComponent();
    //logCom->AddLog("1");
    //logCom->AddLog("2");
    //logCom->Level(dream::ELogLevel::Error);
    //logCom->AddLog("가");
    //logCom->AddLog("나");
    //logCom->AddLog("다");
    //logCom->AddLogsRange({ "A","B","C" });
    //auto list1 = logCom->List();
    //for (auto item : *(list1.get()))
    //    std::cout << item << std::endl;
    //std::cout << "==============" << std::endl;
    //logCom->Clear();
    //auto list2 = logCom->List();
    //for (auto item : *(list1.get()))
    //    std::cout << item << std::endl;
    //std::cout << "---------------" << std::endl;
    //for (auto item : *(list2.get()))
    //    std::cout << item << std::endl;
    //std::cout << "==============" << std::endl;
#pragma endregion
    
#pragma region IntevalCounter
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

#pragma endregion


    exit(0);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.