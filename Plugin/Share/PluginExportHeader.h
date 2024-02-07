#pragma once
#ifndef DECALRE_PLUGINEXPORTHEADER
#define DECALRE_PLUGINEXPORTHEADER
// 플러그인에서 DLL에서 EXPORT를 원하는 클래스에 한하여 해당 디파인 적용
#ifdef PLUGIN_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif
#endif // !DECALRE_PLUGINEXPORTHEADER