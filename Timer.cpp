#include "pch.h"
#include "Timer.h"

CTimer::CTimer()
{
	m_Last = std::chrono::steady_clock::now(); // 객체 생성시 시간체크
}

CTimer::~CTimer()
{
}

float CTimer::Mark()
{
	// 실행하는데 걸리는 시간.
	const std::chrono::steady_clock::time_point OldTime= m_Last;
	std::chrono::duration<float> DeltaTime = m_Last - OldTime;
	return DeltaTime.count();
}

float CTimer::Peek()
{
	// 호출된 시점의 시간 구하기.
	auto now = std::chrono::steady_clock::now();	
	float DeltaTime = std::chrono::duration<float>(std::chrono::steady_clock::now() - m_Last).count();
	m_Last = now;
	return DeltaTime;
}
