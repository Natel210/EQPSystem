#pragma once
#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_TYPE_TRAITS
#define USE_TYPE_TRAITS
#include <type_traits>
#endif // !USE_TYPE_TRAITS

#ifndef USE_PLUGIN_PLUGINEXPORTHEADER
#define USE_PLUGIN_PLUGINEXPORTHEADER
#include "PluginExportHeader.h"
#endif // !USE_PLUGIN_PLUGINEXPORTHEADER

#ifndef DECARE_CREATEPLUGINHEADER
#define DECARE_CREATEPLUGINHEADER
#define CreatePluginHeader() extern "C" PLUGIN_API std::shared_ptr<plugin::share::IPlugin> CreatePlugin()
#endif // !DECARE_CREATEPLUGINHEADER

#ifndef DECARE_IPLUGIN
#define DECARE_IPLUGIN
namespace plugin::share
{
    class PLUGIN_API IPlugin {
    public:
        virtual ~IPlugin() {}
        virtual bool Init() = 0;
    };
}
#endif // !DECARE_IPLUGIN

#ifndef DECARE_CASTPLUGIN
#define DECARE_CASTPLUGIN
namespace plugin::share
{
    template<typename _class>
    extern std::shared_ptr<_class> CastPlugin(std::shared_ptr<IPlugin> plugin)
    {
        if (plugin == nullptr)
            return nullptr;
        auto result = std::dynamic_pointer_cast<_class>(plugin);
        if (result == nullptr)
            return nullptr;
        return result;
    }
}
#endif // !DECARE_CASTPLUGIN




