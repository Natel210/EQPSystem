// TestConsole240206.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Shared_Library/String/TString.h"
#include "Plugin/Manager/Manager/Plugin_Manager.h"
//
//#ifndef DECLARE_TESTDLL_PLUGIN_ENTRY
//#define DECLARE_TESTDLL_PLUGIN_ENTRY
//#pragma comment(lib, "Shared_Library.lib")
//#endif // !DECLARE_TESTDLL_PLUGIN_ENTRY

using Plugin_Manager = plugin::Plugin_Manager;

/// 설정 디파인
//#define USE_PLUGIN_TESTER
#define USE_PLUGIN_LOG_TESTER
//#define USE_PLUGIN_TIME_TESTER

#pragma region plugin include
#pragma region plugin
#ifdef USE_PLUGIN_TESTER
#include "PluginTester.h"
#endif // USE_PLUGIN_TESTER
#pragma endregion
#pragma region log
#ifdef USE_PLUGIN_LOG_TESTER
#include "LogTester.h"
#endif // USE_PLUGIN_TESTER
#pragma endregion
#pragma region time
#ifdef USE_PLUGIN_TIME_TESTER
#include "TimeTester.h"
#endif // USE_PLUGIN_TESTER
#pragma endregion
#pragma endregion



int main()
{
    IMBUE_LANGUAGE("KOR");
#pragma region plugin
#ifdef USE_PLUGIN_TESTER
    PluginTester pluginTester;
    pluginTester.Test1();
#endif // USE_PLUGIN_TESTER
#pragma endregion
#pragma region log
#ifdef USE_PLUGIN_LOG_TESTER
    LogTester logTester;
    logTester.Test1();
#endif // USE_PLUGIN_TESTER
#pragma endregion
#pragma region time
#ifdef USE_PLUGIN_TIME_TESTER
    TimeTester timeTester;
    timeTester.Test1();
#endif // USE_PLUGIN_TESTER
#pragma endregion

    //Plugin_Manager::LoadPlugin(_T("TEST"), _T("../x64/Debug/TestDll_Plugin.dll"));

    exit(0);
    //return 0;
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
