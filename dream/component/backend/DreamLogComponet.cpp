#include "dream/component/DreamLogComponet.h"
#pragma region Namespace
#if _HAS_CXX17
namespace dream::componet {
#else
namespace dream { namespace componet {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_DREAMLOGCOMPONET
#define DEFINITION_DREAMLOGCOMPONET
#pragma endregion

bool DreamLogComponet::Initialize()
{
    bool result = dream::base::DreamComponentBase::Initialize();
    if (result == true)
        Alive();
    return result;
}

bool DreamLogComponet::Release()
{
    bool result = dream::base::DreamComponentBase::Release();
    if (result == true)
        Kill();
    return result;
}

std::shared_ptr<base::DreamObjectBase> DreamLogComponet::Clone_ToObject() const
{
    return std::make_shared<DreamLogComponet>(*this);
}

std::shared_ptr<DreamLogComponet> DreamLogComponet::Clone()
{
    return std::dynamic_pointer_cast<DreamLogComponet>(Clone_ToObject());
}

void DreamLogComponet::AddLog(const std::string& comment)
{
    std::lock_guard<std::mutex> lock(_logListMutex);
    _logList.push_back(Format(comment));
}

void DreamLogComponet::AddLogsRange(const std::vector<std::string>& commentList)
{
    std::lock_guard<std::mutex> lock(_logListMutex);
    for (auto item : commentList)
        _logList.push_back(Format(item));
}

const std::shared_ptr<const std::vector<std::string>> DreamLogComponet::List() const
{
    std::lock_guard<std::mutex> lock(_logListMutex);
    return std::make_shared<std::vector<std::string>>(_logList);
}

void DreamLogComponet::Clear()
{
    std::lock_guard<std::mutex> lock(_logListMutex);
    _logList.clear();
}

const std::string DreamLogComponet::Format(const std::string& comment)
{
    return comment;
}

DreamLogComponet::DreamLogComponet(const std::string& name, const std::string& classType)
    : DreamComponentBase(name, classType)
{
}

DreamLogComponet::DreamLogComponet(const DreamLogComponet& other)
    : DreamComponentBase(other)
{
    auto otherList = other.List();
    std::lock_guard<std::mutex> lock(_logListMutex);
    for (const auto& item : *otherList)
        _logList.push_back(item);
}
    
#pragma region Avoid duplication
#endif // !DEFINITION_DREAMLOGCOMPONET
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion