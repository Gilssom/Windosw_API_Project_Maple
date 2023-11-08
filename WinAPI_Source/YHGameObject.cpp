#include "YHGameObject.h"

namespace YH
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update(int type)
	{
		if (type == 0)
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				m_X -= 0.01f;
			}

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				m_X += 0.01f;
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{
				m_Y -= 0.01f;
			}

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				m_Y += 0.01f;
			}
		}

		if (type == 1)
		{
			if (GetAsyncKeyState('A') & 0x8000)
			{
				m_X -= 0.01f;
			}

			if (GetAsyncKeyState('D') & 0x8000)
			{
				m_X += 0.01f;
			}

			if (GetAsyncKeyState('W') & 0x8000)
			{
				m_Y -= 0.01f;
			}

			if (GetAsyncKeyState('S') & 0x8000)
			{
				m_Y += 0.01f;
			}
		}

		if (type == 2)
		{
			if (GetAsyncKeyState('H') & 0x8000)
			{
				m_X -= 0.01f;
			}

			if (GetAsyncKeyState('K') & 0x8000)
			{
				m_X += 0.01f;
			}

			if (GetAsyncKeyState('U') & 0x8000)
			{
				m_Y -= 0.01f;
			}

			if (GetAsyncKeyState('J') & 0x8000)
			{
				m_Y += 0.01f;
			}
		}
	}
	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc, int type)
	{
		if (type == 0)
		{
			HBRUSH brush = CreateSolidBrush(RGB(125, 255, 255));

			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

			SelectObject(hdc, oldbrush);

			DeleteObject(brush);
		}
		
		if (type == 1)
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Ellipse(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

			SelectObject(hdc, oldbrush);

			DeleteObject(brush);
		}

		if (type == 2)
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));

			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Rectangle(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

			SelectObject(hdc, oldbrush);

			DeleteObject(brush);
		}

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(m_Hdc, redPen);

		//Ellipse(m_Hdc, 800, 80, 850, 300);
		////Ellipse(m_Hdc, 10, 10, 50, 50);

		//SelectObject(m_Hdc, oldPen);
		//DeleteObject(redPen);

		//// 기본으로 자주 사용되는 GDI 오브젝트를 미리 DC 안에 만들어뒀는데
		//// 그 오브젝트들을 Stock Object 라고 한다.
		//HBRUSH graybrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
		//oldbrush = (HBRUSH)SelectObject(m_Hdc, graybrush);

		//Rectangle(m_Hdc, 800, 100, 900, 400);

		//SelectObject(m_Hdc, oldbrush);
	}
}
