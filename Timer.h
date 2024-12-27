#pragma once

class CTimer
{
public:
	CTimer();
	~CTimer();
public:
	float Mark();
	float Peek();

private:
	std::chrono::steady_clock::time_point m_Last;
};

