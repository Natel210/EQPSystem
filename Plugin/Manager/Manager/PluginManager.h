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
        static std::shared_ptr<share::IPlugin> GetPlugin(const TString name);

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
#endif // !DECLARE_PLUGIN_PLUGINMANAGER_H