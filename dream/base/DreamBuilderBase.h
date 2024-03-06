#pragma once
#pragma region Include
#include "dream/base/DreamObjectBase.h"
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
#ifndef DECLARATION_DREAMBUILDERBASE
#define DECLARATION_DREAMBUILDERBASE
#pragma endregion
class DREAM_API DreamBuilderBase : public DreamObjectBase, public IProgress, public ILogic
{
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMBUILDERBASE
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion