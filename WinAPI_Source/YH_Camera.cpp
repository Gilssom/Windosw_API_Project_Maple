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
		, m_BackWidth(0.0f)
		, m_BackHeight(0.0f)
		, isSetting(false)
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
		if (!isSetting)
		{
			if (!CameraAreaCheck())
			{
				Transform* playerTf = m_Target->GetComponent<Transform>();

				if(playerTf->GetPostion().x < (m_Resolution.x / 2.0f))
					m_LookPosition = Vector2(m_Resolution.x / 2.0f, m_BackHeight - (m_Resolution.y / 2.0f));
				else
					m_LookPosition = Vector2(m_BackWidth - (m_Resolution.x / 2.0f), m_BackHeight - (m_Resolution.y / 2.0f));
			}
			else
				CameraSettings();

			isSetting = true;
		}

		if (CameraAreaCheck())
			CameraSettings();

		m_Distance = m_LookPosition - (m_Resolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
		
	}

	void Camera::Render(HDC hdc)
	{
	}

	bool Camera::CameraAreaCheck()
	{
		Transform* playerTf = m_Target->GetComponent<Transform>();

		if (playerTf->GetPostion().x < m_BackWidth - (m_Resolution.x / 2.0f)
			&& playerTf->GetPostion().x > 0.0f + (m_Resolution.x / 2.0f))
			return true;

		return false;
	}

	void Camera::CameraSettings()
	{
		if (m_Target)
		{
			Transform* transform = m_Target->GetComponent<Transform>();
			m_LookPosition = transform->GetPostion();

			if (transform->GetPostion().y > m_BackHeight - (m_Resolution.y / 2.0f))
				m_LookPosition.y = m_BackHeight - (m_Resolution.y / 2.0f);
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			m_LookPosition = cameraTr->GetPostion();
		}
	}
}