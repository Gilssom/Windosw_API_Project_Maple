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
	PlayerScript::PlayerScript() : m_State(PlayerScript::State::Idle), m_Animator(nullptr), m_Dir(PlayerScript::Direction::Left)
	{
	}

	PlayerScript::~PlayerScript()
	{
		object::Destroy(m_FairyTurn);
		object::Destroy(m_BoringSong);
	}

	void PlayerScript::Initialize()
	{
		m_FairyTurn = object::Instantiate<GameObject>(enums::LayerType::Effect);
		graphics::Texture* leftFairyTurn = Resources::Find<graphics::Texture>(L"LeftFairyTurn");
		graphics::Texture* rightFairyTurn = Resources::Find<graphics::Texture>(L"RightFairyTurn");
		m_FairyAnim = m_FairyTurn->AddComponent<Animator>();
		m_FairyTurn->AddComponent<Transform>();

		//m_FairyAnim->CreateAnimationByFolder(L"Fairy Turn Test", L"..\\Resources\\MapleResourceTest\\Fairy_Turn",
			//Vector2::Zero, 0.02f);

		// ** 합쳐져 있는 Png 를 사용하면 속도가 급격하게 느려짐
		//    하지만 따로 따로 작업을 해놓은 리소스는 정상적인 속도로 재생됨 ( ? )
		m_FairyAnim->CreateAnimation(L"Fairy Turn Right Attack", rightFairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.04f);

		m_FairyAnim->CreateAnimation(L"Fairy Turn Left Attack", leftFairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.04f);

		m_FairyTurn->SetActive(false);

		m_FairyAnim->GetCompleteEvent(L"Fairy Turn Right Attack") = std::bind(&PlayerScript::Test, this);
		m_FairyAnim->GetCompleteEvent(L"Fairy Turn Left Attack") = std::bind(&PlayerScript::Test, this);

		// ** 내일 여쭤보기 **
		//std::function<void(bool)> test2 = std::bind(&PlayerScript::FairyEffOff, this, false);
		//m_FairyAnim->GetCompleteEvent2(L"Fairy Turn Left Attack") = std::bind(&PlayerScript::FairyEffOff, this, false);

		//------------------------------------------------------

		m_BoringSong = object::Instantiate<GameObject>(enums::LayerType::Effect);
		graphics::Texture* boringSong = Resources::Find<graphics::Texture>(L"BoringSong");
		graphics::Texture* LeftboringSongStart = Resources::Find<graphics::Texture>(L"LeftBoringSongStart");
		graphics::Texture* LeftboringSonging = Resources::Find<graphics::Texture>(L"LeftBoringSonging");
		graphics::Texture* LeftboringSongEnd = Resources::Find<graphics::Texture>(L"LeftBoringSongEnd");
		m_BoringAnim = m_BoringSong->AddComponent<Animator>();
		m_BoringSong->AddComponent<Transform>();

		m_BoringSong->SetActive(false);

		m_BoringAnim->CreateAnimation(L"Boring Song Left Attack", LeftboringSongStart, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 11, 0.01f);

		m_BoringAnim->CreateAnimation(L"Boring Song Right Attack", boringSong, Vector2(0.0f, 494.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 17, 0.01f);

		m_BoringAnim->CreateAnimation(L"Boring Song Left Attaking", LeftboringSonging, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 6, 0.01f);

		m_BoringAnim->CreateAnimation(L"Boring Song Right Attaking", boringSong, Vector2(3030.5f, 988.0f), Vector2(604.0f, 494.0f),
			Vector2::Zero, 5, 0.01f);

		m_BoringAnim->CreateAnimation(L"Boring Song Left End", LeftboringSongEnd, Vector2(0.0f, 0.0f), Vector2(382.0f, 408.0f),
			Vector2::Zero, 10, 0.01f);

		m_BoringAnim->CreateAnimation(L"Boring Song Right End", boringSong, Vector2(3820.0f, 1482.0f), Vector2(382.0f, 496.0f),
			Vector2::Zero, 10, 0.01f);

		m_BoringAnim->GetCompleteEvent(L"Boring Song Left Attack") = std::bind(&PlayerScript::BoringSongEffing, this);
		m_BoringAnim->GetCompleteEvent(L"Boring Song Right Attack") = std::bind(&PlayerScript::BoringSongEffing, this);
		
		m_BoringAnim->GetCompleteEvent(L"Boring Song Left End") = std::bind(&PlayerScript::BoringSongEffOnOff, this);
		m_BoringAnim->GetCompleteEvent(L"Boring Song Right End") = std::bind(&PlayerScript::BoringSongEffOnOff, this);
	}

	void PlayerScript::Update()
	{
		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		m_PlayerPos = GetOwner()->GetComponent<Transform>()->GetPostion();

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
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_FairyTurn->SetActive(true);

			m_FairyTurn->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x + 150.0f, m_PlayerPos.y));

			m_FairyAnim->PlayAnimation(L"Fairy Turn Right Attack", false);
			break;
		case YH::PlayerScript::Direction::Left:
			m_FairyTurn->SetActive(true);

			m_FairyTurn->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x - 150.0f, m_PlayerPos.y));

			m_FairyAnim->PlayAnimation(L"Fairy Turn Left Attack", false);
			break;
		}
	}

	void PlayerScript::BoringSongEff()
	{
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_BoringSong->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x, m_PlayerPos.y));

			m_BoringAnim->PlayAnimation(L"Boring Song Right Attack", false);
			break;
		case YH::PlayerScript::Direction::Left:
			m_BoringSong->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x, m_PlayerPos.y));

			m_BoringAnim->PlayAnimation(L"Boring Song Left Attack", false);
			break;
		}
	}

	void PlayerScript::BoringSongEffing()
	{
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_BoringAnim->PlayAnimation(L"Boring Song Right Attaking");
			break;
		case YH::PlayerScript::Direction::Left:
			m_BoringAnim->PlayAnimation(L"Boring Song Left Attaking");
			break;
		}
	}

	void PlayerScript::BoringSongEffend()
	{
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_BoringSong->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x + 85.0f, m_PlayerPos.y));

			m_BoringAnim->PlayAnimation(L"Boring Song Right End", false);
			break;
		case YH::PlayerScript::Direction::Left:
			m_BoringSong->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x - 85.0f, m_PlayerPos.y));

			m_BoringAnim->PlayAnimation(L"Boring Song Left End", false);
			break;
		}
	}

	void PlayerScript::Test()
	{
		m_FairyTurn->SetActive(false);
	}

	void PlayerScript::FairyEffOff(bool OnOff)
	{
		m_FairyTurn->SetActive(OnOff);
	}

	void PlayerScript::BoringSongEffOnOff()
	{
		m_BoringSong->SetActive(false);
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

		if (Input::GetKeyDown(KeyCode::D))
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

		if (Input::GetKeyDown(KeyCode::F))
		{
			m_State = PlayerScript::State::BoringSong;

			switch (m_Dir)
			{
			case YH::PlayerScript::Direction::Right:
				if(m_BoringSong->GetActive() == GameObject::State::Paused)
					m_BoringSong->SetActive(true);

				m_Animator->PlayAnimation(L"Player Boring Right Attack");
				break;
			case YH::PlayerScript::Direction::Left:
				if (m_BoringSong->GetActive() == GameObject::State::Paused)
					m_BoringSong->SetActive(true);

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
				BoringSongEffend();
				m_Animator->PlayAnimation(L"Player Right Idle");
				break;
			case YH::PlayerScript::Direction::Left:
				BoringSongEffend();
				m_Animator->PlayAnimation(L"Player Left Idle");
				break;
			default:
				break;
			}
		}
	}
}