#include "YH_PlayerScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Resources.h"

namespace YH
{
	PlayerScript::PlayerScript() : m_State(PlayerScript::State::Idle), m_Animator(nullptr), m_Dir(PlayerScript::Direction::Left),
		m_RightEff{}, m_LeftEff{}, m_RightEffAnim{}, m_LeftEffAnim{}
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		m_RightEff[0] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_RightEff[0]->AddComponent<Transform>();

		m_LeftEff[0] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_LeftEff[0]->AddComponent<Transform>();

		graphics::Texture* fairyTurn = Resources::Find<graphics::Texture>(L"FairyTurn");

		m_RightEffAnim[0] = m_RightEff[0]->AddComponent<Animator>();
		m_RightEffAnim[0]->CreateAnimation(L"Fairy Turn Right Attack", fairyTurn, Vector2(0.0f, 348.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.02f);

		m_LeftEffAnim[0] = m_LeftEff[0]->AddComponent<Animator>();
		m_LeftEffAnim[0]->CreateAnimation(L"Fairy Turn Left Attack", fairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.02f);

		m_RightEff[1] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_RightEff[1]->AddComponent<Transform>();

		m_LeftEff[1] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_LeftEff[1]->AddComponent<Transform>();

		graphics::Texture* boringSong = Resources::Find<graphics::Texture>(L"BoringSong");

		m_LeftEffAnim[1] = m_LeftEff[1]->AddComponent<Animator>();
		m_LeftEffAnim[1]->CreateAnimation(L"Boring Song Left Attack", boringSong, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 17, 0.05f);

		m_RightEffAnim[1] = m_RightEff[1]->AddComponent<Animator>();
		m_RightEffAnim[1]->CreateAnimation(L"Boring Song Right Attack", boringSong, Vector2(0.0f, 494.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 17, 0.05f);

		m_RightEff[2] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_RightEff[2]->AddComponent<Transform>();

		m_LeftEff[2] = object::Instantiate<GameObject>(enums::LayerType::Effect);
		m_LeftEff[2]->AddComponent<Transform>();

		graphics::Texture* boringSongEnd = Resources::Find<graphics::Texture>(L"BoringSongEnd");

		m_LeftEffAnim[2] = m_LeftEff[2]->AddComponent<Animator>();
		m_LeftEffAnim[2]->CreateAnimation(L"Boring Song Left End", boringSongEnd, Vector2(0.0f, 0.0f), Vector2(382.0f, 408.0f),
			Vector2::Zero, 10, 0.05f);

		m_RightEffAnim[2] = m_RightEff[2]->AddComponent<Animator>();
		m_RightEffAnim[2]->CreateAnimation(L"Boring Song Right End", boringSongEnd, Vector2(0.0f, 408.0f), Vector2(382.0f, 408.0f),
			Vector2::Zero, 10, 0.05f);
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
		case YH::PlayerScript::State::DownAttack:
			DownAttack();
			break;
		case YH::PlayerScript::State::Attack:
			Attack();
			break;
		case YH::PlayerScript::State::FairyTurn:
			FairyTurn();
			break;
		case YH::PlayerScript::State::BoringSong:
			BoringSong();
			break;
		default:
			break;
		}

		// 마우스 좌표 가져오는 로직
		if (Input::GetKey(KeyCode::LeftMouse))
		{
			//m_State = PlayerScript::State::FairyTurn;

			Vector2 mousePos = Input::GetMousePosition();
			int a = 0;
		}
	}

	void PlayerScript::LateUpdate()
	{

	}

	void PlayerScript::Render(HDC hdc)
	{

	}

	void PlayerScript::FairyTurnEff()
	{
		Vector2 ownerPos = GetOwner()->GetComponent<Transform>()->GetPostion();

		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_RightEff[0]->GetComponent<Transform>()->SetPosition(Vector2(ownerPos.x + 150.0f, ownerPos.y));

			m_RightEffAnim[0]->PlayAnimation(L"Fairy Turn Right Attack", false);
			break;
		case YH::PlayerScript::Direction::Left:
			m_LeftEff[0]->GetComponent<Transform>()->SetPosition(Vector2(ownerPos.x - 150.0f, ownerPos.y));

			m_LeftEffAnim[0]->PlayAnimation(L"Fairy Turn Left Attack", false);
			break;
		}
	}

	void PlayerScript::BoringSongEff()
	{
		Vector2 ownerPos = GetOwner()->GetComponent<Transform>()->GetPostion();

		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_RightEff[1]->GetComponent<Transform>()->SetPosition(Vector2(ownerPos.x, ownerPos.y));

			m_RightEffAnim[1]->PlayAnimation(L"Boring Song Right Attack");
			break;
		case YH::PlayerScript::Direction::Left:
			m_LeftEff[1]->GetComponent<Transform>()->SetPosition(Vector2(ownerPos.x, ownerPos.y));

			m_LeftEffAnim[1]->PlayAnimation(L"Boring Song Left Attack");
			break;
		}
	}

	void PlayerScript::Idle()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			m_State = PlayerScript::State::Walk;
			m_Dir = PlayerScript::Direction::Right;
			m_Animator->PlayAnimation(L"Player Right Walk");
		}
		if (Input::GetKey(KeyCode::Left))
		{
			m_State = PlayerScript::State::Walk;
			m_Dir = PlayerScript::Direction::Left;
			m_Animator->PlayAnimation(L"Player Left Walk");
		}
		if (Input::GetKey(KeyCode::Up))
		{
			m_State = PlayerScript::State::Idle;
		}
		if (Input::GetKey(KeyCode::Down))
		{
			m_State = PlayerScript::State::Down;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Down");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Down");
				break;
			}
		}

		if (Input::GetKey(KeyCode::LeftCtrl))
		{
			m_State = PlayerScript::State::Attack;
			
			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Attack", false);
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Attack", false);
				break;
			default:
				break;
			}
		}

		if (Input::GetKey(KeyCode::D))
		{
			m_State = PlayerScript::State::FairyTurn;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Fairy Right Attack", false);
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Fairy Left Attack", false);
				break;
			default:
				break;
			}
		}

		if (Input::GetKey(KeyCode::F))
		{
			m_State = PlayerScript::State::BoringSong;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Boring Right Attack");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Boring Left Attack");
				break;
			default:
				break;
			}
		}
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

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}

	void PlayerScript::SitDown()
	{
		if (Input::GetKey(KeyCode::LeftCtrl))
		{
			m_State = PlayerScript::State::DownAttack;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Down Attack", false);
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Down Attack", false);
				break;
			default:
				break;
			}
		}

		if (Input::GetKeyUp(KeyCode::Down))
		{
			m_State = PlayerScript::State::Idle;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}

	void PlayerScript::DownAttack()
	{
		if (m_Animator->IsComplete())
		{
			m_State = PlayerScript::State::Down;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Down");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Down");
				break;
			default:
				break;
			}
		}
	}

	void PlayerScript::Attack()
	{
		if (m_Animator->IsComplete())
		{
			m_State = PlayerScript::State::Idle;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}

	void PlayerScript::FairyTurn()
	{
		if (m_Animator->IsComplete())
		{
			m_State = PlayerScript::State::Idle;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}

	void PlayerScript::BoringSong()
	{
		if (Input::GetKeyUp(KeyCode::F))
		{
			m_State = PlayerScript::State::Idle;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}
}