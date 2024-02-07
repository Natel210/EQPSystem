#pragma once

#ifndef USE_COMMON_TSTRING
#define USE_COMMON_TSTRING
#include "CommonShare/TString.h"
#endif // !USE_COMMON_TSTRING

#ifndef USE_PLUGIN_PLUGINEXPORTHEADER
#define USE_PLUGIN_PLUGINEXPORTHEADER
#include "Plugin/Share/PluginExportHeader.h"
#endif // !USE_PLUGIN_PLUGINEXPORTHEADER

class PLUGIN_API IObjectClass
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

