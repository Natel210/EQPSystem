#pragma once
// MyDllPlugin.cpp
#include "Plugin/Share/IPlugin.h"
#include "Plugin/Share/PluginExportHeader.h"
#include <iostream>

class EXPORT_API MyDllPlugin : public plugin::share::IPlugin {
public:
    bool Init() override {
        std::cout << "dll" << std::endl;
        return true;
    }
};
CreatePluginHeader(TestDll_Plugin);

