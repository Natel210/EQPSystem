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