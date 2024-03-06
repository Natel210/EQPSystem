#pragma once
#pragma region Include
#include "dream/base/DreamObjectBase.h"
#include "dream/definition/DreamIProgress.h"
#include "dream/definition/DreamILogic.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::base {
#else
namespace dream {
	namespace base {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMLAYERBASE
#define DECLARATION_DREAMLAYERBASE
#pragma endregion

class DREAM_API DreamLayerBase : public DreamObjectBase, public IProgress, public ILogic
{
public:
    bool Initialize() override;
    bool Release() override;
protected:
    _NODISCARD std::shared_ptr<DreamObjectBase> Clone_ToObject() const override;
public:
    _NODISCARD std::shared_ptr<DreamLayerBase> Clone();

};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMLAYERBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion

#pragma region Example
/*




*/
#pragma endregion