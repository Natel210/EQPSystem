#pragma once
#include <memory>
#include "ICore.h"
#include "ICoreBuilder.h"
class Core : public ICore
{
private:
	std::shared_ptr<ICoreBuilder> _coreBuilder = nullptr;
	bool _isInit = false;
	bool _isRunning = false;
#pragma region Interface
public:
	virtual const bool Init(std::weak_ptr<ICoreBuilder> coreBuilder) final;
	[[nodiscard]] virtual const bool IsInit() const final;
	virtual const bool Start() final;
	virtual const bool End() final;
	[[nodiscard]] virtual const bool IsRunning() const final;
#pragma endregion
public:
	virtual void Progress() final;
};

