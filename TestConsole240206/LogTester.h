#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Plugin/Manager/Manager/Plugin_Manager.h"
#include "Plugin/Log/Plugin/Log_Plugin.h"

//#pragma comment(lib, "../Bin/Debugx64/Plugin/Plugin_Log.lib")

using Plugin_Manager = plugin::Plugin_Manager;

class LogTester
{
public:
	void Test1()
	{
        std::wcout << L"\r\n=== Log Tester 1 ===" << std::endl;
        std::wstring a = L"LOG";
        const std::filesystem::path b("../Bin/Debugx64/Plugin/Plugin_Log.dll");
        
        Plugin_Manager::LoadPlugin(a, b);
        auto pl1ori = Plugin_Manager::GetPlugin(a);
        auto plch1 = Plugin_Manager::CastPlugin<std::wstring>(pl1ori);
        auto plch3 = Plugin_Manager::CastPlugin<plugin::Log_Plugin>(pl1ori);
        auto testlog1 = plch3->CreateItem(L"TEST1", plugin::className::ILogClassName);
        auto testCastingLog = std::dynamic_pointer_cast<plugin::ILog>(testlog1);
        testCastingLog->Add(L"A0");
        testCastingLog->Level(plugin::ELogLevel::Debug);
        testCastingLog->Add(L"A1");


        //plch3->CreateItem(L"TEST2");
        //std::vector<TString> logs;
        //{
        //    std::vector<std::wstring> logs;
        //    logs.push_back(L"A1");
        //    testCastingLog->AddRange(logs);
        //}
        std::vector<std::wstring> logs;
        logs.push_back(L"A1");
        logs.push_back(L"A2\0");
        logs.push_back(L"A3\0");
        logs.push_back(L"A4\0");
        testCastingLog->Level(plugin::ELogLevel::Fatal);
        testCastingLog->AddRange(logs);
        auto list1 = testCastingLog->List();
        std::wcout << L"=============" << std::endl;
        for (auto item : *list1)
        {
            std::wcout << item << std::endl;
        }
        auto rut1 = testCastingLog->Return();
        std::wcout << L"=============" << std::endl;
        for (auto item : *rut1)
        {
            std::wcout << item << std::endl;
        }
        auto list2 = testCastingLog->List();
        std::wcout << L"=============" << std::endl;
        for (auto item : *list2)
        {
            std::wcout << item << std::endl;
        }
        //// 삭제에 관한 이슈
        //{
        //    auto getpluginascaster = Plugin_Manager::GetPluginAsCaster<plugin::Log_Plugin>(_T("LOG"));
        //    //Plugin_Manager::UnloadPlugin(_T("LOG"));
        //    int fsdf = 0;
        //}

        //{
        //    auto getpluginascaster = Plugin_Manager::GetPluginAsCaster<plugin::Log_Plugin>(_T("LOG"));
        //    int fsdf = 0;
        //}
        //std::map<int, TString> lom;
        //std::vector<std::string> lov;
        //std::vector<std::wstring> lov;
        //std::vector<TString> lov;
        //std::vector<int> logs;
        //logs.push_back(_T("1"));
        //logs.push_back(_T("2"));

	}
public:
	LogTester() = default;
	~LogTester() = default;

private:

};

