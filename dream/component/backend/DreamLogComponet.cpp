#include "dream/component/DreamLogComponet.h"
namespace dream::componet
{
#ifndef DEFINITION_DREAMLOGCOMPONET
#define DEFINITION_DREAMLOGCOMPONET

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

    const ELogLevel DreamLogComponet::Level() const
    {
        std::lock_guard<std::mutex> lock(_levelMutex);
        return _level;
    }

    void DreamLogComponet::Level(const ELogLevel& leval)
    {
        std::lock_guard<std::mutex> lock(_levelMutex);
        _level = leval;
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
        std::string tempString = "";
        std::string getLevelName = typeid(Level()).name();
        tempString = "[" + getLevelName + "]" + comment;
        return tempString;
    }

    DreamLogComponet::DreamLogComponet(const std::string& name, const std::string& classType)
        : DreamComponentBase(name, classType)
    {
    }

    DreamLogComponet::DreamLogComponet(const DreamLogComponet& other)
        : DreamComponentBase(other)
    {
        Level(other.Level());
        auto otherList = other.List();
        std::lock_guard<std::mutex> lock(_logListMutex);
        for (const auto& item : *otherList)
            _logList.push_back(item);
    }
    
#endif // !DEFINITION_DREAMLOGCOMPONET
}