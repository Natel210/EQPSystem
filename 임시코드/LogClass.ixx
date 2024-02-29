export module LogClass;

import ObjectClass;
namespace log_class
{
	export enum class ELogLevel
	{
		None,
		Trace,
		Debug,
		Log,
		Info,
		Warning,
		Error,
		Fatal,
	};

	/// <summary>
	/// 로그의 추상 클래스입니다.<para/>
	/// <example>
	///	상속 할 때 다음과 같은 함수를 구현 해야합니다.<para/>
	///	- Initialize<para/>
	/// - Release<para/>
	/// - Format<para/>
	///	</example>
	/// </summary>
	export class ALogClass : public object_class::AObjectClass
	{
	public:
		bool Initialize() override = 0;
		bool Release() override = 0;
	public:
		virtual inline [[nodiscard]] const ELogLevel Level() const final
		{
			std::lock_guard<std::mutex> lock(_levelMutex);
			return _level;
		}
		virtual inline void Level(const ELogLevel& leval) final
		{
			std::lock_guard<std::mutex> lock(_levelMutex);
			_level = leval;
		}
	public:
		virtual inline void AddLog(const std::wstring& comment) final
		{
			std::lock_guard<std::mutex> lock(_logListMutex);
			_logList.push_back(Format(comment));
		}
		virtual inline void AddLogsRange(const std::vector<std::wstring>& commentList) final
		{
			std::lock_guard<std::mutex> lock(_logListMutex);
			for (auto item : commentList)
				_logList.push_back(Format(item));
		}
		virtual inline [[nodiscard]] const std::shared_ptr<const std::vector<std::wstring>> List() const final
		{
			std::lock_guard<std::mutex> lock(_logListMutex);
			return std::make_shared<std::vector<std::wstring>>(_logList);
		}
		virtual inline void Clear() final
		{
			std::lock_guard<std::mutex> lock(_logListMutex);
			_logList.clear();
		}
	public:
		virtual const std::wstring Format(const std::wstring& comment) = 0;
	public:
		ALogClass(std::wstring name) : object_class::AObjectClass(name, _classType) {}
		virtual ~ALogClass() = default;
	private:
		ELogLevel _level = ELogLevel::None;
		mutable std::mutex _levelMutex;
	private:
		std::vector<std::wstring> _logList;
		mutable std::mutex _logListMutex;
	public:
		static constexpr wchar_t _classType[] = L"Log";
	};

	namespace internal_class
	{
		class LogClass_Manager
		{
		public:
			inline static LogClass_Manager& Instance()
			{
				static LogClass_Manager instance;
				return instance;
			}
		private:
			inline LogClass_Manager() {}
			inline ~LogClass_Manager() {}
		public:
			inline LogClass_Manager(const LogClass_Manager&) = delete;
			inline LogClass_Manager& operator=(const LogClass_Manager&) = delete;
		public:
			inline bool CreateLog(const std::wstring& name, std::shared_ptr<ALogClass> log)
			{
				if (log == nullptr)
					return false;
				if (log->ClassType() != ALogClass::_classType)
					return false;
				if (object_class::CreateObject(name, log) == false)
					return false;
				return true;
			}
			inline std::weak_ptr<ALogClass> GetLog(const std::wstring& name)
			{
				auto getObject = object_class::GetObject<ALogClass>(name);
				if (getObject.expired() == true)
					return std::weak_ptr<ALogClass>();
				if(getObject.lock()->ClassType() != ALogClass::_classType)
					return std::weak_ptr<ALogClass>();
				return getObject;
			}
			inline void KillLog(const std::wstring& name)
			{
				object_class::KillObject(name);
			}
		};
	}

	export bool CreateLog(const std::wstring& name, std::shared_ptr<ALogClass> log)
	{
		return internal_class::LogClass_Manager::Instance().CreateLog(name, log);
	}

	export std::weak_ptr<ALogClass> GetLog(const std::wstring& name)
	{
		return internal_class::LogClass_Manager::Instance().GetLog(name);
	}

	export void KillLog(const std::wstring& name)
	{
		internal_class::LogClass_Manager::Instance().KillLog(name);
	}
}