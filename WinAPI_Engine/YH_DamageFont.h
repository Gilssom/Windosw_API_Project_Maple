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

		void SetDamage(int damage) { m_Damage = damage; }
		void ViewDamageFont();

	private:
		class GameObject* m_NumberImage[10];
		int m_Damage;

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