#pragma once
#include "../WinAPI_Source/YH_Script.h"

namespace YH
{
	class DarkGenesis : public Script
	{
	public:
		DarkGenesis();
		~DarkGenesis();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetSkillDelay(float delay) { m_SkillDelay = delay; }
		void SetSkillOffset(Vector2 offset) { m_SkillOffset = offset; }
		void SetSkillSize(Vector2 size) { m_SkillSize = size; }

	private:
		class Animator* m_Animator;
		float m_SkillDelay;
		float m_AttackTime;
		Vector2 m_SkillOffset;
		Vector2 m_SkillSize;
		bool m_Attack;
	};
}