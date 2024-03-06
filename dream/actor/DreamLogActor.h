#pragma once
#pragma region Include
#include "dream/definition/DreamHeader.h"
#include "dream/base/DreamActorBase.h"
#include "dream/component/DreamLogComponet.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::actor {
#else
namespace dream { namespace actor {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMLOGACTOR
#define DECLARATION_DREAMLOGACTOR
#pragma endregion

class DreamLogActor : public base::DreamActorBase
{
public:
    bool Initialize() final;
    bool Release() override;
protected:
    _NODISCARD std::shared_ptr<base::ObjectBase> Clone_ToObject() const override;
public:
    _NODISCARD std::shared_ptr<DreamLogActor> Clone();

public:
    bool LogComponent(std::shared_ptr<componet::DreamLogComponet> component);
    _NODISCARD std::shared_ptr<componet::DreamLogComponet> LogComponent() const;
    _NODISCARD std::shared_ptr<componet::DreamLogComponet> LogComponent();
public:
    DreamLogActor(const std::string& name, const std::string& classType = "DreamLogActor");
    DreamLogActor(const DreamLogActor& other);
    virtual ~DreamLogActor() = default;
private:
#if _HAS_CXX17
    static constexpr char _logComponentName[] = "logComponent";
#else
    static const char* _logComponentName;
#endif //_HAS_CXX17
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAMLOGACTOR
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}
#endif // _HAS_CXX17
#pragma endregion