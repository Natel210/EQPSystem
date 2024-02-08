#pragma once
#pragma once
#include "CommonShare/TString.h"
#include "Plugin/Manager/Manager/PluginManager.h"

#include "Plugin/Log/Plugin/Time_Plugin.h"

#pragma comment(lib, "../Bin/Debugx64/Plugin/PluginTime.lib")

using Plugin_Manager = plugin::manager::PluginManager;

class PluginTester
{
public:
	void Test1()
	{
        TCOUT << _T("\r\n=== Time Tester 1 ===") << std::endl;
        TString tempName = _T("TIME");
        const std::filesystem::path tempPath("../Bin/Debugx64/Plugin/PluginTime.dll");
        Plugin_Manager::LoadPlugin(tempName, tempPath);
        auto plch3 = Plugin_Manager::GetPluginAsCaster<plugin::Time_Plugin>(tempName);
        //auto testlog1 = plch3->CreateLog(_T("TEST1"));
	}
public:
	PluginTester() = default;
	~PluginTester() = default;

private:

};

