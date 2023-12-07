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

		void Skill2Ball();

	private:
		void Idle();
		void Move();
		void Skill1();
		void Skill2();
		void Skill3();
		void Death();

		void PlayWalkAnimationByDirection(Direction dir);

		void Translate(Transform* transform);

	private:
		State m_State;
		Direction m_Dir;
		class Animator* m_Animator;
		Vector2 m_CygnusPos;
		float m_Time;
		float m_SkillDelay;
		bool m_DoSkill;
		float m_DeathTime;
	};
}