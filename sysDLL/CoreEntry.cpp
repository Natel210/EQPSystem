#include "CoreEntry.h"
#include "Core.h"

class InnerCoreEntry : public ICore
{
private:
	std::shared_ptr<Core> _core = nullptr;
#pragma region Interface
public:
	virtual const bool Init(std::weak_ptr<ICoreBuilder> coreBuilder) final
	{
		if (_core == nullptr)
			_core = std::make_shared<Core>();
		_core->Init(coreBuilder);
	}
	[[nodiscard]] virtual const bool IsInit() const final
	{
		if (_core == nullptr)
			return false;
		return _core->IsInit();
	}
	virtual const bool Start() final
	{
		if (_core == nullptr)
			return false;
		return _core->Start();
	}
	virtual const bool End() final
	{
		if (_core == nullptr)
			return false;
		bool result = _core->End();
		_core.reset();
		return result;
	}
	[[nodiscard]] virtual const bool IsRunning() const final
	{
		if (_core == nullptr)
			return false;
		return _core->IsRunning();
	}
#pragma endregion
public:
	InnerCoreEntry()
	{
		_core.reset();
	}
	~InnerCoreEntry()
	{
		_core.reset();
	}
};
static std::shared_ptr<InnerCoreEntry> _innerCoreEntry = nullptr;

const bool CoreEntry::Create(ICoreBuilder* coreBuilder/* = nullptr*/)
{
	_innerCoreEntry = std::make_shared<InnerCoreEntry>();
	if (_innerCoreEntry == nullptr)
		return false;
	if (coreBuilder != nullptr)
		return Init(coreBuilder);
	return true;
}

const bool CoreEntry::Init(ICoreBuilder* coreBuilder)
{
	if (_innerCoreEntry == nullptr)
		return false;
	// coreBuilder가 nullptr인지 확인
	if (coreBuilder == nullptr)
		return false;
	// coreBuilder의 shared_ptr을 얻음
	std::shared_ptr<ICoreBuilder> sharedBuilder = coreBuilder->shared_from_this();

	return _innerCoreEntry->Init(sharedBuilder);
}

const bool CoreEntry::IsInit()
{
	if (_innerCoreEntry == nullptr)
		return;
	return _innerCoreEntry->IsInit();
}

const bool CoreEntry::Start()
{
	if (_innerCoreEntry == nullptr)
		return;
	return _innerCoreEntry->Start();
}

const bool CoreEntry::End()
{
	if (_innerCoreEntry == nullptr)
		return;
	return _innerCoreEntry->End();
}

const bool CoreEntry::IsRunning()
{
	if (_innerCoreEntry == nullptr)
		return;
	return _innerCoreEntry->IsRunning();
}
