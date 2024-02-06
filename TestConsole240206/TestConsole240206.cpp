// TestConsole240206.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CommonShare/TString.h"
#include "Plugin/Code/Manager/Manager/PluginManager.h"
#include "Plugin/Code/MyDllPlugin/MyDllPlugin.h"
using Plugin_Manager = plugin::manager::PluginManager;

int main()
{
    Plugin_Manager c;
    // 정적 라이브러리 플러그인 로드 (예시 경로, 실제 경로에 맞게 수정 필요)
    // 정적 라이브러리는 동적 로딩이 불가능하므로, 이 부분은 DLL에만 적용됩니다.
    //manager.loadPlugin("path/to/MyLibPlugin.lib");

    // 동적 라이브러리(DLL) 플러그인 로드
    TString a = _T("TEST");
    TString b = _T("../x64/Debug/TestDll_Plugin.dll");
    //Plugin_Manager::LoadPlugin(_T("TEST"), _T("../x64/Debug/TestDll_Plugin.dll"));
    Plugin_Manager::LoadPlugin(a, b);
    auto pl1ori = Plugin_Manager::GetPlugin(a);
    auto plch1 = plugin::share::CastPlugin<TString>(pl1ori);
    auto plch2 = plugin::share::CastPlugin<MyDllPlugin>(pl1ori);

    //c.UnloadPlugin(a.c_str());
    // 
    //Plugin_anager::loadPlugin("TestDll_Plugin.dll");
    //Plugin_anager::executePlugins();




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
