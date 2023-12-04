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
		void BoringSongEffing();
		void BoringSongEffend();

		void Test();
		void FairyEffOff(bool OnOff);
		void BoringSongEffOnOff();

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
		Vector2 m_PlayerPos;

		GameObject* m_BoringSong; GameObject* m_FairyTurn;
		Animator* m_BoringAnim; Animator* m_FairyAnim;
	};
}

