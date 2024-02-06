#pragma once
#ifndef DECALRE_PLUGINEXPORTHEADER
#define DECALRE_PLUGINEXPORTHEADER
#ifdef PLUGIN_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif
#endif // !DECALRE_PLUGINEXPORTHEADER