#include "MyDllPlugin.h"
CreatePluginHeaderCpp(TestDll_Plugin)
{
    return new MyDllPlugin();
}