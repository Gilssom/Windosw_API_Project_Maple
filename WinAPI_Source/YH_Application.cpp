#include "YH_Application.h"
#include "YHInput.h"
#include "YHTime.h"
#include "YHRocket.h"
#include "YH_SceneManager.h"

namespace YH
{
	Application::Application() : m_Hand(nullptr), m_Hdc(nullptr), m_Speed(0), m_PlayerVec(0), m_MonsterVec(0),
		m_Width(0), m_Height(0), m_BackHdc(nullptr), m_BackBitmap(nullptr), m_RocketArray{ }
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

		SceneManager::Initialize();
		Input::Initailize();
		Time::Initailize();

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
		SceneManager::Update();
		Input::Update();
		Time::Update();

#pragma region 미사일 발사
		GameObject* obj = SceneManager::GetScene()->GetGameObject();

		if (obj->isAttack())
		{
			Rocket* r = new Rocket();

			m_RocketArray.push_back(r);

			int state = static_cast<int>(obj->m_LookState);

			r->CreateRocket(obj->GetPositionX(), obj->GetPositionY(), state);
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
		ClearRenderTarget();

		SceneManager::Render(m_BackHdc);
		Time::Render(m_BackHdc);

#pragma region 미사일 발사
		for (int i = 0; i < m_RocketArray.size(); i++)
		{
			if (m_RocketArray[i]->AreaOutCheck())
				continue;

			m_RocketArray[i]->RocketRender(m_BackHdc);
		}
#pragma endregion

		for (int i = 0; i < 2; i++)
		{
			m_Monster[i].MonsterRender(m_BackHdc);
		}

		CopyRenderTarget(m_BackHdc, m_Hdc);
	}
	void Application::ClearRenderTarget()
	{
		Rectangle(m_BackHdc, -1, -1, 1600, 900);
	}
	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer 에 있는 정보들을 원본 Buffer 에 복사 ( 그려준다 )
		BitBlt(dest, 0, 0, m_Width, m_Height, source, 0, 0, SRCCOPY);
	}
}
