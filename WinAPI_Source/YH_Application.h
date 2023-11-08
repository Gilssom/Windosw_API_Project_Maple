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

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_Hand;
		HDC m_Hdc;

		float m_Speed;

		std::vector<std::pair<int, int>> v;
		GameObject m_Player[3];
	};
}