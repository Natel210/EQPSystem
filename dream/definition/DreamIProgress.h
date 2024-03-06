#pragma once
#pragma region Include
#include "dream/definition/DreamHeader.h"
#pragma endregion
#pragma region Namespace
namespace dream {
#pragma endregion
#pragma region Avoid duplication
#ifndef DEFINITION_IPROGRESS
#define DEFINITION_IPROGRESS
#pragma endregion
	
class DREAM_API IProgress
{
public: // Progress ������Ʈ
    virtual void Progress_PrevUpdate() = 0;
    virtual void Progress_Update() = 0;
    virtual void Progress_AfterUpdate() = 0;
public: // Progress Trans(��ǥ��)
    virtual void Progress_Trans_PrevUpdate() = 0;
    virtual void Progress_Trans() = 0;
    virtual void Progress_Trans_AfterUpdate() = 0;
public: // Progress �浹
    virtual void Progress_Collision_PrevUpdate() = 0;
    virtual void Progress_Collision() = 0;
    virtual void Progress_Collision_AfterUpdate() = 0;
public: // Progress ������
    virtual void Progress_Render_PrevUpdate() = 0;
    virtual void Progress_Render() = 0;
    virtual void Progress_Render_AfterUpdate() = 0;
public:
	IProgress() = default;
	virtual ~IProgress() = default;
};

#pragma region Avoid duplication
#endif // !DEFINITION_IPROGRESS
#pragma endregion
#pragma region Namespace
}
#pragma endregion