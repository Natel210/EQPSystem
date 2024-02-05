#include "Log.h"
#include <format>
#include <functional>
#include "LogMangerSingleton.h"
const std::wstring Log::Name() const
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    return _name;
}

void Log::Name(const std::wstring& name)
{
    std::lock_guard<std::mutex> lock(_nameMutex);
    if (_name.compare(name) == 0)
        return;
    _name = name;
}

const bool Log::Active() const
{
    std::lock_guard<std::mutex> lock(_activeMutex);
    return _active;
}

void Log::Active(const bool active)
{
    std::lock_guard<std::mutex> lock(_activeMutex);
    _active = active;
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
    if (Active() == false)
        return;
    _commentList.push_back(LogFormatString(_level, _header, log));
}

void Log::AddRange(const std::vector<std::wstring> list)
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    if (Active() == false)
        return;
    for (auto item : list)
        _commentList.push_back(LogFormatString(_level, _header, item));
}

const std::shared_ptr<const std::vector<std::wstring>> Log::List() const
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    if (Active() == false)
        return nullptr;
    return std::make_shared<std::vector<std::wstring>>(_commentList);
}

const std::shared_ptr<const std::vector<std::wstring>> Log::Return()
{
    std::lock_guard<std::mutex> lock(_commentListMutex);
    if (Active() == false)
        return nullptr;
    auto resultList = std::make_shared<std::vector<std::wstring>>(_commentList);
    _commentList.clear(); // 원본 비움
    return resultList;
}

void Log::FormatFunction(std::function<const std::wstring(const ELogLevel, const std::wstring&, const std::wstring&)> formatFunction)
{
    std::lock_guard<std::mutex> lock(_formatFunctionMutex);
    if (formatFunction == nullptr)
        return;
    _formatFunction = formatFunction;
}

Log::Log()
{
    Active(true);
    FormatFunction([](const ELogLevel level, const std::wstring& header, const std::wstring& log) -> const std::wstring {
        return std::format(L"L:[{0}]\tH:{1}\tC:{2}\r\n", LogMangerSingleton::GetELogLeveltoString(level), header, log);
    });
}

Log::~Log()
{
    Active(false);
}

const bool Log::IsFunction() const
{
    std::lock_guard<std::mutex> lock(_formatFunctionMutex);
    if (_formatFunction == nullptr)
        return false;
    return true;
}

const std::wstring Log::LogFormatString(const ELogLevel level, const std::wstring& header, const std::wstring& log)
{
    std::lock_guard<std::mutex> lock(_formatFunctionMutex);
    if (_formatFunction == nullptr)
        return L"";
    return _formatFunction(level, header, log);
}

