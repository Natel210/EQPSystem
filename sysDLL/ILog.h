#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "CoreEntryDefine.h"
#include "ELogLevel.h"
#include "IObjectClass.h"

/// <summary>
/// Log Interface.
/// </summary>
class DLL_API ILog : public IObjectClass
{

#pragma region Super

#pragma region Name
public:
	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	virtual [[nodiscard]] const std::wstring Name() const = 0;
	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	virtual void Name(const std::wstring& name) = 0;
#pragma endregion

#pragma region Active
public:
	/// <summary>
	/// Get Active.
	/// </summary>
	virtual [[nodiscard]] const bool Active() const = 0;
protected:
	/// <summary>
	/// Set Active.
	/// </summary>
	virtual void Active(const bool active) = 0;
#pragma endregion

#pragma endregion

#pragma region Preface

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	virtual [[nodiscard]] const ELogLevel Level() const = 0;

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

public:

	/// <summary>
	/// Format Func at One Line.
	/// </summary>
	virtual void FormatFunction(std::function<const std::wstring(const ELogLevel, const std::wstring&, const std::wstring&)> formatFunction) = 0;

#pragma endregion

#pragma region Comment

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

#pragma endregion

public:
	/// <summary>
	/// Virtual destructor.
	/// </summary>
	virtual ~ILog() = default;
};

