#pragma once
#include "CoreEntryDefine.h"
#include "ICoreBuilder.h"

/// <summary>
/// �ھ ���� ������ �Լ�
/// </summary>
class DLL_API ICore
{
public:
	virtual const bool Init(std::shared_ptr<ICoreBuilder> coreBuilder) = 0;
	[[nodiscard]] virtual const bool IsInit() const = 0;
	virtual const bool Start() = 0;
	virtual const bool End() = 0;
	[[nodiscard]] virtual const bool IsRunning() const = 0;
};

