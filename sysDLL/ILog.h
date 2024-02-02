#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CoreEntryDefine.h"
#include "ELogLevel.h"

/// <summary>
/// Log Interface.
/// </summary>
class DLL_API ILog
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
	[[nodiscard]] virtual const ELogLevel Level() const = 0;

	/// <summary>
	/// Set Level.<para/>
	/// Comments already registered will be applied at the previous level.<para/>
	/// </summary>
	/// <param name="leval"> Level </param>
	virtual void Level(const ELogLevel leval) = 0;

public: // Header.

	/// <summary>
	/// Get Header.
	/// </summary>
	/// <returns> Header. </returns>
	virtual const std::wstring Header() const = 0;

	/// <summary>
	/// Set Header.<para/>
	/// Comments already registered will be applied at the previous Header.<para/>
	/// </summary>
	/// <param name="header"> Header. </param>
	virtual void Header(const std::wstring header) = 0;

public: // Log Text in out.

	/// <summary>
	/// Add additional log.
	/// </summary>
	/// <param name="log"> Add Log. </param>
	virtual void Add(const std::wstring log) = 0;

	/// <summary>
	/// Add additional logs.
	/// </summary>
	/// <param name="list"> Add LogList. </param>
	virtual void AddRange(const std::vector<std::wstring> list) = 0;

	/// <summary>
	/// LogList Getting, don't clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::shared_ptr<const std::vector<std::wstring>> List() const = 0;

	/// <summary>
	/// LogList Getting, do clear.
	/// </summary>
	/// <returns> LogList. </returns>
	[[nodiscard]] virtual const std::shared_ptr<const std::vector<std::wstring>> Return() = 0;

};

