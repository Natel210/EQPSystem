#pragma once
#include "CoreEntryDefine.h"
#include <string>
/// <summary>
/// Defines the level of logs.
/// </summary>
enum class DLL_API ELogLevel
{
	None,
	Trace,
	Debug,
	Log,
	Info,
	Warning,
	Error,
	Fatal,
};

