#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef USE_STD_CHRONO
#define USE_STD_CHRONO
#include <chrono>
#endif // !USE_STD_CHRONO

#ifndef USE_SHARED_LIBRARY_IOBJECTCLASS
#define USE_SHARED_LIBRARY_IOBJECTCLASS
#include "Shared_Library/ClassTemplate/Object/IObjectClass.h"
#endif // !USE_SHARED_LIBRARY_IOBJECTCLASS

#ifndef DECLARE_PLUGIN_TIME_ICLOCK
#define DECLARE_PLUGIN_TIME_ICLOCK
namespace plugin
{
	/// <summary>
	/// 시계 인터페이스<para/>
	/// 현재 시간을 제공하는 기본적인 시계 기능<para/>
	/// </summary>
	class IClock : public IObjectClass
	{
#pragma region interface

#pragma region Name
	public:
		/// <summary>
		/// Get
		/// </summary>
		[[nodiscard]] const std::wstring Name() const override = 0;
		/// <summary>
		/// Set
		/// </summary>
		void Name(const std::wstring& name) override = 0;
#pragma endregion

#pragma region Active
	public:
		/// <summary>
		/// Get
		/// </summary>
		[[nodiscard]] const bool Active() const override = 0;
	protected:
		/// <summary>
		/// Set
		/// </summary>
		void Active(const bool active) override = 0;
#pragma endregion

#pragma endregion

#pragma region Virtual destructor
	public:
		/// <summary>
		/// Virtual destructor.
		/// </summary>
		virtual ~IClock() = default;
#pragma endregion

#pragma region 1
#pragma endregion

#pragma region 2
#pragma endregion

	};
#pragma region className
	namespace className
	{
		static constexpr wchar_t IClockClassName[] = L"IClock";
	}
#pragma endregion
}
#endif // !DECLARE_PLUGIN_TIME_ICLOCK