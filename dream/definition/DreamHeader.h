#pragma once
#ifndef DECLARE_DREAM_API
#define DECLARE_DREAM_API
#ifdef DREAM_DLL_EXPORT
#define DREAM_API __declspec(dllexport)
#elif DREAM_DLL_IMPORT
#define DREAM_API __declspec(dllimport)
#else
#define DREAM_API
#endif
#endif // !DECLARE_DREAM_API

//include runtime header call defines 
#include <vcruntime.h>

// not nodiscard defined.
#ifndef _NODISCARD
#if _HAS_CXX17
#define DREAM_NODISCARD [[nodiscard]]
#else 
#define _NODISCARD
#endif //_HAS_CXX17
#endif // !_NODISCARD

