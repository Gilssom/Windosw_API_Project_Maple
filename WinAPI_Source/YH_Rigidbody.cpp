#include "YH_Rigidbody.h"
#include "YH_Time.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"

namespace YH
{
	Rigidbody::Rigidbody() : Component(enums::ComponentType::Rigidbody)
		, isGrounded(false)
		, m_Mass(1.0f)
		, m_Friction(10.0f)
		, m_Force(Vector2::Zero)
		, m_Velocity(Vector2::Zero)
		, m_LimitedVelocity(Vector2(1000.0f, 1000.0f))
		, m_Gravity(Vector2(0.0f, 600.0f))
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
		// f (힘) = m (질량) x a (가속도)
		m_Accelation = m_Force / m_Mass;

		// 속도에 가속도 더하기
		m_Velocity += m_Accelation * Time::DeltaTime();

		if (isGrounded)
		{
			// 땅 위에 있을 때
			Vector2 gravity = m_Gravity;
			gravity.normalize();

			float dot = Vector2::Dot(m_Velocity, gravity);
			m_Velocity -= gravity * dot;
		}
		else
		{
			// 공중에 있을 때
			m_Velocity += m_Gravity * Time::DeltaTime();
		}

		// 최대 속도 제한
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

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 클 경우
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