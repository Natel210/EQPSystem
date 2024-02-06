#pragma once
// MyDllPlugin.cpp
#include "Plugin/Code/Share/IPlugin.h"
#include "Plugin/Code/Share/PluginExportHeader.h"
#include <iostream>

class PLUGIN_API MyDllPlugin : public plugin::share::IPlugin {
public:
    bool Init() override {
        std::cout << "dll" << std::endl;
        return true;
    }
};

