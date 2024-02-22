#pragma once

#ifndef USE_STD_STRING
#define USE_STD_STRING
#include <string>
#endif // !USE_STD_STRING

#ifndef DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE
#define DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE
template<typename _Class>
class IItemManager_Single
{
#pragma region ItemManager_Single
	virtual std::shared_ptr<_Class> CreateItem(const std::wstring& name) = 0;
	virtual const bool DeleteItem(const std::wstring& name) = 0;
	virtual [[nodiscard]] std::shared_ptr<_Class> GetItem(const std::wstring& name) = 0;
#pragma endregion
};
#endif // !DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE