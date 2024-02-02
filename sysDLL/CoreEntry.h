#pragma once
#include "CoreEntryDefine.h"
#include "ICoreBuilder.h"
#include <memory>

class DLL_API CoreEntry
{
	static const bool Create(std::shared_ptr<ICoreBuilder> coreBuilder);
	static const bool Init(std::shared_ptr<ICoreBuilder> coreBuilder);
	[[nodiscard]] static const bool IsInit();
	static const bool Start();
	static const bool End();
	[[nodiscard]] static const bool IsRunning();
};

