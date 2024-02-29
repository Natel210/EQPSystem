#pragma once
#include <string>
#include <mutex>
#include "dream/definition/DreamHeader.h"
namespace dream::base
{
#ifndef DECLARATION_DREAMOBJECTBASE
#define DECLARATION_DREAMOBJECTBASE
	/// <summary> 오브젝트의 최소 기능 </summary>
	class DREAM_API DreamObjectBase
	{
	public:
		virtual [[nodiscard]] const std::string Name() const final;
		virtual [[nodiscard]] const std::string ClassType() const final;
		virtual [[nodiscard]] const bool IsAlive() const final;
		virtual void Kill() final;
	protected:
		virtual [[nodiscard]] void Alive() final;
	public:
		virtual bool Initialize();
		virtual bool Release();
	protected:
		virtual std::shared_ptr<DreamObjectBase> Clone_ToObject() const;
	public:
		std::shared_ptr<DreamObjectBase> Clone();
	public:
		DreamObjectBase(const std::string& name, const std::string& classType = "DreamObjectBase");
		virtual ~DreamObjectBase() = default;
		DreamObjectBase(const DreamObjectBase& other);
	private:
		std::string _name = "";
		mutable std::mutex _nameMutex;

		std::string _classType = "";
		mutable std::mutex _classTypeMutex;

		bool _alive = false;
		mutable std::mutex _aliveMutex;
	};
#endif // !DECLARATION_DREAMOBJECTBASE
}