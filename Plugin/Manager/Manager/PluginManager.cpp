#include "PluginManager.h"

#ifndef USE_PLUGIN_PLUGINLOADER
#define USE_PLUGIN_PLUGINLOADER
#include "Plugin/Manager/Loader/PluginLoader.h"
#endif // !USE_PLUGIN_PLUGINLOADER

#ifndef DECLARE_PLUGIN_PLUGINMANAGER_CPP
#define DECLARE_PLUGIN_PLUGINMANAGER_CPP
namespace plugin::manager
{
	bool PluginManager::LoadPlugin(const TString name, const std::filesystem::path& path)
	{
		return PluginLoader::Instance().LoadPlugin(name, path);
	}
	std::shared_ptr<share::IPlugin> PluginManager::GetPlugin(const TString name)
	{
		return PluginLoader::Instance().GetPlugin(name);
	}
	//bool PluginManager::UnloadPlugin(const TString name)
	//{
	//	return PluginLoader::Instance().UnloadPlugin(name);
	//}
}
#endif // !DECLARE_PLUGIN_PLUGINMANAGER_CPP