#pragma once
#include "../WinAPI_Source/YH_Script.h"

namespace YH
{
	class PlayerScript : public Script
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

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Idle();
		void Move();
		void SitDown();
		void Attack();
		void FairyTurn();

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
	};
}

