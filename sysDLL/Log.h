#pragma once
#include "ILog.h"
#include <string>
#include <mutex>
#include <vector>
#include <functional>
/// <summary>
/// Basement Log<para/>
/// </summary>
class Log : public ILog
{
#pragma region interface

#pragma region Name
public:
	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] const std::wstring Name() const final;
	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	void Name(const std::wstring& name) final;
#pragma endregion

#pragma region Active
public:
	/// <summary>
	/// Get Active.
	/// </summary>
	[[nodiscard]] const bool Active() const final;
protected:
	/// <summary>
	/// Set Active.
	/// </summary>
	void Active(const bool active) final;
#pragma endregion


#pragma region Preface

public: // Level.

	/// <summary>
	/// Get Level.
	/// </summary>
	/// <returns> Level </returns>
	[[nodiscard]] const ELogLevel Level() const final;

	/// <summary>
	/// Set Level.<para/>
	/// Comments already registered will be applied at the previous level.<para/>
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
	/// Set Header.<para/>
	/// Comments already registered will be applied at the previous Header.<para/>
	/// </summary>
	/// <param name="header"> Header. </param>
	void Header(const std::wstring header) final;

#pragma endregion

#pragma region Comment

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

	/// <summary>
	/// Format Func at One Line.
	/// </summary>
	void FormatFunction(std::function<const std::wstring(const ELogLevel, const std::wstring&, const std::wstring&)> formatFunction) final;

#pragma endregion

public:
	Log();
	~Log();
private:
	const bool IsFunction() const;
	const std::wstring LogFormatString(const ELogLevel level, const std::wstring& header, const std::wstring& log);
private: // member
	std::wstring _name = L"";
	bool _active = false;
	ELogLevel _level = ELogLevel::None;
	std::wstring _header = L"";
	std::vector<std::wstring> _commentList;
	std::function<const std::wstring(const ELogLevel, const std::wstring&, const std::wstring&)> _formatFunction = nullptr;
	mutable std::mutex _nameMutex;
	mutable std::mutex _activeMutex;
	mutable std::mutex _levelMutex;
	mutable std::mutex _headerMutex;
	mutable std::mutex _commentListMutex;
	mutable std::mutex _formatFunctionMutex;
};

