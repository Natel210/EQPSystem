#pragma once
#include "dream/definition/DreamHeader.h"
#include "dream/definition/DreamLogEnum.h"
#include "dream/base/DreamComponentBase.h"
namespace dream::componet
{
#ifndef DECLARATION_DREAMLOGCOMPONET
#define DECLARATION_DREAMLOGCOMPONET
	class DREAM_API DreamLogComponet : public base::DreamComponentBase
	{
	public:
		bool Initialize() final;
		bool Release() final;
	protected:
		std::shared_ptr<base::DreamObjectBase> Clone_ToObject() const override;
	public:
		std::shared_ptr<DreamLogComponet> Clone();
	public:
		virtual [[nodiscard]] const ELogLevel Level() const final;
		virtual void Level(const ELogLevel& leval) final;
	public:
		virtual void AddLog(const std::string& comment) final;
		virtual void AddLogsRange(const std::vector<std::string>& commentList) final;
		virtual [[nodiscard]] const std::shared_ptr<const std::vector<std::string>> List() const final;
		virtual void Clear() final;
	public: 
		/// <summary> 문자열 포멧에 관해서 변경이 필요할 때 해당 함수 상속 구현 </summary>
		virtual const std::string Format(const std::string& comment);
	public:
		DreamLogComponet(const std::string& name, const std::string& classType = "DreamLogComponet");
		virtual ~DreamLogComponet() = default;
		DreamLogComponet(const DreamLogComponet& other);
	private:
		ELogLevel _level = ELogLevel::None;
		mutable std::mutex _levelMutex;
		std::vector<std::string> _logList;
		mutable std::mutex _logListMutex;
	};
#endif // !DECLARATION_DREAMLOGCOMPONET
}

