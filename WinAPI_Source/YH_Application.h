// �ߺ��� ��������� �־ Ȯ���ؼ� ���� �ð��� �ٿ��ش�.
#pragma once 
#include "CommonInclude.h"
#include "YHGameObject.h"

namespace YH
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_Hand;
		HDC m_Hdc;

		float m_Speed;

		std::vector<std::pair<int, int>> m_PlayerVec;
		GameObject m_Player[3];

		std::vector<std::pair<int, int>> m_MonsterVec;
		GameObject m_Monster[3];
	};
}