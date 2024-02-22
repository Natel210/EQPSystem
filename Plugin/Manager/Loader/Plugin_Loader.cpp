#include "Plugin_Loader.h"
#ifndef DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP
#define DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP

#ifndef USE_STD_IOSTREAM
#define USE_STD_IOSTREAM
#include <iostream>
#endif // !USE_STD_IOSTREAM


namespace plugin::manager
{
	const std::wstring Plugin_Loader::Name() const
	{
		std::lock_guard<std::mutex> lock(_nameMutex);
		return _name;
	}

	void Plugin_Loader::Name(const std::wstring& name)
	{
		std::lock_guard<std::mutex> lock(_nameMutex);
		if (_name != name)
			_name = name;
	}

	const bool Plugin_Loader::Active() const
	{
		std::lock_guard<std::mutex> lock(_activeMutex);
		return _active;
	}

	void Plugin_Loader::Active(const bool active)
	{
		std::lock_guard<std::mutex> lock(_activeMutex);
		if (_active != active)
			_active = active;
	}

	bool Plugin_Loader::LoadPlugin(const std::wstring& name, const std::filesystem::path& path)
	{
		// 플러그인 존재 유무
		_pluginItemsMapMutex.lock();
		if (CheckExistPlugin(name) == true)
		{
			_pluginItemsMapMutex.unlock();
			return false;
		}
		_pluginItemsMapMutex.unlock();
		try
		{
			// DLL 로딩
			HMODULE moduleHandle = LoadLibraryW(path.wstring().c_str());
			if (!moduleHandle) {
				std::wcerr << L"Failed to load plugin: " << name << L". DLL not found: " << path << std::endl;
				return false;
			}
			std::string funcName;
			funcName = "Create" + path.stem().string() + "Plugin";
			// 반드시 존재 해야하는 함수 로딩
			auto createPluginFunc = (plugin::IPlugin * (*)())GetProcAddress(moduleHandle, funcName.c_str());
			if (!createPluginFunc) {
				std::wcerr << L"Function FunctionName not found in plugin: " << name << std::endl;
				FreeLibrary(moduleHandle);
				return false;
			}

			// 함수 실행 및 Init 실행
			auto pluginClass = createPluginFunc();
			if (pluginClass == nullptr)
				return false;
			if (pluginClass->Init() == false)
				return false;

			// shared_ptr로 관리하되, 삭제자에서 DLL 언로드와 객체 삭제 수행
			std::shared_ptr<plugin::IPlugin> pluginPtr(pluginClass);

			// shared_ptr nullptr 검사
			if (pluginPtr == nullptr)
				return false;

			// 이름 넣기
			pluginPtr->Name(name);

			// 성공후 구조체를 만들고 Map 삽입 진행
			auto pluginItem = std::make_shared<Plugin_Item>();
			pluginItem->_module = moduleHandle;
			pluginItem->_class = pluginPtr;
			_pluginItemsMapMutex.lock();
			if (CheckExistPlugin(name) == true)
				return false;
			_pluginItemsDic.insert(std::make_pair(name, pluginItem));
			_pluginItemsMapMutex.unlock();

			// 최종 성공
			return true;
		}
		catch (const std::exception& e)
		{
			std::wcerr << L"Plugin loading error: " << e.what() << std::endl;
			return false; // 예외 발생 시 false 반환
		}

	}

	//bool Plugin_Loader::UnloadPlugin(const TString& name)
	//{
	//	std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);

	//	// 존재 유무 확인 -> 없다면 retrun false
	//	if (CheckExistPlugin(name) == false)
	//		return false;

	//	// DLL 해제 실시
	//	// -> 해제시 문제점은 다음과 같습니다.
	//	// 1. 이미 해제된 경우
	//	// 2. 정상적으로 DLL이 동작하지 않는 경우
	//	// 위의 시나리오에서 한번더 해제를 시도하고 
	//	// 해당 사항에 따라서 안된다면 
	//	// std::cerr을 이용하여 해당 내역을 출력

	//	bool result = true;
	//	if (FreeLibrary(_pluginItemsDic[name]->_module) == FALSE)
	//	{
	//		DWORD errorCode = GetLastError();
	//		TCERR << "Failed to Unload DLL: " << name << ". Error Code: " << errorCode << std::endl;
	//		Sleep(1000);// 1 second grace period.
	//		if (FreeLibrary(_pluginItemsDic[name]->_module) == FALSE)
	//		{
	//			DWORD errorCode = GetLastError();
	//			TCERR << "Failed to Unload DLL: " << name << ". Error Code: " << errorCode << std::endl;
	//			result = false;
	//		}
	//	}

	//	// 해제 유무와 상관없이 Dic에서 삭제
	//	_pluginItemsDic.erase(name);

	//	// 결과값 송출
	//	return result;
	//}

	std::shared_ptr<plugin::IPlugin> Plugin_Loader::GetPlugin(const std::wstring& name)
	{
		std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);
		// 존재 유무 확인 후 해당 클래스 전달
		if (CheckExistPlugin(name) == false)
			return nullptr;
		return _pluginItemsDic[name]->_class;
	}

	bool Plugin_Loader::CheckExistPlugin(const std::wstring& name)
	{
		// Finding을 통해서 확인하고 존재 유무 확인
		if (_pluginItemsDic.find(name) == _pluginItemsDic.end())
			return false;
		return true;
	}

}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP