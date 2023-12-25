#pragma once
#include "../WinAPI_Source/YH_Script.h"
#include "../WinAPI_Source/YH_Transform.h"

namespace YH
{
	class TirueScript : public Script
	{
	public:
		enum class State
		{
			Idle,
			Walk,
			Attack,
			Death,
		};

		enum class Direction
		{
			Right,
			Left,
		};

		TirueScript();
		~TirueScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		void Idle();
		void Move();
		void Attack();
		void Death();

		void PlayWalkAnimationByDirection(Direction dir);

		void Translate(Transform* transform);

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		float m_Time;
		float m_DeathTime;
	};
}