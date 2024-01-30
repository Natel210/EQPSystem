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
	[[nodiscard]] virtual const std::wstring Name() const = 0;

	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	virtual void Name(const std::wstring name) = 0;

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	[[nodiscard]] virtual const eLogLevel Level() const = 0;

	/// <summary>
	/// Set Level.
	/// </summary>
	/// <param name="leval"> Level </param>
	virtual void Level(const eLogLevel leval) = 0;

public: // Header.

	/// <summary>
	/// Set Header.
	/// </summary>
	/// <param name="header"> Header. </param>
	virtual void Header(const std::wstring header) = 0;

	/// <summary>
	/// Get Header.
	/// </summary>
	/// <returns> Header. </returns>
	virtual const std::wstring Header() const = 0;

public: // Log Text in out.

	/// <summary>
	/// Add additional log.
	/// </summary>
	/// <param name="log"> Add Log. </param>
	/// <returns> Success. </returns>
	virtual const bool Add(const std::wstring log) = 0;

	/// <summary>
	/// Add additional logs.
	/// </summary>
	/// <param name="list"> Add LogList. </param>
	/// <returns> Success. </returns>
	virtual const bool AddRange(const std::vector<std::wstring> list) = 0;

	/// <summary>
	/// LogList Getting, don't clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::vector<std::wstring> List() const = 0;

	/// <summary>
	/// LogList Getting, do clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::vector<std::wstring>  Return() const = 0;

};

