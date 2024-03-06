#pragma once
#pragma region Include
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include "dream/object_frame/DreamObjectBase.h"
#include "dream/backend/core_frame/ActorCore.h"
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
#ifndef DECLARATION_DREAM_BACKEND_CORE_FRAME_LAYERCORE
#define DECLARATION_DREAM_BACKEND_CORE_FRAME_LAYERCORE
#pragma endregion

class LayerCore : public object_frame::ObjectBase
{
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAM_BACKEND_CORE_FRAME_LAYERCORE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}}
#endif // _HAS_CXX17
#pragma endregion
