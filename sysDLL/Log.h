#pragma once
#include "ILog.h"
#include <mutex>
class Log : public ILog
{
};


//class Log : public ILog
//{
//public:
//	void SetHeader(std::wstring headerString)
//
//
//private:
//	std::wstring _logName;
//	std::mutex _logNameMutex;
//	std::wstring _header;
//	std::mutex _headerMutex;
//	std::wstring _comment;
//	std::mutex _commentMutex;
//};

