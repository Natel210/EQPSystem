#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamILogic.h"
#include "dream/base/DreamObjectBase.h"
namespace dream::base
{
#ifndef DECLARATION_DREAMCOMPONENTBASE
#define DECLARATION_DREAMCOMPONENTBASE
	class DREAM_API DreamComponentBase : public DreamObjectBase, public ILogic
	{
    public:
        bool Initialize() override;
        bool Release() override;
    protected:
        std::shared_ptr<DreamObjectBase> Clone_ToObject() const override;
    public:
        std::shared_ptr<DreamComponentBase> Clone();
    private: // 업데이트
        void PrevUpdate() override;
        void Update() override;
        void AfterUpdate() override;
    private: // Trans(좌표계)
        void Trans_PrevUpdate() override;
        void Trans() override;
        void Trans_AfterUpdate() override;
    private: // 충돌
        void Collision_PrevUpdate() override;
        void Collision() override;
        void Collision_AfterUpdate() override;
    private: // 랜더링
        void Render_PrevUpdate() override;
        void Render() override;
        void Render_AfterUpdate() override;
    public:
        DreamComponentBase(const std::string& name, const std::string& classType = "DreamComponentBase");
        virtual ~DreamComponentBase() = default;
        DreamComponentBase(const DreamComponentBase& other);
	};
#endif // !DECLARATION_DREAMCOMPONENTBASE
}