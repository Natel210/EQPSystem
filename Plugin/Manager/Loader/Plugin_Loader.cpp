#include "Plugin_Loader.h"
#ifndef DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP
#define DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP

namespace plugin::manager
{
	const TString Plugin_Loader::Name() const
	{
		std::lock_guard<std::mutex> lock(_nameMutex);
		return _name;
	}

	void Plugin_Loader::Name(const TString& name)
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

	bool Plugin_Loader::LoadPlugin(const TString& name, const std::filesystem::path& path)
	{
		// �÷����� ���� ����
		_pluginItemsMapMutex.lock();
		if (CheckExistPlugin(name) == true)
		{
			_pluginItemsMapMutex.unlock();
			return false;
		}
		_pluginItemsMapMutex.unlock();
		try
		{
			// DLL �ε�
			HMODULE moduleHandle = LoadLibrary(TO_TSTRING_PATH(path).c_str());
			if (!moduleHandle) {
				TCERR << "Failed to load plugin: " << name << ". DLL not found: " << path << std::endl;
				return false;
			}
			std::string funcName;
			funcName = "Create" + path.stem().string() + "Plugin";
			// �ݵ�� ���� �ؾ��ϴ� �Լ� �ε�
			auto createPluginFunc = (plugin::IPlugin * (*)())GetProcAddress(moduleHandle, funcName.c_str());
			if (!createPluginFunc) {
				TCERR << "Function FunctionName not found in plugin: " << name << std::endl;
				FreeLibrary(moduleHandle);
				return false;
			}

			// �Լ� ���� �� Init ����
			auto pluginClass = createPluginFunc();
			if (pluginClass == nullptr)
				return false;
			if (pluginClass->Init() == false)
				return false;

			// shared_ptr�� �����ϵ�, �����ڿ��� DLL ��ε�� ��ü ���� ����
			std::shared_ptr<plugin::IPlugin> pluginPtr(pluginClass);

			// shared_ptr nullptr �˻�
			if (pluginPtr == nullptr)
				return false;

			// �̸� �ֱ�
			pluginPtr->Name(name);

			// ������ ����ü�� ����� Map ���� ����
			auto pluginItem = std::make_shared<Plugin_Item>();
			pluginItem->_module = moduleHandle;
			pluginItem->_class = pluginPtr;
			_pluginItemsMapMutex.lock();
			if (CheckExistPlugin(name) == true)
				return false;
			_pluginItemsDic.insert(std::make_pair(name, pluginItem));
			_pluginItemsMapMutex.unlock();

			// ���� ����
			return true;
		}
		catch (const std::exception& e)
		{
			TCERR << "Plugin loading error: " << e.what() << std::endl;
			return false; // ���� �߻� �� false ��ȯ
		}

	}

	//bool Plugin_Loader::UnloadPlugin(const TString& name)
	//{
	//	std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);

	//	// ���� ���� Ȯ�� -> ���ٸ� retrun false
	//	if (CheckExistPlugin(name) == false)
	//		return false;

	//	// DLL ���� �ǽ�
	//	// -> ������ �������� ������ �����ϴ�.
	//	// 1. �̹� ������ ���
	//	// 2. ���������� DLL�� �������� �ʴ� ���
	//	// ���� �ó��������� �ѹ��� ������ �õ��ϰ� 
	//	// �ش� ���׿� ���� �ȵȴٸ� 
	//	// std::cerr�� �̿��Ͽ� �ش� ������ ���

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

	//	// ���� ������ ������� Dic���� ����
	//	_pluginItemsDic.erase(name);

	//	// ����� ����
	//	return result;
	//}

	std::shared_ptr<plugin::IPlugin> Plugin_Loader::GetPlugin(const TString& name)
	{
		std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);
		// ���� ���� Ȯ�� �� �ش� Ŭ���� ����
		if (CheckExistPlugin(name) == false)
			return nullptr;
		return _pluginItemsDic[name]->_class;
	}

	bool Plugin_Loader::CheckExistPlugin(const TString& name)
	{
		// Finding�� ���ؼ� Ȯ���ϰ� ���� ���� Ȯ��
		if (_pluginItemsDic.find(name) == _pluginItemsDic.end())
			return false;
		return true;
	}

}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_CPP