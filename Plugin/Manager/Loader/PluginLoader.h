#pragma once

#ifndef USE_STD_UNORDERED_MAP
#define USE_STD_UNORDERED_MAP
#include <unordered_map>
#endif // !USE_STD_UNORDERED_MAP

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_STD_MUTEX
#define USE_STD_MUTEX
#include <mutex>
#endif // !USE_STD_MUTEX

#ifndef USE_STD_TYPE_TRAITS
#define USE_STD_TYPE_TRAITS
#include <type_traits>
#endif // !USE_STD_TYPE_TRAITS

#ifndef USE_WINODW_WINDOWS
#define USE_WINODW_WINDOWS
#include <Windows.h>
#endif // !USE_WINODW_WINDOWS

#ifndef USE_COMMON_TSTRING
#define USE_COMMON_TSTRING
#include "CommonShare/TString.h"
#endif // !USE_COMMON_TSTRING

#ifndef USE_COMMON_SINGLETONTEMPLATE
#define USE_COMMON_SINGLETONTEMPLATE
#include "CommonShare/SingletonTemplate.h"
#endif // !USE_COMMON_SINGLETONTEMPLATE

#ifndef USE_PLUGIN_IPLUGIN
#define USE_PLUGIN_IPLUGIN
#include "Plugin/Share/IPlugin.h"
#endif // !USE_PLUGIN_IPLUGIN

#ifndef DECLARE_PLUGINLOADER_H
#define DECLARE_PLUGINLOADER_H
namespace plugin::manager
{
	/// <summary>
	/// 플러그인 로딩을 위한 싱글톤<para/>
	/// 멀티 쓰레딩 환경을 위한 적용이 되어있습니다.<para/>
	/// </summary>
	class PluginLoader : public SingletonTemplate<PluginLoader>
	{
	private:
		/// <summary>
		/// 플러그 인을 위한 DLL 모듈과 생성된 클래스의 구조체<para/>
		/// 이너 클래스 private<para/>
		/// </summary>
		struct PluginItem
		{
			HMODULE _module;
			std::shared_ptr<share::IPlugin> _class;
		};

	public:
		/// <summary>
		/// 플러그인 로딩
		/// </summary>
		/// <param name="name"> -> 플러그인 이름</param>
		/// <param name="path"> -> 플러그인 DLL 경로</param>
		/// <returns>성공 여부</returns>
		bool LoadPlugin(const TString& name, const std::filesystem::path& path);

		/// <summary>
		/// 로딩된 플러그인 가져옵니다.
		/// </summary>
		/// <param name="name"> -> 플러그인 이름</param>
		/// <returns>없다면 nullptr </returns>
		std::shared_ptr<share::IPlugin> GetPlugin(const TString& name);

		///// <summary>
		///// 플러그인 사용 해제
		///// </summary>
		///// <param name="name"> -> 플러그인 이름</param>
		///// <returns>해제 성공 여부</returns>
		//bool UnloadPlugin(const TString& name);

	private:
		/// <summary>
		/// 플러그인 존재 여부
		/// </summary>
		/// <param name="name"> -> 플러그인 이름</param>
		/// <returns>있다면 true, 없으면 false</returns>
		bool CheckExistPlugin(const TString& name);

	private:

		/// <summary>
		/// 플러그인 정보를 담기위한 Map 인스턴스<para/>
		/// pair -> [플러그인 이름](Tstring), [플러그인 구조체](PluginItem)<para/>
		/// </summary>
		std::unordered_map<TString, std::shared_ptr<PluginItem>> _pluginItemsDic;

		/// <summary>
		/// Map 인스턴스를 멀티 스레드 환경 구현을 위한 뮤텍스
		/// </summary>
		std::mutex _pluginItemsMapMutex;
	};

}
#endif // !DECLARE_PLUGINLOADER_H