#pragma once
#include <string>
#include "CoreEntryDefine.h"
#include "IObjectClass.h"

class DLL_API ITimer : public IObjectClass
{

#pragma region interface

public: // Name.

	/// <summary>
	/// Get Name.
	/// </summary>
	/// <returns> name </returns>
	[[nodiscard]] virtual const std::wstring Name() const override = 0;

	/// <summary>
	/// Set Name.
	/// </summary>
	/// <param name="name"> Log name. </param>
	virtual void Name(const std::wstring name) override = 0;

#pragma endregion

public:
	virtual void Start() = 0;
	virtual double ElapsedMilliseconds() const = 0;
};