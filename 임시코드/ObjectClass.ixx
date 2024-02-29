export module ObjectClass;
import <mutex>;
import <memory>;
import <vector>;
import <unordered_map>;

namespace object_class
{
	/// <summary>
	/// 오브젝트의 최상위 추상 클래스입니다.<para/>
	/// <example>
	///	상속 할 때 다음과 같은 함수를 구현 해야합니다.<para/>
	///	- Initialize<para/>
	/// - Release<para/>
	///	</example>
	/// </summary>
	export class AObjectClass
	{
	public:
		virtual inline [[nodiscard]] const std::wstring Name() const final
			{
				std::lock_guard<std::mutex> lock(_nameMutex);
				return _name;
			}
	public:
		virtual inline [[nodiscard]] const std::wstring ClassType() const final
		{
			std::lock_guard<std::mutex> lock(_classTypeMutex);
			return _classType;
		}
	public:
		virtual inline [[nodiscard]] const bool IsAlive() const final
			{
				std::lock_guard<std::mutex> lock(_aliveMutex);
				return _alive;
			}
		virtual inline void Kill() final
			{
				std::lock_guard<std::mutex> lock(_aliveMutex);
				_alive = false;
			}
	public:
		virtual bool Initialize() = 0;
		virtual bool Release() = 0;
	public:
		inline AObjectClass(const std::wstring& name, const std::wstring& classType)
			: _name(name), _classType(classType)
		{}
		virtual ~AObjectClass() = default;
	private:
		std::wstring _name = L"";
		mutable std::mutex _nameMutex;
	private:
		std::wstring _classType = L"";
		mutable std::mutex _classTypeMutex;
	private:
		bool _alive = true;
		mutable std::mutex _aliveMutex;
	};

	namespace internal_class
	{
		class ObjectClass_Manger
		{
		public:
			inline static ObjectClass_Manger& Instance()
			{
				static ObjectClass_Manger instance;
				return instance;
			}
		private:
			inline ObjectClass_Manger() {}
			inline ~ObjectClass_Manger() {}
		public:
			inline ObjectClass_Manger(const ObjectClass_Manger&) = delete;
			inline ObjectClass_Manger& operator=(const ObjectClass_Manger&) = delete;
		public:
			inline bool CreateObject(const std::wstring& name, std::shared_ptr<AObjectClass> object)
			{
				std::lock_guard<std::mutex> lock(_objectDicMutex);
				auto findIter = _objectDic.find(name);
				if (findIter != _objectDic.end())
					return false;
				if (object == nullptr)
					return false;
				if (object->Initialize() == false)
					return false;
				_objectDic.insert(std::pair(name, object));
				return true;
			}
			template<typename T>
			inline std::weak_ptr<T> GetObject(const std::wstring& name)
			{
				std::lock_guard<std::mutex> lock(_objectDicMutex);
				auto findIter = _objectDic.find(name);
				if (findIter == _objectDic.end())
					return std::weak_ptr<T>();
				auto castingPointer = std::dynamic_pointer_cast<T>(findIter->second);
				if (castingPointer == nullptr)
					return std::weak_ptr<T>();
				return castingPointer;
			}
			inline void KillObject(const std::wstring& name)
			{
				std::lock_guard<std::mutex> lock(_objectDicMutex);
				auto findIter = _objectDic.find(name);
				if (findIter == _objectDic.end())
					return;
				findIter->second->Kill();
			}
			inline void OrganizeObjects()
			{
				std::lock_guard<std::mutex> lock(_objectDicMutex);
				std::vector<std::wstring> deadNameList;
				for (auto item : _objectDic)
				{
					if (item.second == nullptr)
					{
						deadNameList.push_back(item.first);
						continue;
					}
					if (item.second->IsAlive() == false)
					{
						deadNameList.push_back(item.first);
						continue;
					}
				}
				for (auto item : deadNameList)
				{
					_objectDic[item]->Release();
					_objectDic.erase(item);
				}
			}
		private:
			std::unordered_map<std::wstring, std::shared_ptr<AObjectClass>> _objectDic;
			std::mutex _objectDicMutex;
		};
	}

	export bool CreateObject(const std::wstring& name, std::shared_ptr<AObjectClass> object)
	{
		return internal_class::ObjectClass_Manger::Instance().CreateObject(name, object);
	}
	export template<typename T> std::weak_ptr<T> GetObject(const std::wstring& name)
	{
		return internal_class::ObjectClass_Manger::Instance().GetObject<T>(name);
	}
	export void KillObject(const std::wstring& name)
	{
		internal_class::ObjectClass_Manger::Instance().KillObject(name);
	}
	export void OrganizeObjects()
	{
		return internal_class::ObjectClass_Manger::Instance().OrganizeObjects();
	}
}