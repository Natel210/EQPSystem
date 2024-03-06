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
#ifndef DECLARATION_DREAMSCENEBASE
#define DECLARATION_DREAMSCENEBASE
#pragma endregion

class DREAM_API DreamSceneBase : public DreamObjectBase, public IProgress, public ILogic
{
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMSCENEBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
	}
#else
}
}
#endif // _HAS_CXX17
#pragma endregion