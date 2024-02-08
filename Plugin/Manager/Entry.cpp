#ifndef DECLARE_PLUGINMANAGER_ENTRY
#define DECLARE_PLUGINMANAGER_ENTRY
#pragma comment(lib, "Plugin/PluginShare.lib")
#pragma comment(lib, "CommonShare.lib")
#endif // !DECLARE_PLUGINMANAGER_ENTRY

/*
* 플러그인 넣는방법

#include "Plugin/Manager/Manager/PluginManager.h"
#include "Plugin/[카테고리]/Plugin/[플러그인 해더]"

//플러그인의 내부 동작을 액세스 시에 필요한 빌드 타임 리소스 로딩
#pragma comment(lib, "../Bin/Debugx64/Plugin/[플러그인 정적라이브러리]")

void ImportPlugin_[카테고리]
{
	
}


* 
* 
*/