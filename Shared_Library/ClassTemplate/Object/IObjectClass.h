#pragma once

#ifndef USE_SHARED_LIBRARY_TSTRING
#define USE_SHARED_LIBRARY_TSTRING
#include "Shared_Library/String/TString.h"
#endif // !USE_SHARED_LIBRARY_TSTRING

#ifndef DECLARE_SHARED_LIBRARY_IOBJECTCLASS
#define DECLARE_SHARED_LIBRARY_IOBJECTCLASS
class IObjectClass
{

#pragma region Name

public:
	/// <summary>
	/// Get
	/// </summary>
	virtual [[nodiscard]] const TString Name() const = 0;

	/// <summary>
	/// Set
	/// </summary>
	virtual void Name(const TString& name) = 0;

#pragma endregion

#pragma region Active

public:
	/// <summary>
	/// Get
	/// </summary>
	virtual [[nodiscard]] const bool Active() const = 0;

protected:
	/// <summary>
	/// Set
	/// </summary>
	virtual void Active(const bool active) = 0;

#pragma endregion

public:
	/// <summary>
	/// Virtual destructor.
	/// </summary>
	virtual ~IObjectClass() = default;
};
#endif // !DECLARE_SHARED_LIBRARY_IOBJECTCLASS