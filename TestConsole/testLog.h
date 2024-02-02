#pragma once
#include <iostream>
#include "../sysDLL/LogManager.h"

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