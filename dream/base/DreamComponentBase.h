#pragma once
#pragma region Include
#include <unordered_map>
#include <memory>
#include <string>
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamILogic.h"
#include "dream/base/DreamObjectBase.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::base {
#else
namespace dream { namespace base {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMCOMPONENTBASE
#define DECLARATION_DREAMCOMPONENTBASE
#pragma endregion

class DREAM_API DreamComponentBase : public ObjectBase, protected ILogic
{
public:
    bool Initialize() override;
    bool Release() override;
protected:
    _NODISCARD std::shared_ptr<ObjectBase> Clone_ToObject() const override;
public:
    _NODISCARD std::shared_ptr<DreamComponentBase> Clone();
protected: // 업데이트
    void PrevUpdate() override;
    void Update() override;
    void AfterUpdate() override;
protected: // Trans(좌표계)
    void Trans_PrevUpdate() override;
    void Trans() override;
    void Trans_AfterUpdate() override;
protected: // 충돌
    void Collision_PrevUpdate() override;
    void Collision() override;
    void Collision_AfterUpdate() override;
protected: // 랜더링
    void Render_PrevUpdate() override;
    void Render() override;
    void Render_AfterUpdate() override;
public:
    DreamComponentBase(const std::string& name, const std::string& classType = "DreamComponentBase");
    virtual ~DreamComponentBase() = default;
    DreamComponentBase(const DreamComponentBase& other);
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMCOMPONENTBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion