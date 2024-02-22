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

#ifndef DECLARE_PLUGIN_TIME_ISTOPWATCH
#define DECLARE_PLUGIN_TIME_ISTOPWATCH
namespace plugin
{
	/// <summary>
	/// 스톱워치 인터페이스<para/>
	/// 특정 기간을 기준으로 얼마나 기간이 지났는지 알려주는 기능<para/>
	/// </summary>
	class IStopWatch : public IObjectClass
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
		virtual ~IStopWatch() = default;
#pragma endregion

#pragma region Start & End
		/// <summary>
		/// 스톱워치 기능 활성화<para/>
		/// </summary>
		/// <param name="startTime"> > 기본값 : Now</param>
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// 스톱워치 기능 비활성화<para/>
		/// </summary>
		virtual void End() = 0;
#pragma endregion

#pragma region Function
		/// <summary>
		/// YYYY. MM. DD _ HH : mm : ss : ms 정보<para/>
		/// </summary>
		virtual void GetDuration() = 0;

		/// <summary>
		/// YYYY. MM. DD 정보<para/>
		/// DD(일자) 단위 아래의 정보 버림<para/>
		/// </summary>
		virtual void GetDuration_toData() = 0;

		/// <summary>
		/// HH : mm : ss : ms 정보<para/>
		/// HH(시간) 단위 위의 정보는 시간에 추가되어 표기<para/>
		/// 1.0 = 24H<para/>
		/// </summary>
		virtual void GetDuration_toTime() = 0;

		/// <summary>
		/// 경과된 연단위
		/// </summary>
		virtual int GetElapsedYearsPeriod() = 0;
		/// <summary>
		/// 경과된 월단위
		/// </summary>
		virtual int GetDuration_toMonth() = 0;
		/// <summary>
		/// 경과된 주단위
		/// </summary>
		virtual int GetDuration_toWeek() = 0;
		/// <summary>
		/// 경과된 일단위
		/// </summary>
		virtual int GetDuration_toDay() = 0;
		/// <summary>
		/// 
		/// </summary>
		virtual void GetDuration_toHour() = 0;
		virtual void GetDuration_toMinute() = 0;
		virtual void GetDuration_toSeconds() = 0;
		virtual void GetDuration_toMilliseconds() = 0;



#pragma endregion

	};
#pragma region className
	namespace className
	{
		static constexpr wchar_t IStopWatchClassName[] = L"IStopWatch";
	}
#pragma endregion
}
#endif // !DECLARE_PLUGIN_TIME_ISTOPWATCH