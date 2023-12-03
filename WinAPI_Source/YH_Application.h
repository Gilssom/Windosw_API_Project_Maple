// 중복된 헤더파일이 있어도 확인해서 빌드 시간을 줄여준다.
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
		void Release();

		HWND GetHwnd() { return m_Hand; }
		HDC GetHdc() { return m_Hdc; }
		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }

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