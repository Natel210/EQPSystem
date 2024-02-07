#pragma once

#ifndef USE_PLUGIN_PLUGINEXPORTHEADER
#define USE_PLUGIN_PLUGINEXPORTHEADER
#include "Plugin/Share/PluginExportHeader.h"
#endif // !USE_PLUGIN_PLUGINEXPORTHEADER

#ifndef USE_COMMON_TSTRING
#define USE_COMMON_TSTRING
#include "CommonShare/TString.h"
#endif // !USE_COMMON_TSTRING

#ifndef USE_PLUGIN_IPLUGIN
#define USE_PLUGIN_IPLUGIN
#include "Plugin/Share/IPlugin.h"
#endif // !USE_PLUGIN_IPLUGIN

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_STD_FILESYSTEM
#define USE_STD_FILESYSTEM
#include <filesystem>
#endif // !USE_STD_FILESYSTEM

#ifndef DECLARE_PLUGIN_PLUGINMANAGER_H
#define DECLARE_PLUGIN_PLUGINMANAGER_H
namespace plugin::manager
{
    class PLUGIN_API PluginManager {
    public:

        /// <summary>
        /// �÷����� �ε�
        /// </summary>
        /// <param name="name"> -> �÷����� �̸�</param>
        /// <param name="path"> -> �÷����� DLL ���</param>
        /// <returns>���� ����</returns>
        static bool LoadPlugin(const TString name, const std::filesystem::path& path);

        /// <summary>
        /// �ε��� �÷����� �����ɴϴ�.
        /// </summary>
        /// <param name="name"> -> �÷����� �̸�</param>
        /// <returns>���ٸ� nullptr </returns>
        static std::shared_ptr<share::IPlugin> GetPlugin(const TString name);

        ///// <summary>
        ///// �÷����� ��� ����
        ///// </summary>
        ///// <param name="name"> -> �÷����� �̸�</param>
        ///// <returns>���� ���� ����</returns>
        //static bool UnloadPlugin(const TString name);

    public:

        /// <summary>
        /// �÷����� �ٿ� ĳ����
        /// </summary>
        /// <typeparam name="_class">�÷����� Ŭ���� ����</typeparam>
        /// <param name="plugin"> -> �÷�����</param>
        /// <returns>ĳ��Ʈ�� �����Ѵٸ� nullptr</returns>
        template<typename _class>
        static std::shared_ptr<_class> CastPlugin(std::shared_ptr<plugin::share::IPlugin> plugin)
        {
            if (plugin == nullptr)
                return nullptr;
            auto result = std::dynamic_pointer_cast<_class>(plugin);
            if (result == nullptr)
                return nullptr;
            return result;
        }

    public:
        /// <summary>
        /// �÷����� �ٿ� ĳ����
        /// </summary>
        /// <typeparam name="_class">�÷����� Ŭ���� ����</typeparam>
        /// <param name="name"> -> �÷����� �̸�</param>
        /// <returns>ĳ��Ʈ�� �����Ѵٸ� nullptr</returns>
        template<typename _class>
        static std::shared_ptr<_class> GetPluginAsCaster(const TString name)
        {
            return CastPlugin<_class>(GetPlugin(name));
        }
    };
}
#endif // !DECLARE_PLUGIN_PLUGINMANAGER_H