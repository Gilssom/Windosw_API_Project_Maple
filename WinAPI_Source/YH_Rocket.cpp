#include "YH_Rocket.h"

namespace YH
{
	Rocket::Rocket() : m_X(0), m_Y(0), m_Speed(1.0f), m_Dir(4), isOut(false)
	{

	}

	Rocket::~Rocket()
	{

	}

	void Rocket::Update()
	{
		switch (m_Dir)
		{
		case 0 :
			m_X -= m_Speed;
			break;
		case 1:
			m_X += m_Speed;
			break;
		case 2:
			m_Y -= m_Speed;
			break;
		case 3:
			m_Y += m_Speed;
			break;
		case 4:
			m_Y -= m_Speed;
			break;
		}
	}

	void Rocket::CreateRocket(float x, float y, int dir)
	{
		m_X = x;
		m_Y = y;
		m_Dir = dir;
	}

	void Rocket::RocketRender(HDC hdc)
	{
		if (!AreaOutCheck())
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Ellipse(hdc, 25 + m_X, 25 + m_Y, 75 + m_X, 75 + m_Y);

			SelectObject(hdc, oldbrush);

			DeleteObject(brush);
		}
	}
	bool Rocket::AreaOutCheck()
	{
		if (m_X < -100 || m_X > 1600 || m_Y < -100 || m_Y > 1600)
			return true;
		else
			return false;
	}
}