#pragma once
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamLogEnum.h"
#include "dream/base/DreamActorBase.h"
#include "dream/component/DreamLogComponet.h"
namespace dream::actor
{
#ifndef DECLARATION_DREAMLOGACTOR
#define DECLARATION_DREAMLOGACTOR
	class DreamLogActor : public base::DreamActorBase
	{
    public:
        bool Initialize() final;
        bool Release() override;
    protected:
        std::shared_ptr<base::DreamObjectBase> Clone_ToObject() const override;
    public:
        std::shared_ptr<DreamLogActor> Clone();

    public:
        bool LogComponent(std::shared_ptr<componet::DreamLogComponet> component);
        std::shared_ptr<componet::DreamLogComponet> LogComponent() const;
        std::shared_ptr<componet::DreamLogComponet> LogComponent();
    public:
        DreamLogActor(const std::string& name, const std::string& classType = "DreamLogActor");
        DreamLogActor(const DreamLogActor& other);
        virtual ~DreamLogActor() = default;
    private:
        static constexpr char _logComponentName[] = "logComponent";
	};
#endif // !DECLARATION_DREAMLOGACTOR
}



