#pragma once
#include "CommonInclude.h"

namespace YH
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update(int type);
		void LateUpdate();
		void Render(HDC hdc, int type);

		void MonsterRender(HDC hdc);
		void MonsterMoving();

		void SetPosition(float x, float y)
		{
			m_X = x;
			m_Y = y;
		}

		float GetPositionX() { return m_X; }
		float GetPositionY() { return m_Y; }

	private:
		// 게임오브젝트의 좌표
		float m_X;
		float m_Y;

		// 몬스터 움직임 좌표 및 속도
		float dir[3] = { -0.5f, 0, 0.5f };
	};
}