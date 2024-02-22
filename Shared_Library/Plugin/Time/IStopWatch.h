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
	/// �����ġ �������̽�<para/>
	/// Ư�� �Ⱓ�� �������� �󸶳� �Ⱓ�� �������� �˷��ִ� ���<para/>
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
		/// �����ġ ��� Ȱ��ȭ<para/>
		/// </summary>
		/// <param name="startTime"> > �⺻�� : Now</param>
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// �����ġ ��� ��Ȱ��ȭ<para/>
		/// </summary>
		virtual void End() = 0;
#pragma endregion

#pragma region Function
		/// <summary>
		/// YYYY. MM. DD _ HH : mm : ss : ms ����<para/>
		/// </summary>
		virtual void GetDuration() = 0;

		/// <summary>
		/// YYYY. MM. DD ����<para/>
		/// DD(����) ���� �Ʒ��� ���� ����<para/>
		/// </summary>
		virtual void GetDuration_toData() = 0;

		/// <summary>
		/// HH : mm : ss : ms ����<para/>
		/// HH(�ð�) ���� ���� ������ �ð��� �߰��Ǿ� ǥ��<para/>
		/// 1.0 = 24H<para/>
		/// </summary>
		virtual void GetDuration_toTime() = 0;

		/// <summary>
		/// ����� ������
		/// </summary>
		virtual int GetElapsedYearsPeriod() = 0;
		/// <summary>
		/// ����� ������
		/// </summary>
		virtual int GetDuration_toMonth() = 0;
		/// <summary>
		/// ����� �ִ���
		/// </summary>
		virtual int GetDuration_toWeek() = 0;
		/// <summary>
		/// ����� �ϴ���
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