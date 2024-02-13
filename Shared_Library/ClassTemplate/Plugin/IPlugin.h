#pragma once

#ifndef USE_STD_MEMORY
#define USE_STD_MEMORY
#include <memory>
#endif // !USE_STD_MEMORY

#ifndef USE_TYPE_TRAITS
#define USE_TYPE_TRAITS
#include <type_traits>
#endif // !USE_TYPE_TRAITS

#ifndef USE_SHARED_LIBRARY_IOBJECTCLASS
#define USE_SHARED_LIBRARY_IOBJECTCLASS
#include "Shared_Library/ClassTemplate/Object/IObjectClass.h"
#endif // !USE_SHARED_LIBRARY_IOBJECTCLASS

#ifndef USE_SHARED_LIBRARY_TSTRING
#define USE_SHARED_LIBRARY_TSTRING
#include "Shared_Library/String/TString.h"
#endif // !USE_SHARED_LIBRARY_TSTRING

#ifndef DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER
#define DECLARE_SHARED_LIBRARY_CREATEPLUGINHEADER
/// 플러그인 전용 생성 함수 해더 부분, 통상적인 함수 선언과 동일하게 사용하면 됩니다.
#define CreatePluginHeader(projectName, Export_Name) extern "C" plugin::IPlugin* Create##projectName##Plugin()
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
		virtual [[nodiscard]] const TString Name() const = 0;

		/// <summary>
		/// Set
		/// </summary>
		virtual void Name(const TString& name) = 0;

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
        virtual ~IPlugin() = default;
    };
}
#endif // !DECLARE_SHARED_LIBRARY_IPLUGIN





