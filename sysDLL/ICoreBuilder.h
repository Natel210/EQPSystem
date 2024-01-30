#pragma once
#include <memory>
#include "CoreEntryDefine.h"

class DLL_API ICoreBuilder : public std::enable_shared_from_this<ICoreBuilder>
{
public:
	virtual bool Init() = 0;
	virtual bool Start() = 0;
	virtual bool End() = 0;
	virtual bool Progress() = 0;
};

