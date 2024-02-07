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
#include "Plugin/Share/PluginExportHeader.h"
#endif // !USE_PLUGIN_PLUGINEXPORTHEADER

#ifndef DECLARE_CREATEPLUGINHEADER
#define DECLARE_CREATEPLUGINHEADER
/// 플러그인 전용 생성 함수 해더 부분, 통상적인 함수 선언과 동일하게 사용하면 됩니다.
#define CreatePluginHeader(projectName) extern "C" PLUGIN_API plugin::share::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_CREATEPLUGINHEADER

#ifndef DECLARE_CREATEPLUGINHEADER_CPP
#define DECLARE_CREATEPLUGINHEADER_CPP
/// 플러그인 전용 생성 함수 해더 부분, 통상적인 함수 선언과 동일하게 사용하면 됩니다.
#define CreatePluginHeaderCpp(projectName) plugin::share::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_CREATEPLUGINHEADER_CPP

#ifndef DECLARE_IPLUGIN
#define DECLARE_IPLUGIN
namespace plugin::share
{
    /// <summary>
    /// 플러그인 인터 페이스
    /// </summary>
    class PLUGIN_API IPlugin {
    public:
        virtual ~IPlugin() {}
        virtual bool Init() = 0;
    };
}
#endif // !DECLARE_IPLUGIN





