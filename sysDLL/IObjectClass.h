#pragma once
#include <string>
#include "CoreEntryDefine.h"
class DLL_API IObjectClass
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
};

