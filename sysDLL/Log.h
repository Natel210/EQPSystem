#pragma once
#include "ILog.h"
#include <string>
#include <mutex>
#include <vector>

/// <summary>
/// Basement Log<para/>
/// </summary>
class Log : public ILog
{
#pragma region interface

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
	void Name(const std::wstring name) final;

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	[[nodiscard]] const ELogLevel Level() const final;

	/// <summary>
	/// Set Level.
	/// </summary>
	/// <param name="leval"> Level </param>
	void Level(const ELogLevel leval) final;

public: // Header.

	/// <summary>
	/// Get Header.
	/// </summary>
	/// <returns> Header. </returns>
	const std::wstring Header() const final;

	/// <summary>
	/// Set Header.
	/// </summary>
	/// <param name="header"> Header. </param>
	void Header(const std::wstring header) final;

public: // Log Text in out.

	/// <summary>
	/// Add additional log.
	/// </summary>
	/// <param name="log"> Add Log. </param>
	void Add(const std::wstring log) final;

	/// <summary>
	/// Add additional logs.
	/// </summary>
	/// <param name="list"> Add LogList. </param>
	void AddRange(const std::vector<std::wstring> list) final;

	/// <summary>
	/// LogList Getting, don't clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] const std::shared_ptr<const std::vector<std::wstring>> List() const final;

	/// <summary>
	/// LogList Getting, do clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] const std::shared_ptr<const std::vector<std::wstring>> Return() final;

#pragma endregion

private:
	const std::wstring LogFormatString(const ELogLevel level, const std::wstring header, const std::wstring log);
private: // member
	std::wstring _name = L"";
	ELogLevel _level = ELogLevel::None;
	std::wstring _header = L"";
	std::vector<std::wstring> _commentList;
	mutable std::mutex _nameMutex;
	mutable std::mutex _levelMutex;
	mutable std::mutex _headerMutex;
	mutable std::mutex _commentListMutex;
};

