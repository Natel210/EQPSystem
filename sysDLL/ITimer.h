#pragma once


class ITimer
{
public:
	virtual void Start() = 0;
	virtual double ElapsedMilliseconds() const = 0;
};