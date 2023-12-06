#pragma once
#include "CommonInclude.h"

namespace YH
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float DeltaTime() { return m_DeltaTime; }

	private:
		static LARGE_INTEGER m_CpuFrequency;
		static LARGE_INTEGER m_PrevFrequency;
		static LARGE_INTEGER m_CurrentFrequency;
		static float m_DeltaTime;
	};
}

