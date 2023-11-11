#include "YH_Application.h"
#include "YHInput.h"
#include "YHTime.h"
#include "YHRocket.h"

namespace YH
{
	Application::Application() : m_Hand(nullptr), m_Hdc(nullptr), m_Speed(0), m_PlayerVec(0), m_MonsterVec(0),
		m_Width(0), m_Height(0), m_BackHdc(nullptr), m_BackBitmap(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		m_Hand = hwnd;
		m_Hdc = GetDC(m_Hand);

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;

		SetWindowPos(m_Hand, nullptr, 0, 0, m_Width, m_Height, 0);
		ShowWindow(m_Hand, true);

		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		m_BackBitmap = CreateCompatibleBitmap(m_Hdc, width, height);

		// ����۸� ����ų DC ����
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_BackBitmap);
		DeleteObject(oldBitmap);

		m_PlayerVec = { {0,0},{600,300} };
		m_MonsterVec = { {100,200},{800,450} };

		Input::Initailize();
		Time::Initailize();

		m_Player[0].SetPosition(m_PlayerVec[0].first, m_PlayerVec[0].second);

		for (int i = 0; i < 2; i++)
		{
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
		Input::Update();
		Time::Update();

		m_Player[0].Update(0);

#pragma region �̻��� �߻�
		if (m_Player[0].isAttack())
		{
			Rocket* r = new Rocket();

			m_RocketArray.push_back(r);

			int state = static_cast<int>(m_Player[0].m_LookState);

			r->CreateRocket(m_Player[0].GetPositionX(), m_Player[0].GetPositionY(), state);
		}

		for (int i = 0; i < m_RocketArray.size(); i++)
		{
			if (m_RocketArray[i]->AreaOutCheck())
				continue;

			m_RocketArray[i]->Update();
		}
#pragma endregion	

		for (int i = 0; i < 2; i++)
		{
			m_Monster[i].MonsterMoving();
		}
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(m_BackHdc, 0, 0, 1600, 900);

		Time::Render(m_BackHdc);

#pragma region �̻��� �߻�
		for (int i = 0; i < m_RocketArray.size(); i++)
		{
			if (m_RocketArray[i]->AreaOutCheck())
				continue;

			m_RocketArray[i]->RocketRender(m_BackHdc);
		}
#pragma endregion

		m_Player[0].Render(m_BackHdc, 0);

		for (int i = 0; i < 2; i++)
		{
			m_Monster[i].MonsterRender(m_BackHdc);
		}

		// BackBuffer �� �ִ� �������� ���� Buffer �� ���� ( �׷��ش� )
		BitBlt(m_Hdc, 0, 0, m_Width, m_Height, m_BackHdc, 0, 0, SRCCOPY);
	}
}
