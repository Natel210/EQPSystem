#include "Log.h"
#include <format>
#include "LogMangerSingleton.h"

const std::wstring Log::Name() const
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

void Log::Name(const std::wstring name)
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    if (_name.compare(name) == 0)
        return;
    _name = name;
}

const ELogLevel Log::Level() const
{
    std::lock_guard<std::mutex> lock(_levelMutex);
    return _level;
}

void Log::Level(const ELogLevel leval)
{
    std::lock_guard<std::mutex> lock(_levelMutex);
    if (_level == leval)
        return;
    _level = leval;
}

const std::wstring Log::Header() const
{
    std::lock_guard<std::mutex> lock(_headerMutex);
    return _header;
}

void Log::Header(const std::wstring header)
{
    std::lock_guard<std::mutex> lock(_headerMutex);
    if (_header.compare(_header) == 0)
        return;
    _header = header;
}

void Log::Add(const std::wstring log)
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    _commentList.push_back(LogFormatString(_level, _header, log));
}

void Log::AddRange(const std::vector<std::wstring> list)
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    for (auto item : list)
        _commentList.push_back(LogFormatString(_level, _header, item));
}

const std::shared_ptr<const std::vector<std::wstring>> Log::List() const
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    return std::make_shared<std::vector<std::wstring>>(_commentList);
}

const std::shared_ptr<const std::vector<std::wstring>> Log::Return()
{
    std::lock_guard<std::mutex> lock(_commentListMutex);

    auto resultList = std::make_shared<std::vector<std::wstring>>(_commentList);
    _commentList.clear(); // 원본 비움
    return resultList;
}

const std::wstring Log::LogFormatString(const ELogLevel level, const std::wstring header, const std::wstring log)
{
    return std::format(L"L:[{0}]\tH:{1}\tC:{2}", LogMangerSingleton::GetELogLeveltoString(level), header, log);
}

