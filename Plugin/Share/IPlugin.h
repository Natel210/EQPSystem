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
/// �÷����� ���� ���� �Լ� �ش� �κ�, ������� �Լ� ����� �����ϰ� ����ϸ� �˴ϴ�.
#define CreatePluginHeader(projectName) extern "C" PLUGIN_API plugin::share::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_CREATEPLUGINHEADER

#ifndef DECLARE_CREATEPLUGINHEADER_CPP
#define DECLARE_CREATEPLUGINHEADER_CPP
/// �÷����� ���� ���� �Լ� �ش� �κ�, ������� �Լ� ����� �����ϰ� ����ϸ� �˴ϴ�.
#define CreatePluginHeaderCpp(projectName) plugin::share::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_CREATEPLUGINHEADER_CPP

#ifndef DECLARE_IPLUGIN
#define DECLARE_IPLUGIN
namespace plugin::share
{
    /// <summary>
    /// �÷����� ���� ���̽�
    /// </summary>
    class PLUGIN_API IPlugin {
    public:
        virtual ~IPlugin() {}
        virtual bool Init() = 0;
    };
}
#endif // !DECLARE_IPLUGIN





