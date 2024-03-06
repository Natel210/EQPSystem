#pragma once
#pragma region Include
#include <memory>
#include <vector>
#include <string>
#include "dream/object_frame/DreamObjectBase.h"
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
namespace dream::backend::core_frame {
#else
namespace dream {
    namespace backend {
        namespace core_frame {
#endif // _HAS_CXX17
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAM_ICOREFRAMECLASS
#define DECLARATION_DREAM_ICOREFRAMECLASS
#pragma endregion

class Dream_ICoreFrameClass
{
public://Super
    virtual std::weak_ptr<object_frame::DreamObjectBase> GetSuper() = 0;
public://Infer
    virtual std::weak_ptr<ui_frame::Object> GetInfer(std::string _name) = 0;
    virtual bool AddInfer(std::weak_ptr<ui_frame::Object> _object) = 0;
    virtual bool DelInfer(std::weak_ptr<ui_frame::Object> _object) = 0;
    virtual bool DelInfer(std::string _name) = 0;
public://Output
    virtual std::string GetSuperName() = 0;
    virtual std::vector<std::string> GetInferName() = 0;
protected:
    DreamICoreFrameClass() {}
    virtual ~DreamICoreFrameClass() = 0 {};
};

#pragma region Avoid duplication
#endif // !DECLARATION_DREAM_ICOREFRAMECLASS
#pragma endregion
#pragma region Namespace
#if _HAS_CXX17
}
#else
}}}
#endif // _HAS_CXX17
#pragma endregion