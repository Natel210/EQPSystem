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
	/// �÷����� �ε��� ���� �̱���<para/>
	/// ��Ƽ ������ ȯ���� ���� ������ �Ǿ��ֽ��ϴ�.<para/>
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
		/// �÷��� ���� ���� DLL ���� ������ Ŭ������ ����ü<para/>
		/// �̳� Ŭ���� private<para/>
		/// </summary>
		struct Plugin_Item
		{
			HMODULE _module;
			std::shared_ptr<IPlugin> _class;
		};

	public:
		/// <summary>
		/// �÷����� �ε�
		/// </summary>
		/// <param name="name"> -> �÷����� �̸�</param>
		/// <param name="path"> -> �÷����� DLL ���</param>
		/// <returns>���� ����</returns>
		bool LoadPlugin(const std::wstring& name, const std::filesystem::path& path);

		/// <summary>
		/// �ε��� �÷����� �����ɴϴ�.
		/// </summary>
		/// <param name="name"> -> �÷����� �̸�</param>
		/// <returns>���ٸ� nullptr </returns>
		std::shared_ptr<IPlugin> GetPlugin(const std::wstring& name);

		///// <summary>
		///// �÷����� ��� ����
		///// </summary>
		///// <param name="name"> -> �÷����� �̸�</param>
		///// <returns>���� ���� ����</returns>
		//bool UnloadPlugin(const TString& name);

	private:
		/// <summary>
		/// �÷����� ���� ����
		/// </summary>
		/// <param name="name"> -> �÷����� �̸�</param>
		/// <returns>�ִٸ� true, ������ false</returns>
		bool CheckExistPlugin(const std::wstring& name);

	private:
		std::wstring _name = L"Plugin Manager";
		bool _active = true;
		mutable std::mutex _nameMutex;
		mutable std::mutex _activeMutex;
	private:

		/// <summary>
		/// �÷����� ������ ������� Map �ν��Ͻ�<para/>
		/// pair -> [�÷����� �̸�](Tstring), [�÷����� ����ü](Plugin_Item)<para/>
		/// </summary>
		std::unordered_map<std::wstring, std::shared_ptr<Plugin_Item>> _pluginItemsDic;

		/// <summary>
		/// Map �ν��Ͻ��� ��Ƽ ������ ȯ�� ������ ���� ���ؽ�
		/// </summary>
		std::mutex _pluginItemsMapMutex;
	};

}
#endif // !DECLARE_PLUGIN_MANAGER_PLUGIN_LOADER_H