#include "YH_Application.h"

namespace YH
{
	Application::Application() : m_Hand(nullptr), m_Hdc(nullptr), m_Speed(0), m_PlayerVec(0), m_MonsterVec(0)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		m_Hand = hwnd;
		m_Hdc = GetDC(m_Hand);

		m_PlayerVec = { {0,0},{600,300} };
		m_MonsterVec = { {100,200},{800,450} };

		for (int i = 0; i < 2; i++)
		{
			m_Player[i].SetPosition(m_PlayerVec[i].first, m_PlayerVec[i].second);
			m_Monster[i].SetPosition(m_MonsterVec[i].first, m_MonsterVec[i].second);
		}

	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		for (int i = 0; i < 2; i++)
		{
			m_Player[i].Update(i);
			m_Monster[i].MonsterMoving();
		}

	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		for (int i = 0; i < 2; i++)
		{
			m_Player[i].Render(m_Hdc, i);
			m_Monster[i].MonsterRender(m_Hdc);
		}
	}
}
