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
		Vector2 GetPostion() { return m_Position; }
		float GetRotation() { return m_Rotation; }
		Vector2 GetScale() { return m_Scale; }
		void SetRotation(float rotate) { m_Rotation = rotate; }
		void SetScale(Vector2 scale) { m_Scale = scale; }

		void SetSpeed(float speed) { m_Speed = speed; }

	private:
		Vector2 m_Position;
		Vector2 m_Scale;
		float m_Rotation;

		float m_Speed;
	};
}