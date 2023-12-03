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
			DownAttack,
			Attack,
			FairyTurn,
			BoringSong,
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

		void FairyTurnEff();
		void BoringSongEff();

	private:
		void Idle();
		void Move();
		void SitDown();
		void DownAttack();
		void Attack();
		void FairyTurn();
		void BoringSong();

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		GameObject* m_RightEff[50];
		GameObject* m_LeftEff[50];
		Animator* m_RightEffAnim[50];
		Animator* m_LeftEffAnim[50];
	};
}

