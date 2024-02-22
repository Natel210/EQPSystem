#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_TYPE_TRAITS
#define USE_TYPE_TRAITS
#include <type_traits>
#endif // !USE_TYPE_TRAITS

import "ObjectClass";

#ifndef USE_SHARED_LIBRARY_IOBJECTCLASS
#define USE_SHARED_LIBRARY_IOBJECTCLASS
#include "Shared_Library/ClassTemplate/Object/IObjectClass.h"
#endif // !USE_SHARED_LIBRARY_IOBJECTCLASS

#ifndef DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER
#define DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER
/// 플러그인 전용 생성 함수 해더 부분, 통상적인 함수 선언과 동일하게 사용하면 됩니다.
#define CreatePluginHeader(projectName) extern "C" __declspec(dllexport) plugin::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER

#ifndef DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER_CPP
#define DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER_CPP
/// 플러그인 전용 생성 함수 해더 부분, 통상적인 함수 선언과 동일하게 사용하면 됩니다.
#define CreatePluginHeaderCpp(projectName) plugin::IPlugin* Create##projectName##Plugin()
#endif // !DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER_CPP

#ifndef DECLARE_SHARED_LIBRARY_IPLUGIN
#define DECLARE_SHARED_LIBRARY_IPLUGIN
namespace plugin
{
    /// <summary>
    /// 플러그인 인터 페이스
    /// </summary>
    class IPlugin :public IObjectClass
    {
#pragma region interface

#pragma region Name

	public:
		/// <summary>
		/// Get
		/// </summary>
		virtual [[nodiscard]] const std::wstring Name() const = 0;

		/// <summary>
		/// Set
		/// </summary>
		virtual void Name(const std::wstring& name) = 0;

#pragma endregion

#pragma region Active

	public:
		/// <summary>
		/// Get
		/// </summary>
		virtual [[nodiscard]] const bool Active() const = 0;

	protected:
		/// <summary>
		/// Set
		/// </summary>
		virtual void Active(const bool active) = 0;

#pragma endregion

#pragma endregion

    public:
        virtual bool Init() = 0;

	public:
		/// <summary>
		/// 원하는 객체를 생성합니다.
		/// </summary>
		/// <param name="name">명칭</param>
		/// <param name="classType">클래스타입</param>
		/// <returns>실패 시 nullptr </returns>
		virtual std::shared_ptr<IObjectClass> CreateItem(const std::wstring name, const std::wstring classType) = 0;
		/// <summary>
		/// 원하는 객체를 제거합니다.
		/// </summary>
		/// <param name="name">명칭</param>
		/// <param name="classType">클래스타입</param>
		/// <returns>실패 시 false </returns>
		virtual const bool DeleteItem(const std::wstring name, const std::wstring classType) = 0;
		/// <summary>
		/// 원하는 객체를 가져옵니다.
		/// </summary>
		/// <param name="name">명칭</param>
		/// <param name="classType">클래스타입</param>
		/// <returns>실패 시 nullptr </returns>
		virtual std::shared_ptr<IObjectClass> GetIItem(const std::wstring name, const std::wstring classType) = 0;
    public:
        virtual ~IPlugin() = default;
    };
}
#endif // !DECLARE_SHARED_LIBRARY_IPLUGIN