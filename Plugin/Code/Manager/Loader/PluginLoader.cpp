#include "PluginLoader.h"
#ifndef DECLARE_PLUGINLOADER_CPP
#define DECLARE_PLUGINLOADER_CPP

namespace plugin::manager
{
    bool PluginLoader::LoadPlugin(const TString& name, const TString& path)
    {
        if (CheckExistPlugin(name) == true)
            return false;
        HMODULE moduleHandle = LoadLibrary(path.c_str());
        if (!moduleHandle) {
            TCERR << "Failed to load plugin: " << name << ". DLL not found: " << path << std::endl;
            return false;
        }
        auto createPluginFunc = (std::shared_ptr<share::IPlugin>(*)())GetProcAddress(moduleHandle, "CreatePlugin");
        if (!createPluginFunc) {
            TCERR << "Function FunctionName not found in plugin: " << name << std::endl;
            FreeLibrary(moduleHandle);
            return false;
        }
        auto pluginClass = createPluginFunc();
        if (pluginClass == nullptr)
            return false;
        if (pluginClass->Init() == false)
            return false;
        auto pluginItem = std::make_shared<PluginItem>();
        pluginItem->_module = moduleHandle;
        pluginItem->_class = pluginClass;
        _pluginItemsMapMutex.lock();
        if (CheckExistPlugin(name) == true)
            return false;
        _pluginItemsMap.insert(std::make_pair(name, pluginItem));
        _pluginItemsMapMutex.unlock();
        return true;
    }

    bool PluginLoader::UnloadPlugin(const TString& name)
    {
        std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);
        bool result = true;
        if (CheckExistPlugin(name) == false)
            return false;
        if (FreeLibrary(_pluginItemsMap[name]->_module) == FALSE)
        {
            DWORD errorCode = GetLastError();
            TCERR << "Failed to Unload DLL: " << name << ". Error Code: " << errorCode << std::endl;
            Sleep(1000);// 1 second grace period.
            if (FreeLibrary(_pluginItemsMap[name]->_module) == FALSE)
            {
                DWORD errorCode = GetLastError();
                TCERR << "Failed to Unload DLL: " << name << ". Error Code: " << errorCode << std::endl;
                result = false;
            }
        }
        _pluginItemsMap.erase(name);
        return result;
    }

    std::shared_ptr<share::IPlugin> PluginLoader::GetPlugin(const TString& name)
    {
        if (CheckExistPlugin(name) == false)
            return nullptr;
        return _pluginItemsMap[name]->_class;
    }

    bool PluginLoader::CheckExistPlugin(const TString& name)
    {
        std::lock_guard<std::mutex> lock(_pluginItemsMapMutex);
        if (_pluginItemsMap.find(name) == _pluginItemsMap.end())
            return false;
        return true;
    }
}
#endif // !DECLARE_PLUGINLOADER_CPP