#pragma once
#ifndef USE_SHARED_LIBRARY_TSTRING
#define USE_SHARED_LIBRARY_TSTRING
#include "Shared_Library/String/TString.h"
#endif // !USE_SHARED_LIBRARY_TSTRING

#ifndef DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE
#define DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE
template<typename _Class>
class IItemManager_Single
{
#pragma region ItemManager_Single
	virtual std::shared_ptr<_Class> CreateItem(const TString& name) = 0;
	virtual const bool DeleteItem(const TString& name) = 0;
	virtual [[nodiscard]] std::shared_ptr<_Class> GetItem(const TString& name) = 0;
#pragma endregion
};
#endif // !DECLARE_SHARED_LIBRARY_IITEMMANAGER_SINGLE