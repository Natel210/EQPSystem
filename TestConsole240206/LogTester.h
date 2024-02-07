#pragma once
#include <vector>
#include <map>
#include "CommonShare/TString.h"
#include "Plugin/Manager/Manager/PluginManager.h"
#include "Plugin/Log/Plugin/Log_Plugin.h"

#pragma comment(lib, "../Bin/Debugx64/Plugin/PluginLog.lib")

using Plugin_Manager = plugin::manager::PluginManager;

class LogTester
{
public:
	void Test1()
	{
        TCOUT << _T("\r\n=== Log Tester 1 ===") << std::endl;
        TString a = _T("LOG");
        const std::filesystem::path b("../Bin/Debugx64/Plugin/PluginLog.dll");
        Plugin_Manager::LoadPlugin(a, b);
        auto pl1ori = Plugin_Manager::GetPlugin(a);
        auto plch1 = Plugin_Manager::CastPlugin<TString>(pl1ori);
        auto plch3 = Plugin_Manager::CastPlugin<plugin::Log_Plugin>(pl1ori);
        auto testlog1 = plch3->CreateLog(_T("TEST1"));

        plch3->CreateLog(_T("TEST2"));
        testlog1->Level(plugin::log::ELogLevel::Debug);
        testlog1->Add(_T("A0"));
        testlog1->Add(_T("A1"));
        std::vector<TString> logs;
        //logs.push_back(_T("A1"));
        //logs.clear();
        //logs.push_back(_T("A2"));
        //logs.push_back(_T("A3"));
        //logs.push_back(_T("A4"));
        //testlog1->Level(plugin::log::ELogLevel::Fatal);
        //testlog1->AddRange(logs);
        auto list1 = testlog1->List();
        TCOUT << _T("=============") << std::endl;
        for (auto item : *list1)
        {
            TCOUT << item << std::endl;
        }
        auto rut1 = testlog1->Return();
        TCOUT << _T("=============") << std::endl;
        for (auto item : *rut1)
        {
            TCOUT << item << std::endl;
        }
        auto list2 = testlog1->List();
        TCOUT << _T("=============") << std::endl;
        for (auto item : *list2)
        {
            TCOUT << item << std::endl;
        }
        // 삭제에 관한 이슈
        {
            auto getpluginascaster = Plugin_Manager::GetPluginAsCaster<plugin::Log_Plugin>(_T("LOG"));
            //Plugin_Manager::UnloadPlugin(_T("LOG"));
            int fsdf = 0;
        }

        {
            auto getpluginascaster = Plugin_Manager::GetPluginAsCaster<plugin::Log_Plugin>(_T("LOG"));
            int fsdf = 0;
        }
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

