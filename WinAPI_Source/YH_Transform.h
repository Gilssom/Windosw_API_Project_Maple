#pragma once
#include "YH_Component.h"
#include "YH_Entity.h"

namespace YH
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { m_Position.x = pos.x; m_Position.y = pos.y; }
		void SetSpeed(float speed) { m_Speed = speed; }
		
		Vector2 GetPostion() { return m_Position; }

	private:
		Vector2 m_Position;
		float m_Speed;
	};
}