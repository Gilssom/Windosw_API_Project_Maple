#include "YH_Application.h"
#include "YHInput.h"
#include "YHTime.h"

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

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		m_BackBitmap = CreateCompatibleBitmap(m_Hdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_BackBitmap);
		DeleteObject(oldBitmap);

		m_PlayerVec = { {0,0},{600,300} };
		m_MonsterVec = { {100,200},{800,450} };

		Input::Initailize();
		Time::Initailize();

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
		Input::Update();
		Time::Update();

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
		Rectangle(m_BackHdc, 0, 0, 1600, 900);

		Time::Render(m_BackHdc);

		for (int i = 0; i < 2; i++)
		{
			m_Player[i].Render(m_BackHdc, i);
			m_Monster[i].MonsterRender(m_BackHdc);
		}

		// BackBuffer 에 있는 정보들을 원본 Buffer 에 복사 ( 그려준다 )
		BitBlt(m_Hdc, 0, 0, m_Width, m_Height, m_BackHdc, 0, 0, SRCCOPY);
	}
}
