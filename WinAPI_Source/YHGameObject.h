#pragma once
#include "CommonInclude.h"
#include "YHRocket.h"
#include "YHInput.h"

namespace YH
{
	enum class Lookfor
	{
		Left, Right, Up, Down, None,
	};

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

		// �̻��� �߻�
		bool isAttack() { return Input::GetKeyDown(KeyCode::Space); }

		Lookfor m_LookState;
	private:
		// ���ӿ�����Ʈ�� ��ǥ
		float m_X;
		float m_Y;

		// ���� ������ ��ǥ �� �ӵ�
		float dir[3] = { -0.5f, 0, 0.5f };
	};
}