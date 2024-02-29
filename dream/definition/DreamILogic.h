#pragma once
namespace dream
{
#ifndef DEFINITION_ILOGIC
#define DEFINITION_ILOGIC
	class ILogic
	{
    public: // ������Ʈ
        virtual void PrevUpdate() = 0;
        virtual void Update() = 0;
        virtual void AfterUpdate() = 0;
    public: // Trans(��ǥ��)
        virtual void Trans_PrevUpdate() = 0;
        virtual void Trans() = 0;
        virtual void Trans_AfterUpdate() = 0;
    public: // �浹
        virtual void Collision_PrevUpdate() = 0;
        virtual void Collision() = 0;
        virtual void Collision_AfterUpdate() = 0;
    public: // ������
        virtual void Render_PrevUpdate() = 0;
        virtual void Render() = 0;
        virtual void Render_AfterUpdate() = 0;
    public:
        ILogic() = default;
        virtual ~ILogic() = default;
	};
#endif // !DEFINITION_ILOGIC
}