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
	/// �÷����� �ε��� ���� �̱���<para/>
	/// ��Ƽ ������ ȯ���� ���� ������ �Ǿ��ֽ��ϴ�.<para/>
	/// </summary>
	class PluginLoader : public SingletonTemplate<PluginLoader>
	{
	private:
		/// <summary>
		/// �÷��� ���� ���� DLL ���� ������ Ŭ������ ����ü<para/>
		/// �̳� Ŭ���� private<para/>
		/// </summary>
		struct PluginItem
		{
			HMODULE _module;
			std::shared_ptr<share::IPlugin> _class;
		};

	public:
		/// <summary>
		/// �÷����� �ε�
		/// </summary>
		/// <param name="name"> -> �÷����� �̸�</param>
		/// <param name="path"> -> �÷����� DLL ���</param>
		/// <returns>���� ����</returns>
		bool LoadPlugin(const TString& name, const std::filesystem::path& path);

		/// <summary>
		/// �ε��� �÷����� �����ɴϴ�.
		/// </summary>
		/// <param name="name"> -> �÷����� �̸�</param>
		/// <returns>���ٸ� nullptr </returns>
		std::shared_ptr<share::IPlugin> GetPlugin(const TString& name);

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
		bool CheckExistPlugin(const TString& name);

	private:

		/// <summary>
		/// �÷����� ������ ������� Map �ν��Ͻ�<para/>
		/// pair -> [�÷����� �̸�](Tstring), [�÷����� ����ü](PluginItem)<para/>
		/// </summary>
		std::unordered_map<TString, std::shared_ptr<PluginItem>> _pluginItemsDic;

		/// <summary>
		/// Map �ν��Ͻ��� ��Ƽ ������ ȯ�� ������ ���� ���ؽ�
		/// </summary>
		std::mutex _pluginItemsMapMutex;
	};

}
#endif // !DECLARE_PLUGINLOADER_H