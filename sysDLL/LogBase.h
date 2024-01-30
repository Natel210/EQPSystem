#pragma once
#include "ILog.h"
#include <string>
#include <mutex>
#include <vector>

class LogBase : public ILog
{

public: // Name.

	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] const std::wstring Name() const final;

	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	/// <returns> Success. </returns>
	const bool Name(const std::wstring name) final;

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	[[nodiscard]] virtual const eLogLevel Level() const final;

	/// <summary>
	/// Set Level.
	/// </summary>
	/// <param name="leval"> Level </param>
	/// <returns> Success. </returns>
	virtual const bool Level(const eLogLevel leval) final;

public: // Header.

	/// <summary>
	/// Set Header.
	/// </summary>
	/// <param name="header"> Header. </param>
	/// <returns> Success. </returns>
	virtual const bool Header(const std::wstring header) final;

	/// <summary>
	/// Get Header.
	/// </summary>
	/// <returns> Header. </returns>
	virtual const std::wstring Header() const final;

public: // Log Text in out.

	/// <summary>
	/// Add additional log.
	/// </summary>
	/// <param name="log"> Add Log. </param>
	/// <returns> Success. </returns>
	virtual const bool Add(const std::wstring log) final;

	/// <summary>
	/// Add additional logs.
	/// </summary>
	/// <param name="list"> Add LogList. </param>
	/// <returns> Success. </returns>
	virtual const bool AddRange(const std::vector<std::wstring> list) final;

	/// <summary>
	/// LogList Getting, don't clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::vector<std::wstring> List() const final;

	/// <summary>
	/// LogList Getting, do clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::vector<std::wstring>  Return() const final;

private: // member
	std::wstring _name;
	mutable std::mutex _nameMutex;
	eLogLevel _level;
	mutable std::mutex _levelMutex;
	std::wstring _header;
	mutable std::mutex _headerMutex;
	std::vector<std::wstring> _commentList;
	mutable std::mutex _commentListMutex;
};

