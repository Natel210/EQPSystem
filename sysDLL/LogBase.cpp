#include "LogBase.h"

const std::wstring LogBase::Name() const
{
    //std::wstring _name;
    //std::mutex _nameMutex;
    //std::wstring _header;
    //std::mutex _headerMutex;
    //std::vector<std::wstring> _commentList;
    //std::mutex _commentListMutex;

    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

const bool LogBase::Name(const std::wstring name)
{
    return false;
}

const eLogLevel LogBase::Level() const
{
    return eLogLevel();
}

const bool LogBase::Level(const eLogLevel leval)
{
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
