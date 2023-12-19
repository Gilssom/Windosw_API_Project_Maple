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
			HowlingGale,
			Buff,
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
		void FairyTurnEffOff();

		void BoringSongEff();
		void BoringSongEffing();
		void BoringSongEffend();
		void BoringSongEffOff();

		void BoringArrow();

		void HowlingEff();
		void HowlingEffing();
		void HowlingEffend();
		void HowlingEffOff();

		//void FairyEffOff(bool OnOff);

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		Vector2 GetPlayerPos() { return m_PlayerPos; }

	private:
		void Idle();
		void Move();
		void Jump();
		void SitDown();
		void DownAttack();
		void Attack();
		void FairyTurn();
		void BoringSong();
		void HowlingGale();
		void Buff();

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		class Rigidbody* m_Rigidbody;
		Vector2 m_PlayerPos;

		float m_ReShootTime;
		bool isBuff;

		GameObject* m_BoringSong; 
		GameObject* m_FairyTurn; 
		GameObject* m_HowlingGale; 
		GameObject* m_SharpEyes;
		class BoxCollider2D* m_FairyColl; 
		class BoxCollider2D* m_HowlingColl;
	};
}

