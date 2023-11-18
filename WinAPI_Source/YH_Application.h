// �ߺ��� ��������� �־ Ȯ���ؼ� ���� �ð��� �ٿ��ش�.
#pragma once 
#include "CommonInclude.h"
#include "YH_GameObject.h"
#include "YH_Rocket.h"

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
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);
		void AdJustWindowRect(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitializeEtc();

	private:
		HWND m_Hand;
		HDC m_Hdc;

		HDC m_BackHdc;
		HBITMAP m_BackBitmap;

		UINT m_Width;
		UINT m_Height;
	};
}