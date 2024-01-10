#include "YH_Application.h"
#include "YH_Input.h"
#include "YH_Time.h"
#include "YH_Rocket.h"
#include "YH_SceneManager.h"
#include "YH_Resources.h"
#include "YH_CollisionManager.h"
#include "YH_UIManager.h"
#include "YH_Fmod.h"

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

		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
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
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		CollisionManager::Render(m_BackHdc);
		SceneManager::Render(m_BackHdc);
		Time::Render(m_BackHdc);
		UIManager::Render(m_BackHdc);

		CopyRenderTarget(m_BackHdc, m_Hdc);
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
	}

	void Application::ClearRenderTarget()
	{
		// ���� �ٲٱ�
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(m_BackHdc, grayBrush);

		Rectangle(m_BackHdc, -1, -1, 1600, 900);

		(HBRUSH)SelectObject(m_BackHdc, oldBrush);
		DeleteObject(grayBrush);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer �� �ִ� �������� ���� Buffer �� ���� ( �׷��ش� )
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
		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		m_BackBitmap = CreateCompatibleBitmap(m_Hdc, width, height);

		// ����۸� ����ų DC ����
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
