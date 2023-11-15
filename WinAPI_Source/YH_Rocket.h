#pragma once
#include "CommonInclude.h"
#include "YH_Time.h"

namespace YH
{
	class Rocket
	{
	public:
		Rocket();
		~Rocket();

		void Update();

		void CreateRocket(float x, float y, int dir);
		void RocketRender(HDC hdc);

		bool AreaOutCheck();

	private:
		bool isOut;

		float m_X;
		float m_Y;
		int m_Dir;

		float m_Speed;
	};
}