#pragma once
#include <string>
#include <vector>


/// <summary>
/// Defines the level of logs.
/// </summary>
enum class eLogLevel
{
	None,
	Trace,
	Debug,
	Log,
	Info,
	Warnning,
	Error,
	Fatal,
};

/// <summary>
/// Log Interface.
/// </summary>
class ILog
{

public: // Name.

	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] virtual std::wstring Name() = 0;

	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	/// <returns> Success. </returns>
	virtual bool Name(std::wstring name) = 0;

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	[[nodiscard]] virtual eLogLevel Level() = 0;

	/// <summary>
	/// Set Level.
	/// </summary>
	/// <param name="leval"> Level </param>
	/// <returns> Success. </returns>
	virtual bool Level(eLogLevel leval) = 0;

public: // Log Text in out.

	/// <summary>
	/// Add additional log.
	/// </summary>
	/// <param name="log"> Add Log. </param>
	/// <returns> Success. </returns>
	virtual bool Add(std::wstring log) = 0;

	/// <summary>
	/// Add additional logs.
	/// </summary>
	/// <param name="list"> Add LogList. </param>
	/// <returns> Success. </returns>
	virtual bool AddRange(const std::vector<std::wstring> list) = 0;

	/// <summary>
	/// LogList Getting, don't clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual std::vector<std::wstring> List() = 0;

	/// <summary>
	/// LogList Getting, do clear.
	/// </summary>
	/// <returns> LogList. </returns>
	virtual [[nodiscard]] virtual std::vector<std::wstring>  Return() = 0;

};

