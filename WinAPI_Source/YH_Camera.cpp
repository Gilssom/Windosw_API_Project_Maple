#include "YH_Camera.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"
#include "YH_Application.h"

extern YH::Application application;

namespace YH
{
	Camera::Camera() 
		: Component(enums::ComponentType::Camera)
		, m_Distance(Vector2::Zero)
		, m_Resolution(Vector2(1366.0f, 768.0f))
		, m_LookPosition(Vector2::Zero)
		, m_Target(nullptr)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
		//m_Resolution.x = application.GetWidth();
		//m_Resolution.y = application.GetHeight();
	}

	void Camera::Update()
	{
		if (m_Target)
		{
			Transform* transform = m_Target->GetComponent<Transform>();
			m_LookPosition = transform->GetPostion();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			m_LookPosition = cameraTr->GetPostion();
		}

		m_Distance = m_LookPosition - (m_Resolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}
}