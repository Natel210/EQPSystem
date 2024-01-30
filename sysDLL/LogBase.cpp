#include "LogBase.h"

const std::wstring LogBase::Name() const
{
    //std::wstring _header;
    //std::mutex _headerMutex;
    //std::vector<std::wstring> _commentList;
    //std::mutex _commentListMutex;

    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

const bool LogBase::Name(const std::wstring name)
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    if (_name.compare(name) == 0)
        return false;
    _name = name;
}

const eLogLevel LogBase::Level() const
{
    std::lock_guard<std::mutex> lock(_levelMutex);
    return _level;
}

const bool LogBase::Level(const eLogLevel leval)
{
    std::lock_guard<std::mutex> lock(_levelMutex);
    if (_level == level)
    {

    }
    return false;
}

const bool LogBase::Header(const std::wstring header)
{
    return false;
}

const std::wstring LogBase::Header() const
{
    return std::wstring();
}

const bool LogBase::Add(const std::wstring log)
{
    return false;
}

const bool LogBase::AddRange(const std::vector<std::wstring> list)
{
    return false;
}

const std::vector<std::wstring> LogBase::List() const
{
    return std::vector<std::wstring>();
}

const std::vector<std::wstring> LogBase::Return() const
{
    return std::vector<std::wstring>();
}
