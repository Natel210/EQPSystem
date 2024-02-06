#pragma once

#ifndef USE_PLUGIN_PLUGINEXPORTHEADER
#define USE_PLUGIN_PLUGINEXPORTHEADER
#include "Plugin/Code/Share/PluginExportHeader.h"
#endif // !USE_PLUGIN_PLUGINEXPORTHEADER

#ifndef USE_COMMON_TSTRING
#define USE_COMMON_TSTRING
#include "CommonShare/TString.h"
#endif // !USE_COMMON_TSTRING

#ifndef USE_PLUGIN_IPLUGIN
#define USE_PLUGIN_IPLUGIN
#include "Plugin/Code/Share/IPlugin.h"
#endif // !USE_PLUGIN_IPLUGIN

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef DECLARE_PLUGINMANAGER_H
#define DECLARE_PLUGINMANAGER_H
namespace plugin::manager
{
    class PLUGIN_API PluginManager {
    public:
        static bool LoadPlugin(const TString& name, const TString& path);
        static std::shared_ptr<share::IPlugin> GetPlugin(const TString& name);
        static bool UnloadPlugin(const TString& name);
    };
}
#endif // !DECLARE_PLUGINMANAGER_H