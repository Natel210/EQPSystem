#pragma once
#include <unordered_map>
#include <memory>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamIProgress.h"
#include "dream/definition/DreamILogic.h"
#include "dream/base/DreamObjectBase.h"
#include "dream/base/DreamComponentBase.h"
namespace dream::base
{
#ifndef DECLARATION_DREAMACTORBASE
#define DECLARATION_DREAMACTORBASE
	class DREAM_API DreamActorBase : public DreamObjectBase, public IProgress, public ILogic
	{

    public:
        bool Initialize() override;
        bool Release() override;
    protected:
        std::shared_ptr<DreamObjectBase> Clone_ToObject() const override;
    public:
        std::shared_ptr<DreamActorBase> Clone();

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

    private: // Progress 업데이트
        void Progress_PrevUpdate() final;
        void Progress_Update() final;
        void Progress_AfterUpdate() final;
    private: // Progress Trans(좌표계)
        void Progress_Trans_PrevUpdate() final;
        void Progress_Trans() final;
        void Progress_Trans_AfterUpdate() final;
    private: // Progress 충돌
        void Progress_Collision_PrevUpdate() final;
        void Progress_Collision() final;
        void Progress_Collision_AfterUpdate() final;
    private: // Progress 랜더링
        void Progress_Render_PrevUpdate() final;
        void Progress_Render() final;
        void Progress_Render_AfterUpdate() final;

    public:
        virtual void AddComponent(std::string name, std::shared_ptr<DreamComponentBase>component) final;
        virtual bool SwapComponent(std::string name, std::shared_ptr<DreamComponentBase>component) final;
        virtual void DelComponent(std::string name) final;
        virtual void ClearComponent() final;
    protected:
        virtual bool ExistComponent(std::string name) const final;
        virtual std::shared_ptr<DreamComponentBase> GetComponent(std::string name) final;
        virtual std::shared_ptr<DreamComponentBase> GetComponent(std::string name) const final;
    private:
        /// <summary> 유효하지 않는 컴포넌트들은 삭제 </summary>
        virtual void CleanupComponent() final;
    public:
        DreamActorBase(const std::string& name, const std::string& classType = "DreamActorBase");
        DreamActorBase(const DreamActorBase& other);
        virtual ~DreamActorBase() = default;
	private:
        std::unordered_map<std::string, std::shared_ptr<DreamComponentBase>> _componentList;
        mutable std::mutex _componentListMutex;
	};
#endif // !DECLARATION_DREAMACTORBASE
}