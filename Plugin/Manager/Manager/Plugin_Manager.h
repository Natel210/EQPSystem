#pragma once

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_STD_FILESYSTEM
#define USE_STD_FILESYSTEM
#include <filesystem>
#endif // !USE_STD_FILESYSTEM

#ifndef USE_SHARED_LIBRARY_TSTRING
#define USE_SHARED_LIBRARY_TSTRING
#include "Shared_Library/String/TString.h"
#endif // !USE_SHARED_LIBRARY_TSTRING

#ifndef USE_SHARED_LIBRARY_IOBJECTCLASS
#define USE_SHARED_LIBRARY_IOBJECTCLASS
#include "Shared_Library/ClassTemplate/Object/IObjectClass.h"
#endif // !USE_SHARED_LIBRARY_IOBJECTCLASS

#ifndef USE_SHARED_LIBRARY_IPLUGIN
#define USE_SHARED_LIBRARY_IPLUGIN
#include "Shared_Library/ClassTemplate/Plugin/IPlugin.h"
#endif // !USE_SHARED_LIBRARY_IPLUGIN

#ifndef USE_PLUGIN_MANAGER_PLUGIN_MANAGER_EXPORT
#define USE_PLUGIN_MANAGER_PLUGIN_MANAGER_EXPORT
#include "Plugin/Manager/Header/Plugin_Manager_Export.h"
#endif // !USE_PLUGIN_MANAGER_PLUGIN_MANAGER_EXPORT

#ifndef DECLARE_PLUGIN_MANAGER_PLUGIN_MANAGER_H
#define DECLARE_PLUGIN_MANAGER_PLUGIN_MANAGER_H
namespace plugin
{
    class PLUGIN_MANAGER_API Plugin_Manager
    {
#pragma region Name

    public:
        /// <summary>
        /// Get
        /// </summary>
        static [[nodiscard]] const TString Name();

#pragma region Active

    public:
        /// <summary>
        /// Get
        /// </summary>
        static [[nodiscard]] const bool Active();

#pragma endregion

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
        static std::shared_ptr<plugin::IPlugin> GetPlugin(const TString name);

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
        static std::shared_ptr<_class> CastPlugin(std::shared_ptr<plugin::IPlugin> plugin)
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
#endif // !DECLARE_PLUGIN_MANAGER_PLUGINMANAGER_H