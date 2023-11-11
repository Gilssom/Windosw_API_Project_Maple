#include "YHGameObject.h"
#include "YHInput.h"
#include "YHTime.h"
#include "YHRocket.h"
#include "YH_Application.h"

namespace YH
{
	GameObject::GameObject() : m_X(0), m_Y(0), m_LookState(Lookfor::None)
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update(int type)
	{
		const int speed = 100.0f;

		if (type == 0)
		{
			if (Input::GetKey(KeyCode::A))
			{
				m_X -= speed * Time::DeltaTime();
				m_LookState = Lookfor::Left;
			}

			if (Input::GetKey(KeyCode::D))
			{
				m_X += speed * Time::DeltaTime();
				m_LookState = Lookfor::Right;
			}

			if (Input::GetKey(KeyCode::W))
			{
				m_Y -= speed * Time::DeltaTime();
				m_LookState = Lookfor::Up;
			}
				

			if (Input::GetKey(KeyCode::S))
			{
				m_Y += speed * Time::DeltaTime();
				m_LookState = Lookfor::Down;
			}		
		}

		if (type == 1)
		{
			if (Input::GetKey(KeyCode::Left))
				m_X -= 0.01f;

			if (Input::GetKey(KeyCode::Right))
				m_X += 0.01f;

			if (Input::GetKey(KeyCode::Up))
				m_Y -= 0.01f;

			if (Input::GetKey(KeyCode::Down))
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

			Ellipse(hdc, 0 + m_X, 0 + m_Y, 50 + m_X, 50 + m_Y);

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
