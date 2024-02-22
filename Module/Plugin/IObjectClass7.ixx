export module IObjectClass;

import <string>;

#ifndef DECLARE_IOBJECTCLASS
#define DECLARE_IOBJECTCLASS
export class IObjectClass
{
public: // Name
	/// <summary>Get Name</summary>
	virtual [[nodiscard]] const std::wstring Name() const = 0;
	/// <summary>Set Name</summary>
	virtual void Name(const std::wstring& name) = 0;
public: // Active
	/// <summary>Get Active</summary>
	virtual [[nodiscard]] const bool Active() const = 0;
	/// <summary>Set Active</summary>
	virtual void Active(const bool active) = 0;
public: // 
	/// <summary>Virtual destructor.</summary>
	virtual ~IObjectClass() = default;
};
#endif // !DECLARE_IOBJECTCLASS