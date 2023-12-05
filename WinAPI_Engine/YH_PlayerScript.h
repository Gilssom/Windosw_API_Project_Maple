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
			Jump,
			Down,
			DownAttack,
			Attack,
			FairyTurn,
			BoringSong,
			MonSun,
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

		void FairyTurnEffOff();
		//void FairyEffOff(bool OnOff);
		void BoringSongEffOff();

	private:
		void Idle();
		void Move();
		void Jump();
		void SitDown();
		void DownAttack();
		void Attack();
		void FairyTurn();
		void BoringSong();
		void MonSun();

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		Vector2 m_PlayerPos;

		GameObject* m_BoringSong; GameObject* m_FairyTurn; GameObject* m_Monsun;
		Animator* m_BoringAnim; Animator* m_FairyAnim; Animator* m_MonsunAnim;
	};
}

