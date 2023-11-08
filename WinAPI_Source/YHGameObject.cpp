#include "YHGameObject.h"

namespace YH
{
	GameObject::GameObject() : m_X(0), m_Y(0)
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
				m_X -= 0.01f;

			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
				m_X += 0.01f;

			if (GetAsyncKeyState(VK_UP) & 0x8000)
				m_Y -= 0.01f;

			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
				m_Y += 0.01f;
		}

		if (type == 1)
		{
			if (GetAsyncKeyState('A') & 0x8000)
				m_X -= 0.01f;

			if (GetAsyncKeyState('D') & 0x8000)
				m_X += 0.01f;

			if (GetAsyncKeyState('W') & 0x8000)
				m_Y -= 0.01f;

			if (GetAsyncKeyState('S') & 0x8000)
				m_Y += 0.01f;
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
	}

	void GameObject::MonsterRender(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

		SelectObject(hdc, oldbrush);

		DeleteObject(brush);
	}
	void GameObject::MonsterMoving()
	{
		int nx = rand() % 3;
		int ny = rand() % 3;

		if (nx == ny)
			return;

		if (m_X + dir[nx] < -100 || m_X + dir[nx] > 1500 || m_Y + dir[ny] < -100 || m_Y + dir[ny] > 800)
			return;

		m_X += dir[nx];
		m_Y += dir[ny];
	}
}
