#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef DECLARE_SHARED_LIBRARY_IOBJECTCLASS
#define DECLARE_SHARED_LIBRARY_IOBJECTCLASS
class IObjectClass
{

#pragma region Name

public:
	/// <summary>
	/// Get
	/// </summary>
	virtual [[nodiscard]] const std::wstring Name() const = 0;

	/// <summary>
	/// Set
	/// </summary>
	virtual void Name(const std::wstring& name) = 0;

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