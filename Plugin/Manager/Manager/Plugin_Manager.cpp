#include "Plugin_Manager.h"

#ifndef USE_PLUGIN_MANAGER_PLUGIN_LOADER
#define USE_PLUGIN_MANAGER_PLUGIN_LOADER
#include "Plugin/Manager/Loader/Plugin_Loader.h"
#endif // !USE_PLUGIN_MANAGER_PLUGIN_LOADER

#ifndef DECLARE_PLUGIN_MANAGER_PLUGIN_MANAGER_CPP
#define DECLARE_PLUGIN_MANAGER_PLUGIN_MANAGER_CPP
namespace plugin
{
	const std::wstring Plugin_Manager::Name()
	{
		return manager::Plugin_Loader::Instance().Name();
	}

	const bool Plugin_Manager::Active()
	{
		return manager::Plugin_Loader::Instance().Active();
	}

	bool Plugin_Manager::LoadPlugin(const std::wstring name, const std::filesystem::path& path)
	{
		if (Active() == false)
			return false;
		return manager::Plugin_Loader::Instance().LoadPlugin(name, path);
	}

	std::shared_ptr<plugin::IPlugin> Plugin_Manager::GetPlugin(const std::wstring name)
	{
		if (Active() == false)
			return nullptr;
		return manager::Plugin_Loader::Instance().GetPlugin(name);
	}

	//bool Plugin_Manager::UnloadPlugin(const TString name)
	//{
	//	if (Active() == false)
	//		return false;
	//	return manager::Plugin_Loader::Instance().UnloadPlugin(name);
	//}
}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGIN_MANAGER_CPP