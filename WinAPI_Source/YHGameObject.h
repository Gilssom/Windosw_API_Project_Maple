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
		// ���ӿ�����Ʈ�� ��ǥ
		float m_X;
		float m_Y;

		// ���� ������ ��ǥ
		float dir[3] = { -0.4f, 0, 0.4f };
	};
}