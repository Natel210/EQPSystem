#pragma once
#include <string>
#include "CoreEntryDefine.h"
class DLL_API IObjectClass
{

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

public:
	/// <summary>
	/// Virtual destructor.
	/// </summary>
	virtual ~IObjectClass() = default;
};

