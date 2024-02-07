#include "PluginLoader.h"
#ifndef DECLARE_PLUGIN_PLUGINLOADER_CPP
#define DECLARE_PLUGIN_PLUGINLOADER_CPP

namespace plugin::manager
{
	bool PluginLoader::LoadPlugin(const TString& name, const std::filesystem::path& path)
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
			HMODULE moduleHandle = LoadLibrary(TO_TSTRING_PATH(path).c_str());
			if (!moduleHandle) {
				TCERR << "Failed to load plugin: " << name << ". DLL not found: " << path << std::endl;
				return false;
			}
			std::string funcName;
			funcName = "Create" + path.stem().string() + "Plugin";
			// 반드시 존재 해야하는 함수 로딩
			auto createPluginFunc = (share::IPlugin * (*)())GetProcAddress(moduleHandle, funcName.c_str());
			if (!createPluginFunc) {
				TCERR << "Function FunctionName not found in plugin: " << name << std::endl;
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
			std::shared_ptr<plugin::share::IPlugin> pluginPtr(pluginClass);

			// 성공후 구조체를 만들고 Map 삽입 진행
			auto pluginItem = std::make_shared<PluginItem>();
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
			TCERR << "Plugin loading error: " << e.what() << std::endl;
			return false; // 예외 발생 시 false 반환
		}

	}

	//bool PluginLoader::UnloadPlugin(const TString& name)
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

	std::shared_ptr<share::IPlugin> PluginLoader::GetPlugin(const TString& name)
	{
		std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);
		// 존재 유무 확인 후 해당 클래스 전달
		if (CheckExistPlugin(name) == false)
			return nullptr;
		return _pluginItemsDic[name]->_class;
	}

	bool PluginLoader::CheckExistPlugin(const TString& name)
	{
		// Finding을 통해서 확인하고 존재 유무 확인
		if (_pluginItemsDic.find(name) == _pluginItemsDic.end())
			return false;
		return true;
	}
}
#endif // !DECLARE_PLUGIN_PLUGINLOADER_CPP