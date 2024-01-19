#pragma once
#include "../WinAPI_Source/YH_Script.h"
#include "../WinAPI_Source/YH_Transform.h"

namespace YH
{
	class CygnusScript : public Script
	{
	public:
		enum class State
		{
			Idle,
			Move,
			Skill1,
			Skill2,
			Skill3,
			Death,
		};

		enum class Direction
		{
			Right,
			Left,
		};

		CygnusScript();
		~CygnusScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { m_Target = target; }

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void Skill1Ball();
		void Skill2Ball();
		void Skill3Ball();

		float GetHpPercent() { return (double)m_Hp / (double)m_MaxHp; }

	private:
		void DeathCheck();
		void Idle();
		void Move();
		void Skill1();
		void Skill2();
		void Skill3();
		void Death();

		void PlayWalkAnimationByDirection(Direction dir);

		void Translate(Transform* transform);

		void SetDamage(int damage, int cnt, bool critical)
		{
			m_Damage = damage;
			ViewDamageFont(m_Damage, cnt, critical);
		}
		void ViewDamageFont(int damage, int cnt, bool critical);

	private:
		__int64 m_Hp, m_MaxHp;
		int m_Exp;

		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		class GameObject* m_Target;
		Vector2 m_CygnusPos;
		Vector2 m_TargetPos;
		float m_Time;
		float m_SkillDelay;
		bool m_DoSkill;
		float m_DeathTime;

		int m_Damage;

		Vector2 m_GPos[6] =
		{
			{300.0f, 330.0f},
			{550.0f, 330.0f},
			{800.0f, 330.0f},
			{1050.0f, 330.0f},
			{1300.0f, 330.0f},
			{1550.0f, 330.0f}
		};
	};
}