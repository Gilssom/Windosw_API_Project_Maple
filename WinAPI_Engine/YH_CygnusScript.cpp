#include "YH_CygnusScript.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Resources.h"

namespace YH
{
	CygnusScript::CygnusScript() : m_State(CygnusScript::State::Idle)
		, m_Animator(nullptr), m_Dir(CygnusScript::Direction::Left)
		, m_Time(0.0f), m_DeathTime(0.0f)
	{

	}

	CygnusScript::~CygnusScript()
	{

	}

	void CygnusScript::Initialize()
	{
		
	}

	void CygnusScript::Update()
	{
		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		m_CygnusPos = GetOwner()->GetComponent<Transform>()->GetPostion();

		switch (m_State)
		{
		case YH::CygnusScript::State::Idle:
			Idle();
			break;
		case YH::CygnusScript::State::Move:
			Move();
			break;
		case YH::CygnusScript::State::Skill1:
			Skill1();
			break;
		case YH::CygnusScript::State::Skill2:
			Skill2();
			break;
		case YH::CygnusScript::State::Skill3:
			Skill3();
			break;
		default:
			break;
		}
	}

	void CygnusScript::LateUpdate()
	{

	}

	void CygnusScript::Render(HDC hdc)
	{

	}

	void CygnusScript::Idle()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > 5.0f)
		{
			int pattern = (rand() % 2);

			if (pattern == 0)
			{
				m_State = CygnusScript::State::Move;

				int direction = (rand() % 2);
				m_Dir = (Direction)direction;
				PlayWalkAnimationByDirection(m_Dir);
				m_Time = 0.0f;
			}
			else if (pattern == 1)
			{
				m_State = CygnusScript::State::Skill2;

				switch (m_Dir)
				{
				case YH::CygnusScript::Direction::Right:
					m_Animator->PlayAnimation(L"Cygnus Right Skill2", false);
					break;
				case YH::CygnusScript::Direction::Left:
					m_Animator->PlayAnimation(L"Cygnus Left Skill2", false);
					break;
				default:
					break;
				}
			}

			m_Time = 0.0f;
		}
	}

	void CygnusScript::Move()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > 5.0f)
		{
			/*int isLayDown = rand() % 2;
			if (isLayDown)
			{
				
			}*/

			m_State = State::Idle;

			switch (m_Dir)
			{
			case YH::CygnusScript::Direction::Right:
				m_Animator->PlayAnimation(L"Cygnus Right Idle");
				break;
			case YH::CygnusScript::Direction::Left:
				m_Animator->PlayAnimation(L"Cygnus Left Idle");
				break;
			default:
				break;
			}

			m_Time = 0.0f;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);
	}

	void CygnusScript::Skill1()
	{
	}

	void CygnusScript::Skill2()
	{
		if (m_Animator->IsComplete())
		{
			m_State = State::Idle;

			switch (m_Dir)
			{
			case YH::CygnusScript::Direction::Right:
				m_Animator->PlayAnimation(L"Cygnus Right Idle");
				break;
			case YH::CygnusScript::Direction::Left:
				m_Animator->PlayAnimation(L"Cygnus Left Idle");
				break;
			default:
				break;
			}
		}
	}

	void CygnusScript::Skill3()
	{

	}

	void CygnusScript::Death()
	{

	}

	void CygnusScript::PlayWalkAnimationByDirection(Direction dir)
	{
		switch (dir)
		{
		case YH::CygnusScript::Direction::Right:
			m_Animator->PlayAnimation(L"Cygnus Right Move");
			break;
		case YH::CygnusScript::Direction::Left:
			m_Animator->PlayAnimation(L"Cygnus Left Move");
			break;
		default:
			break;
		}
	}

	void CygnusScript::Translate(Transform* transform)
	{
		Vector2 pos = transform->GetPostion();

		switch (m_Dir)
		{
		case YH::CygnusScript::Direction::Right:
			pos.x += 20.f * Time::DeltaTime();
			break;
		case YH::CygnusScript::Direction::Left:
			pos.x -= 20.f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		transform->SetPosition(pos);
	}
}