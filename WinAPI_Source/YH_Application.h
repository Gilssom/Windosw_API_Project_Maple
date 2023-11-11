// 중복된 헤더파일이 있어도 확인해서 빌드 시간을 줄여준다.
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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_Hand;
		HDC m_Hdc;

		HDC m_BackHdc;
		HBITMAP m_BackBitmap;

		UINT m_Width;
		UINT m_Height;

		float m_Speed;

		std::vector<std::pair<int, int>> m_PlayerVec;
		GameObject m_Player[3];

		std::vector<std::pair<int, int>> m_MonsterVec;
		GameObject m_Monster[3];

		std::vector<Rocket*> m_RocketArray;
	};
}