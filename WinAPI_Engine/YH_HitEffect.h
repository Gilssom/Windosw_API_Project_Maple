#pragma once
#include "../WinAPI_Source/YH_Script.h"

namespace YH
{
	class HitEffect : public Script
	{
	public:
		HitEffect();
		~HitEffect();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class Animator* m_Anim;
	};
}