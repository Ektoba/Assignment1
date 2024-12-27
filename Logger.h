#pragma once
class CLogger
{
public:
	CLogger();
	~CLogger();
private:
	int LogCount = NULL;
public:
	void LogInfo(const std::string& Message);
	void LogWarning(const std::string& Message);
	void LogError(const std::string& Message);
	void ShowTotalLogs();
};

