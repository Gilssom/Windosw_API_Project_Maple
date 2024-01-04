#include "YH_Time.h"

namespace YH
{
	LARGE_INTEGER Time::m_CpuFrequency = { };
	LARGE_INTEGER Time::m_PrevFrequency = { };
	LARGE_INTEGER Time::m_CurrentFrequency = { };
	float Time::m_DeltaTime = 0.0f;

	void Time::Initailize()
	{
		// Cpu �� ���� ���� ��
		QueryPerformanceFrequency(&m_CpuFrequency);

		// ���α׷��� ���� ���� �� ���� ���� ��
		QueryPerformanceCounter(&m_PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&m_CurrentFrequency);

		float diferenceFrequency
			= static_cast<float>(m_CurrentFrequency.QuadPart - m_PrevFrequency.QuadPart);

		m_DeltaTime = diferenceFrequency / static_cast<float>(m_CpuFrequency.QuadPart);

		m_PrevFrequency.QuadPart = m_CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += m_DeltaTime;
		float fps = 1.0f / m_DeltaTime;

		// wchar �ʱ�ȭ ���
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
