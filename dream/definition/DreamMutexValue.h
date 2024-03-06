#pragma once
#pragma region Include
#include <mutex>
#pragma endregion
#pragma region Namespace
namespace dream {
#pragma endregion
#pragma region Avoid duplication
#ifndef DECLARATION_DREAMMUTEXVALUE
#define DECLARATION_DREAMMUTEXVALUE
#pragma endregion

template<typename _Value>
class DreamMutexValue
{
public:
	_NODISCARD _Value Get() const
	{
		std::lock_guard<std::mutex> lock(_valueMutex);
		return _value;
	}
	void Set(const _Value value)
	{
		std::lock_guard<std::mutex> lock(_valueMutex);
		_value = value;
	}
public:
	_NODISCARD DreamMutexValue<_Value>& operator=(const _Value& value)
	{
		Set(value);
		return *this;
	}
public:
	DreamMutexValue() = default;
	template<typename T>
	DreamMutexValue(T&& value) : _value(std::forward<T>(value))
	{

	}
	DreamMutexValue(const _Value& value)
	{
		Set(value);
	}
	DreamMutexValue(const DreamMutexValue& other)
	{
		Set(other.Get());
	}
private:
	_Value _value;
	mutable std::mutex _valueMutex;
};

#pragma region Rename : MutexValue
template<typename _Value>
using MutexValue = DreamMutexValue<_Value>;
#pragma endregion

#pragma region Avoid duplication
#endif // DECLARATION_DREAMMUTEXVALUE
#pragma endregion
#pragma region Namespace
}
#pragma endregion