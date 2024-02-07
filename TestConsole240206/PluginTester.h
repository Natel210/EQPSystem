#pragma once
#include "CommonShare/TString.h"
#include "Plugin/Manager/Manager/PluginManager.h"
#include "Plugin/MyDllPlugin/MyDllPlugin.h"

#pragma comment(lib, "../Bin/Debugx64/Plugin/TestDll_Plugin.lib")

using Plugin_Manager = plugin::manager::PluginManager;

class PluginTester
{
public:
	void Test1()
	{
		TCOUT << _T("\r\n=== Plugin Tester 1 ===") << std::endl;
		TString a = _T("TESTER1");
		const std::filesystem::path b("../Bin/Debugx64/Plugin/TestDll_Plugin.dll");
		Plugin_Manager::LoadPlugin(a, b);
	}
public:
	PluginTester() = default;
	~PluginTester() = default;

private:

};

