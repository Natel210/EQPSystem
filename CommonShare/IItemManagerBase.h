#pragma once
template<typename _Class>
class IItemManagerBase
{
	virtual std::shared_ptr<_Class> CreateItem(const std::wstring& name) = 0;
	virtual const bool DeleteItem(const std::wstring& name) = 0;
	virtual std::shared_ptr<_Class> GetItem(const std::wstring& name) = 0;
};