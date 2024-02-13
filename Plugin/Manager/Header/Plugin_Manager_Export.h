#pragma once
// DLL에서 EXPORT를 원하는 클래스에 한하여 해당 디파인 적용
#ifdef EXPORT_PLUGIN_MANAGER_DLL
#define PLUGIN_MANAGER_API __declspec(dllexport)
#else
#define PLUGIN_MANAGER_API __declspec(dllimport)
#endif // !EXPORT_PROJECT