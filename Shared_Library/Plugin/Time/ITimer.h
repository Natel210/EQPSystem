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

#ifndef DECLARE_PLUGIN_TIME_ITIMER
#define DECLARE_PLUGIN_TIME_ITIMER
namespace plugin
{
	/// <summary>
	/// 타이머 인터페이스<para/>
	/// 설정된 시간이 경과했는지를 알려주는 기능<para/>
	/// </summary>
	class ITimer : public IObjectClass
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
		virtual ~ITimer() = default;
#pragma endregion

#pragma region Start & End
		/// <summary>
		/// 타이머 기능 활성화<para/>
		/// 사전에 interval 설정 필요<para/>
		/// </summary>
		/// <param name="startTime"> > 기본값 : Now</param>
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// 타이머 기능 활성화<para/>
		/// </summary>
		/// <param name="interval"> > 주기</param>
		/// <param name="startTime"> > 기본값 : Now</param>
		virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// 타이머 기능 활성화<para/>
		/// </summary>
		/// <param name="interval"> > 주기</param>
		/// <param name="startTime"> > 기본값 : Now</param>
		virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// 타이머 기능 비활성화<para/>
		/// </summary>
		virtual void End() = 0;
#pragma endregion

#pragma region interval
		/// <summary>
		/// Get
		/// </summary>
		virtual const std::chrono::milliseconds Interval() const = 0;
		/// <summary>
		/// Set
		/// </summary>
		virtual void Interval(const std::chrono::milliseconds& interval) = 0;
		/// <summary>
		/// Set
		/// </summary>
		virtual void Interval(const long long& interval) = 0;
#pragma endregion

#pragma region Function
		/// <summary>
		/// 시간 경과 체크
		/// </summary>
		/// <returns>
		///  > true : 시간 경과<para/>
		///  > fasle : 시간 남음<para/>
		/// </returns>
		virtual bool IsOver() const = 0;
#pragma endregion

	};
#pragma region className
	namespace className
	{
		static constexpr wchar_t ITimerClassName[] = L"ITimer";
	}
#pragma endregion
}
#endif // !DECLARE_PLUGIN_TIME_ITIMER