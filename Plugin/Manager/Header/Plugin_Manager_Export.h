#pragma once
// DLL���� EXPORT�� ���ϴ� Ŭ������ ���Ͽ� �ش� ������ ����
#ifdef EXPORT_PLUGIN_MANAGER_DLL
#define PLUGIN_MANAGER_API __declspec(dllexport)
#else
#define PLUGIN_MANAGER_API __declspec(dllimport)
#endif // !EXPORT_PROJECT