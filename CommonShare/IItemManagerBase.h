#pragma once
#ifndef USE_COMMON_TSTRING
#define USE_COMMON_TSTRING
#include "CommonShare/TString.h"
#endif // !USE_COMMON_TSTRING

template<typename _Class>
class IItemManagerBase
{
	virtual std::shared_ptr<_Class> CreateItem(const TString& name) = 0;
	virtual const bool DeleteItem(const TString& name) = 0;
	virtual [[nodiscard]] std::shared_ptr<_Class> GetItem(const TString& name) = 0;
};