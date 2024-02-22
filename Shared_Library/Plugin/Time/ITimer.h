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
	/// Ÿ�̸� �������̽�<para/>
	/// ������ �ð��� ����ߴ����� �˷��ִ� ���<para/>
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
		/// Ÿ�̸� ��� Ȱ��ȭ<para/>
		/// ������ interval ���� �ʿ�<para/>
		/// </summary>
		/// <param name="startTime"> > �⺻�� : Now</param>
		virtual void Start(const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// Ÿ�̸� ��� Ȱ��ȭ<para/>
		/// </summary>
		/// <param name="interval"> > �ֱ�</param>
		/// <param name="startTime"> > �⺻�� : Now</param>
		virtual void Start(const std::chrono::milliseconds& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// Ÿ�̸� ��� Ȱ��ȭ<para/>
		/// </summary>
		/// <param name="interval"> > �ֱ�</param>
		/// <param name="startTime"> > �⺻�� : Now</param>
		virtual void Start(const long long& interval, const std::chrono::steady_clock::time_point& startTime = std::chrono::steady_clock::now()) = 0;
		/// <summary>
		/// Ÿ�̸� ��� ��Ȱ��ȭ<para/>
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
		/// �ð� ��� üũ
		/// </summary>
		/// <returns>
		///  > true : �ð� ���<para/>
		///  > fasle : �ð� ����<para/>
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