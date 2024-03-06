#pragma once
#pragma region Include
#include "dream/definition/DreamHeader.h"
#pragma endregion
#pragma region Namespace
namespace dream {
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_ILOGIC
#define DEFINITION_ILOGIC
#pragma endregion

class DREAM_API ILogic
{
public: // 업데이트
    virtual void PrevUpdate() = 0;
    virtual void Update() = 0;
    virtual void AfterUpdate() = 0;
public: // Trans(좌표계)
    virtual void Trans_PrevUpdate() = 0;
    virtual void Trans() = 0;
    virtual void Trans_AfterUpdate() = 0;
public: // 충돌
    virtual void Collision_PrevUpdate() = 0;
    virtual void Collision() = 0;
    virtual void Collision_AfterUpdate() = 0;
public: // 랜더링
    virtual void Render_PrevUpdate() = 0;
    virtual void Render() = 0;
    virtual void Render_AfterUpdate() = 0;
public:
    ILogic() = default;
    virtual ~ILogic() = default;
};

#pragma region Avoid duplication
#endif // !DEFINITION_ILOGIC
#pragma endregion
#pragma region Namespace
}
#pragma endregion