#include "MyDllPlugin.h"
CreatePluginHeader()
{
    return std::make_shared<MyDllPlugin>();
}