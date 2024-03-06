#pragma once
#include "MutexValue.h"
class Core
{
public:
	static Core& Get();
public:
	bool Run();
private:
	bool Progress();
private:
	Core() = default;
	Core(Core&) noexcept = delete;
	Core(Core&&) noexcept = delete;
private:
	MutexValue<bool> _run = true;

};

