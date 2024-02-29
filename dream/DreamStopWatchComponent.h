#pragma once
#include <chrono>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamLogEnum.h"
#include "dream/base/DreamComponentBase.h"
namespace dream::componet
{
#ifndef DECLARATION_DREAMSTOPWATCHCOMPONENT
#define DECLARATION_DREAMSTOPWATCHCOMPONENT
	class DREAM_API DreamStopWatchComponent : public base::DreamComponentBase
	{
	public:
		bool Initialize() final;
		bool Release() final;
	protected:
		std::shared_ptr<base::DreamObjectBase> Clone_ToObject() const override;
	public:
		std::shared_ptr<DreamStopWatchComponent> Clone();
	public:

	public:
		DreamStopWatchComponent(const std::string& name, const std::string& classType = "DreamStopWatchComponent");
		virtual ~DreamStopWatchComponent() = default;
		DreamStopWatchComponent(const DreamStopWatchComponent& other);
	};
#endif // !DECLARATION_DREAMSTOPWATCHCOMPONENT
}