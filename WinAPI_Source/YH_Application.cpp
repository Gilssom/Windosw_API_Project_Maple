#include "YH_Application.h"
#include "YH_Input.h"
#include "YH_Time.h"
#include "YH_Rocket.h"
#include "YH_SceneManager.h"
#include "YH_Resources.h"

namespace YH
{
	Application::Application() : m_Hand(nullptr), m_Hdc(nullptr),
		m_Width(0), m_Height(0), m_BackHdc(nullptr), m_BackBitmap(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		AdJustWindowRect(hwnd, width, height);
		CreateBuffer(width, height);
		InitializeEtc();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		SceneManager::Update();
		Input::Update();
		Time::Update();
	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		SceneManager::Render(m_BackHdc);
		Time::Render(m_BackHdc);

		CopyRenderTarget(m_BackHdc, m_Hdc);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
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

	void Application::AdJustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		m_Hand = hwnd;
		m_Hdc = GetDC(m_Hand);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;

		SetWindowPos(m_Hand, nullptr, 0, 0, m_Width, m_Height, 0);
		ShowWindow(m_Hand, true);
	}

	void Application::CreateBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		m_BackBitmap = CreateCompatibleBitmap(m_Hdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_BackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::InitializeEtc()
	{
		SceneManager::Initialize();
		Input::Initailize();
		Time::Initailize();
	}
}
