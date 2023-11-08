#include "YH_Application.h"

namespace YH
{
	Application::Application() : m_Hand(nullptr), m_Hdc(nullptr), m_Speed(0), v(0)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		m_Hand = hwnd;
		m_Hdc = GetDC(m_Hand);

		v = { {0,0},{600,300},{100,200} };

		for (int i = 0; i < 3; i++)
		{
			m_Player[i].SetPosition(v[i].first, v[i].second);
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
		for (int i = 0; i < 3; i++)
		{
			m_Player[i].Update(i);
		}
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		for (int i = 0; i < 3; i++)
		{
			m_Player[i].Render(m_Hdc, i);
		}
	}
}
