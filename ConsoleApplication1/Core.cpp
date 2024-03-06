#include "Core.h"

Core& Core::Get()
{
    static Core inst;
    return inst;
}

bool Core::Run()
{
    if (_run == false)
        return false;
    Progress();
    return true;
}

bool Core::Progress()
{
    return false;
}