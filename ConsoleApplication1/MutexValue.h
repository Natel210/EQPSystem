#pragma once
#include <mutex>

template<typename _Value>
class MutexValue
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
	_NODISCARD MutexValue<_Value>& operator=(const _Value& value)
	{
		Set(value);
		return *this;
	}
	_NODISCARD MutexValue<_Value>& operator=(const MutexValue<_Value>& mutexValue)
	{
		Set(mutexValue.Get());
		return *this;
	}
	_NODISCARD const bool operator==(const _Value& value) const
	{
		if (Get() == value)
		{
			return true;
		}
		return false;
	}
	_NODISCARD const bool operator==(const MutexValue<_Value>& mutexValue) const
	{
		if (Get() == mutexValue.Get())
		{
			return true;
		}
		return false;
	}
	_NODISCARD const bool operator!=(const _Value& value) const
	{
		if (Get() != value)
		{
			return true;
		}
		return false;
	}
	_NODISCARD const bool operator!=(const MutexValue<_Value>& mutexValue) const
	{
		if (Get() != mutexValue.Get())
		{
			return true;
		}
		return false;
	}
public:
	MutexValue() = default;
	template<typename T>
	MutexValue(T&& value) : _value(std::forward<T>(value)) {}
	MutexValue(const _Value& value) : _value(value) {}
	MutexValue(const MutexValue& other) : _value(other.Get()) {}
private:
	_Value _value;
	mutable std::mutex _valueMutex;
};