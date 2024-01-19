#pragma once
#include "../WinAPI_Source/YH_Script.h"

namespace YH
{
	class DamageFont : public Script
	{
	public:
		DamageFont();
		~DamageFont();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetMonster(GameObject* monster) { m_Monster = monster; }
		void SetDamage(int damage, int cnt, bool critical)
		{ 
			m_Damage = damage; 
			m_Count = cnt;
			ViewDamageFont(critical);
		}
		void ViewDamageFont(bool critical);

	private:
		GameObject* m_Monster;
		GameObject* m_CriEffect;
		GameObject* m_NumberImage[10];
		int m_Damage;
		int m_Count;

		float m_DeathTime;

		std::vector<GameObject*> m_DamageFonts;

		std::wstring m_Name[10] =
		{
			L"Zero",
			L"One",
			L"Two",
			L"Three",
			L"Four",
			L"Five",
			L"Six",
			L"Seven",
			L"Eight",
			L"Nine",
		};
	};
}