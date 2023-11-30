#pragma once
#include "../WinAPI_Source/YH_Script.h"
#include "../WinAPI_Source/YH_Transform.h"

namespace YH
{
	class MushScript : public Script
	{
	public:
		enum class State
		{
			Idle,
			Walk,
			Down,
			Attack,
			FairyTurn,
		};

		enum class Direction
		{
			Right,
			Left,
		};

		MushScript();
		~MushScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Idle();
		void Move();
		void Attack();

		void PlayWalkAnimationByDirection(Direction dir);

		void Translate(Transform* transform);

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		float m_Time;
	};
}

