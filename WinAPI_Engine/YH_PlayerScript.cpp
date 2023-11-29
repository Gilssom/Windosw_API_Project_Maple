#include "YH_PlayerScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"

namespace YH
{
	PlayerScript::PlayerScript() : m_State(PlayerScript::State::Idle), m_Animator(nullptr), m_Dir(PlayerScript::Direction::Left)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		switch (m_State)
		{
		case YH::PlayerScript::State::Idle:
			Idle();
			break;
		case YH::PlayerScript::State::Walk:
			Move();
			break;
		case YH::PlayerScript::State::Down:
			SitDown();
			break;
		case YH::PlayerScript::State::Attack:
			Attack();
			break;
		case YH::PlayerScript::State::FairyTurn:

			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			m_State = PlayerScript::State::Walk;

			m_Animator->PlayAnimation(L"Player Walk");

			if (m_Dir != PlayerScript::Direction::Right)
			{
				m_Animator->ImageFlip();
				m_Dir = PlayerScript::Direction::Right;
			}

		}
		if (Input::GetKey(KeyCode::Left))
		{
			m_State = PlayerScript::State::Walk;

			m_Animator->PlayAnimation(L"Player Walk");

			if (m_Dir != PlayerScript::Direction::Left)
			{
				m_Animator->ImageFlip();
				m_Dir = PlayerScript::Direction::Left;
			}

		}
		if (Input::GetKey(KeyCode::Up))
			m_State = PlayerScript::State::Idle;
		if (Input::GetKey(KeyCode::Down))
			m_State = PlayerScript::State::Down;

		if (Input::GetKey(KeyCode::LeftCtrl))
			m_State = PlayerScript::State::Attack;

	}

	void PlayerScript::Move()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();

		Vector2 pos = transform->GetPostion();

		if (Input::GetKey(KeyCode::Right))
			pos.x += 100.f * Time::DeltaTime();
		if (Input::GetKey(KeyCode::Left))
			pos.x -= 100.f * Time::DeltaTime();

		transform->SetPosition(pos);

		if (Input::GetKeyUp(KeyCode::Right) || Input::GetKeyUp(KeyCode::Left))
		{
			m_State = PlayerScript::State::Idle;
			m_Animator->PlayAnimation(L"Player Idle");
			m_Animator->ImageFlip();
		}
	}

	void PlayerScript::SitDown()
	{
		if (Input::GetKey(KeyCode::Down))
			m_Animator->PlayAnimation(L"Player Down");

		if (Input::GetKeyUp(KeyCode::Down))
		{
			m_State = PlayerScript::State::Idle;
			m_Animator->PlayAnimation(L"Idle");
		}
	}

	void PlayerScript::Attack()
	{
		if (Input::GetKey(KeyCode::LeftCtrl))
		{
			m_Animator->PlayAnimation(L"Player Attack");
		}

		if (Input::GetKeyUp(KeyCode::LeftCtrl))
		{
			m_State = PlayerScript::State::Idle;
			m_Animator->PlayAnimation(L"Idle");
		}
	}

	void PlayerScript::FairyTurn()
	{

	}
}
