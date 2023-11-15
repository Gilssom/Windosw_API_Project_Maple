#pragma once
#include "YH_Component.h"
#include "YH_Entity.h"

namespace YH
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(float x, float y) { m_X = x; m_Y = y; }
		void SetSpeed(float speed) { m_Speed = speed; }
		float GetX() { return m_X; }
		float GetY() { return m_Y; }

	private:
		float m_X;
		float m_Y;
		float m_Speed;
	};
}