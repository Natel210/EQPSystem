#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef USE_STD_FILESYSTEM
#define USE_STD_FILESYSTEM
#include <filesystem>
#endif // !USE_STD_FILESYSTEM


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

#ifndef USE_SHARED_LIBRARY_IOBJECTCLASS
#define USE_SHARED_LIBRARY_IOBJECTCLASS
#include "Shared_Library/ClassTemplate/Object/IObjectClass.h"
#endif // !USE_SHARED_LIBRARY_IOBJECTCLASS

#ifndef USE_SHARED_LIBRARY_IPLUGIN
#define USE_SHARED_LIBRARY_IPLUGIN
#include "Shared_Library/ClassTemplate/Plugin/IPlugin.h"
#endif // !USE_SHARED_LIBRARY_IPLUGIN

#ifndef USE_SHARED_LIBRARY_SINGLETONTEMPLATE
#define USE_SHARED_LIBRARY_SINGLETONTEMPLATE
#include "Shared_Library/ClassTemplate/Managing/SingletonTemplate.h"
#endif // !USE_SHARED_LIBRARY_SINGLETONTEMPLATE

#ifndef DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_H
#define DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_H
namespace plugin::manager
{
	/// <summary>
	/// 플러그인 로딩을 위한 싱글톤<para/>
	/// 멀티 쓰레딩 환경을 위한 적용이 되어있습니다.<para/>
	/// </summary>
	class Plugin_Loader : public SingletonTemplate<Plugin_Loader>, public IObjectClass
	{
#pragma region interface

#pragma region Name

	public:
		/// <summary>
		/// Get
		/// </summary>
		[[nodiscard]] const std::wstring Name() const final;

		/// <summary>
		/// Set
		/// </summary>
		void Name(const std::wstring& name);

#pragma endregion

#pragma region Active

	public:
		/// <summary>
		/// Get
		/// </summary>
		[[nodiscard]] const bool Active() const final;

	protected:
		/// <summary>
		/// Set
		/// </summary>
		void Active(const bool active) final;

#pragma endregion

#pragma endregion

	private:
		/// <summary>
		/// 플러그 인을 위한 DLL 모듈과 생성된 클래스의 구조체<para/>
		/// 이너 클래스 private<para/>
		/// </summary>
		struct Plugin_Item
		{
			HMODULE _module;
			std::shared_ptr<IPlugin> _class;
		};

	public:
		/// <summary>
		/// 플러그인 로딩
		/// </summary>
		/// <param name="name"> -> 플러그인 이름</param>
		/// <param name="path"> -> 플러그인 DLL 경로</param>
		/// <returns>성공 여부</returns>
		bool LoadPlugin(const std::wstring& name, const std::filesystem::path& path);

		/// <summary>
		/// 로딩된 플러그인 가져옵니다.
		/// </summary>
		/// <param name="name"> -> 플러그인 이름</param>
		/// <returns>없다면 nullptr </returns>
		std::shared_ptr<IPlugin> GetPlugin(const std::wstring& name);

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
		bool CheckExistPlugin(const std::wstring& name);

	private:
		std::wstring _name = L"Plugin Manager";
		bool _active = true;
		mutable std::mutex _nameMutex;
		mutable std::mutex _activeMutex;
	private:

		/// <summary>
		/// 플러그인 정보를 담기위한 Map 인스턴스<para/>
		/// pair -> [플러그인 이름](Tstring), [플러그인 구조체](Plugin_Item)<para/>
		/// </summary>
		std::unordered_map<std::wstring, std::shared_ptr<Plugin_Item>> _pluginItemsDic;

		/// <summary>
		/// Map 인스턴스를 멀티 스레드 환경 구현을 위한 뮤텍스
		/// </summary>
		std::mutex _pluginItemsMapMutex;
	};

}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_H