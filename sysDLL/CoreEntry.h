#pragma once
#include "CoreEntryDefine.h"
#include "ICoreBuilder.h"
class DLL_API CoreEntry
{
	static const bool Create(ICoreBuilder* coreBuilder = nullptr);
	static const bool Init(ICoreBuilder* coreBuilder);
	[[nodiscard]] static const bool IsInit();
	static const bool Start();
	static const bool End();
	[[nodiscard]] static const bool IsRunning();
};

