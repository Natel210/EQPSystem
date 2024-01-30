#include "Core.h"

const bool Core::Init(std::weak_ptr<ICoreBuilder> coreBuilder)
{
	if (coreBuilder.expired() == true)
	{
		_coreBuilder = coreBuilder.lock();
		_isInit = _coreBuilder->Init();
	}
	else
		_isInit = false;

	return IsInit();
}

const bool Core::IsInit() const
{
	return _isInit ;
}

const bool Core::Start()
{
	if (IsInit() == false)
		return false;
	return _coreBuilder->Start();
}

const bool Core::End()
{
	if (IsRunning() == false)
		return false;
	return _coreBuilder->End();
}

const bool Core::IsRunning() const
{
	return _isRunning;
}

void Core::Progress()
{
	if (IsRunning() == true)
		_coreBuilder->Progress();
}
