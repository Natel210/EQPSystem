#pragma once
#pragma region Include
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include "dream/object_frame/DreamObjectBase.h"
#include "dream/backend/core_frame/LayerCore.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::backend::core_frame {
#else
namespace dream {
    namespace backend {
        namespace core_frame {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAM_BACKEND_CORE_FRAME_SCENECORE
#define DECLARATION_DREAM_BACKEND_CORE_FRAME_SCENECORE
#pragma endregion

class SceneCore : public object_frame::ObjectBase
{
public: // 업데이트
    virtual void PrevUpdate() final;
    virtual void Update() final;
    virtual void AfterUpdate() final;
public: // Trans(좌표계)
    virtual void Trans_PrevUpdate() final;
    virtual void Trans() final;
    virtual void Trans_AfterUpdate() final;
public: // 충돌
    virtual void Collision_PrevUpdate() final;
    virtual void Collision() final;
    virtual void Collision_AfterUpdate() final;
public: // 랜더링
    virtual void Render_PrevUpdate() final;
    virtual void Render() final;
    virtual void Render_AfterUpdate() final;


private:
    std::list<std::shared_ptr<dream::backend::core_frame::LayerCore>> layerList;

};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAM_BACKEND_CORE_FRAME_SCENECORE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}}
#endif // _HAS_CXX17
#pragma endregion
