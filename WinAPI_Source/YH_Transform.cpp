#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Time.h"

namespace YH
{
	Transform::Transform() : m_X(0), m_Y(0), m_Speed(0)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
		if (Input::GetKey(KeyCode::A))
		{
			m_X -= m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Left;
		}

		if (Input::GetKey(KeyCode::D))
		{
			m_X += m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Right;
		}

		if (Input::GetKey(KeyCode::W))
		{
			m_Y -= m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Up;
		}

		if (Input::GetKey(KeyCode::S))
		{
			m_Y += m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Down;
		}
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}