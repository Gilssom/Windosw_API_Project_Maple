#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Time.h"

namespace YH
{
	Transform::Transform() : Component(enums::ComponentType::Transform), m_Speed(0), m_Scale(Vector2::Zero), m_Rotation(0.0f)
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
			//m_X -= m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Left;
		}

		if (Input::GetKey(KeyCode::D))
		{
			//m_X += m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Right;
		}

		if (Input::GetKey(KeyCode::W))
		{
			//m_Y -= m_Speed * Time::DeltaTime();
			//m_LookState = Lookfor::Up;
		}

		if (Input::GetKey(KeyCode::S))
		{
			//m_Y += m_Speed * Time::DeltaTime();
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