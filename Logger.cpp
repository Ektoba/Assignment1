#include "pch.h"
#include "Logger.h"

CLogger::CLogger()
{
}

CLogger::~CLogger()
{
	std::cout << "Logger instance destroyed." << std::endl;
}

void CLogger::LogInfo(const std::string& Message)
{
	std::cout << "[LOGINFO] : " << Message << std::endl;
	++LogCount;
}

void CLogger::LogWarning(const std::string& Message)
{
	std::cout << "[WARNING] : " << Message << std::endl;
	++LogCount;
}

void CLogger::LogError(const std::string& Message)
{
	std::cout << "[ERROR] : " << Message << std::endl;
	++LogCount;
}

void CLogger::ShowTotalLogs()
{
	std::cout << "Total logs recorded : " << LogCount << std::endl;
}
