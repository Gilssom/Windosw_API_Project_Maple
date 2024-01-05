#include "YH_Rigidbody.h"
#include "YH_Time.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "..\\WinAPI_Engine\\YH_PlayerScript.h"

namespace YH
{
	Rigidbody::Rigidbody() : Component(enums::ComponentType::Rigidbody)
		, isGrounded(false)
		, m_Mass(1.0f)
		, m_Friction(10.0f)
		//, m_Force(Vector2::Zero)
		, m_Velocity(Vector2::Zero)
		, m_LimitedVelocity(Vector2(1000.0f, 1000.0f))
		, m_Gravity(Vector2(0.0f, 800.0f))
		, m_Accelation(Vector2::Zero)
	{

	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Initialize()
	{

	}

	void Rigidbody::Update()
	{
		// f (��) = m (����) x a (���ӵ�)
		m_Accelation = m_Force / m_Mass;

		// �ӵ��� ���ӵ� ���ϱ�
		m_Velocity += m_Accelation * Time::DeltaTime();

		if (isGrounded)
		{
			// �� ���� ���� ��
			Vector2 gravity = m_Gravity;
			gravity.normalize();

			float dot = Vector2::Dot(m_Velocity, gravity);
			m_Velocity -= gravity * dot;
		}
		else
		{
			// ���߿� ���� ��
			m_Velocity += m_Gravity * Time::DeltaTime();
		}

		// �ִ� �ӵ� ����
		Vector2 gravity = m_Gravity;
		gravity.normalize();
		float dot = Vector2::Dot(m_Velocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = m_Velocity - gravity;

		if (m_LimitedVelocity.y < gravity.length())
		{
			gravity.normalize();
			gravity *= m_LimitedVelocity.y;
		}

		if (m_LimitedVelocity.x < sideVelocity.length())
		{
			sideVelocity.normalize();
			sideVelocity *= m_LimitedVelocity.x;
		}

		m_Velocity = gravity + sideVelocity;

		if (!(m_Velocity == Vector2::Zero))
		{
			Vector2 friction = -m_Velocity;
			friction = friction.normalize() * m_Friction * m_Mass * Time::DeltaTime();

			if (friction.y <= 0.0f)
				GetOwner()->GetComponent<PlayerScript>()->SetisJumpUp(false);
			else
				GetOwner()->GetComponent<PlayerScript>()->SetisJumpUp(true);

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� Ŭ ���
			if (m_Velocity.length() <= friction.length())
				m_Velocity = Vector2::Zero;
			else
				m_Velocity += friction;
		}

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();
		pos = pos + m_Velocity * Time::DeltaTime();
		transform->SetPosition(pos);

		m_Force.clear();
	}

	void Rigidbody::LateUpdate()
	{
		if(GetOwner()->GetComponent<Rigidbody>()->GetGround())
			m_Velocity = Vector2::Zero;
	}

	void Rigidbody::Render(HDC hdc)
	{

	}
}