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
			Rope,
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
		bool GetPlayerisRope() { return isRope; }
		void SetisJumpUp(bool jumpUp) { isJumpUp = jumpUp; }
		bool GetisJumpUp() { return isJumpUp; }

		// Status
		float GetHpPercent() { return (float)m_Hp / (float)m_MaxHp; }
		float GetMpPercent() { return (float)m_Mp / (float)m_MaxMp; }
		float GetExpPercent() { return (float)m_Exp / (float)m_MaxExp; }

		void ExpUp(int exp);

		int GetPlayerMapNumber() { return m_MapNumber; }

	private:
		void Idle();
		void Move();
		void Jump();
		void Rope();
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
		class AudioSource* m_AudioSource;
		class BoxCollider2D* m_PlayerColl;
		Vector2 m_PlayerPos;
		int m_MapNumber;

		int m_Hp, m_MaxHp;
		int m_Mp, m_MaxMp;
		int m_Exp, m_MaxExp;
		int m_Level;

		float m_ReShootTime;
		bool isBuff;
		bool isJump;
		bool isRope;
		bool isJumpUp;

		GameObject* m_BoringSong; 
		GameObject* m_FairyTurn; 
		GameObject* m_HowlingGale; 
		GameObject* m_SharpEyes;
		GameObject* m_DoubleJump;
		GameObject* m_HighJump;
		GameObject* m_LevelUpEffect;
		class BoxCollider2D* m_FairyColl; 
		class BoxCollider2D* m_HowlingColl;
	};
}

