#include "PluginManager.h"

#ifndef USE_PLUGIN_PLUGINLOADER
#define USE_PLUGIN_PLUGINLOADER
#include "Plugin/Code/Manager/Loader/PluginLoader.h" // 가정: PluginLoader에 LoadPlugin 정의
#endif // !USE_PLUGIN_PLUGINLOADER

#ifndef DECLARE_PLUGINMANAGER_CPP
#define DECLARE_PLUGINMANAGER_CPP
namespace plugin::manager
{
	bool PluginManager::LoadPlugin(const TString& name, const TString& path)
	{
		return PluginLoader::Instance().LoadPlugin(name, path);
	}
	std::shared_ptr<share::IPlugin> PluginManager::GetPlugin(const TString& name)
	{
		return PluginLoader::Instance().GetPlugin(name);
	}
	bool PluginManager::UnloadPlugin(const TString& name)
	{
		return PluginLoader::Instance().UnloadPlugin(name);
	}
}
#endif // !DECLARE_PLUGINMANAGER_CPP