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
        /// 플러그인 로딩
        /// </summary>
        /// <param name="name"> -> 플러그인 이름</param>
        /// <param name="path"> -> 플러그인 DLL 경로</param>
        /// <returns>성공 여부</returns>
        static bool LoadPlugin(const TString name, const std::filesystem::path& path);

        /// <summary>
        /// 로딩된 플러그인 가져옵니다.
        /// </summary>
        /// <param name="name"> -> 플러그인 이름</param>
        /// <returns>없다면 nullptr </returns>
        static std::shared_ptr<plugin::IPlugin> GetPlugin(const TString name);

        ///// <summary>
        ///// 플러그인 사용 해제
        ///// </summary>
        ///// <param name="name"> -> 플러그인 이름</param>
        ///// <returns>해제 성공 여부</returns>
        //static bool UnloadPlugin(const TString name);

    public:

        /// <summary>
        /// 플러그인 다운 캐스터
        /// </summary>
        /// <typeparam name="_class">플러그인 클래스 원형</typeparam>
        /// <param name="plugin"> -> 플러그인</param>
        /// <returns>캐스트에 실패한다면 nullptr</returns>
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
        /// 플러그인 다운 캐스터
        /// </summary>
        /// <typeparam name="_class">플러그인 클래스 원형</typeparam>
        /// <param name="name"> -> 플러그인 이름</param>
        /// <returns>캐스트에 실패한다면 nullptr</returns>
        template<typename _class>
        static std::shared_ptr<_class> GetPluginAsCaster(const TString name)
        {
            return CastPlugin<_class>(GetPlugin(name));
        }
    };
}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGINMANAGER_H