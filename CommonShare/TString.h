#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef USE_WINDOW_TCHAR
#define USE_WINDOW_TCHAR
#include <tchar.h>
#endif // !USE_WINDOW_TCHAR

#ifndef USE_STD_IOSTREAM
#define USE_STD_IOSTREAM
#include <iostream>
#endif // !USE_STD_IOSTREAM

#ifndef USE_STD_LOCALE
#define USE_STD_LOCALE
#include <locale>
#endif // !USE_STD_LOCALE

#ifndef DECLARE_TSTRING
#define DECLARE_TSTRING
typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> TString;
#endif // !DECLARE_TSTRING

#ifndef DECLARE_TSTRINGSTREAM
#define DECLARE_TSTRINGSTREAM
typedef std::basic_stringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>> TStringstream;
#endif // !DECLARE_TSTRINGSTREAM

#ifndef DECLARE_TO_TSTRING
#define DECLARE_TO_TSTRING
#ifdef _UNICODE
#define TO_TSTRING std::to_wstring
#else
#define TO_TSTRING std::to_string
#endif // _UNICODE
#endif // !DECLARE_TO_TSTRING

#ifndef DECLARE_TCOUT
#define DECLARE_TCOUT
#ifdef _UNICODE
#define TCOUT std::wcout
#else
#define TCOUT std::cout
#endif // _UNICODE
#endif // !DECLARE_TCOUT

#ifndef DECLARE_TCIN
#define DECLARE_TCIN
#ifdef _UNICODE
#define TCIN std::wcin
#else
#define TCIN std::cin
#endif // _UNICODE
#endif // !DECLARE_TCIN

#ifndef DECLARE_TCERR
#define DECLARE_TCERR
#ifdef _UNICODE
#define TCERR std::wcerr
#else
#define TCERR std::cerr
#endif // _UNICODE
#endif // !DECLARE_TCERR

#ifndef DECLARE_IMBUE_LANGUAGE
#define DECLARE_IMBUE_LANGUAGE
#define IMBUE_LANGUAGE(strLanguage) TCin.imbue(std::locale(strLanguage)); TCout.imbue(std::locale(strLanguage));
#endif // !DECLARE_IMBUE_LANGUAGE