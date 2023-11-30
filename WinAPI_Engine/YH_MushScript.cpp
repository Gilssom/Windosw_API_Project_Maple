#include "YH_MushScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"

namespace YH
{
	MushScript::MushScript() : m_State(MushScript::State::Idle)
		, m_Animator(nullptr), m_Dir(MushScript::Direction::Left), m_Time(0.0f)
	{

	}
	MushScript::~MushScript()
	{

	}

	void MushScript::Initialize()
	{

	}
	void MushScript::Update()
	{
		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		switch (m_State)
		{
		case YH::MushScript::State::Idle:
			Idle();
			break;
		case YH::MushScript::State::Walk:
			Move();
			break;
		case YH::MushScript::State::Attack:
			Attack();
			break;
		case YH::MushScript::State::FairyTurn:
			break;
		default:
			break;
		}
	}
	void MushScript::LateUpdate()
	{

	}
	void MushScript::Render(HDC hdc)
	{

	}

	void MushScript::Idle()
	{
		m_Time += Time::DeltaTime();
		if (m_Time > 3.0f)
		{
			m_State = MushScript::State::Walk;
			int direction = (rand() % 4);
			m_Dir = (Direction)direction;
			PlayWalkAnimationByDirection(m_Dir);
			m_Time = 0.0f;
		}
	}

	void MushScript::Move()
	{
		m_Time += Time::DeltaTime();
		if (m_Time > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				//m_State = State::LayDown;
				m_Animator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				//m_State = State::SitDown;
				m_Animator->PlayAnimation(L"SitDown", false);
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);
	}

	void MushScript::Attack()
	{

	}

	void MushScript::PlayWalkAnimationByDirection(Direction dir)
	{
		switch (dir)
		{
		case YH::MushScript::Direction::Right:
			break;
		case YH::MushScript::Direction::Left:
			break;
		default:
			break;
		}
	}

	void MushScript::Translate(Transform* transform)
	{
		Vector2 pos = transform->GetPostion();

		switch (m_Dir)
		{
		case YH::MushScript::Direction::Right:
			pos.x += 100.f * Time::DeltaTime();
			break;
		case YH::MushScript::Direction::Left:
			pos.x -= 100.f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		transform->SetPosition(pos);
	}
}