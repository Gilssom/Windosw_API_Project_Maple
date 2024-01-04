#pragma once
#include "YH_Component.h"

namespace YH
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { m_Mass = mass; }
		void AddForce(Vector2 force) { m_Force += force; }
		void SetGround(bool ground) { isGrounded = ground; }
		bool GetGround() { return isGrounded; }
		void SetVelocity(Vector2 velocity) { m_Velocity = velocity; }
		Vector2 GetVelocity() { return m_Velocity; }

	private:
		bool isGrounded;
		float m_Mass;
		float m_Friction;

		Vector2 m_Force;
		Vector2 m_Accelation;
		Vector2 m_Velocity;
		Vector2 m_LimitedVelocity;
		Vector2 m_Gravity;
	};
}