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
		//object::Destroy(m_FairyTurn);
	}

	void PlayerScript::Initialize()
	{
		#pragma region Fairy Turn
				m_FairyTurn = object::Instantiate<GameObject>(enums::LayerType::Effect);
				graphics::Texture* leftFairyTurn = Resources::Find<graphics::Texture>(L"LeftFairyTurn");
				graphics::Texture* rightFairyTurn = Resources::Find<graphics::Texture>(L"RightFairyTurn");
				m_FairyAnim = m_FairyTurn->AddComponent<Animator>();
				m_FairyTurn->AddComponent<Transform>();
				m_FairyTurn->SetActive(false);

				//m_FairyAnim->CreateAnimationByFolder(L"Fairy Turn Test", L"..\\Resources\\MapleResourceTest\\Fairy_Turn",
					//Vector2::Zero, 0.02f);

				// ** 합쳐져 있는 Png 를 사용하면 속도가 급격하게 느려짐
				//    하지만 따로 따로 작업을 해놓은 리소스는 정상적인 속도로 재생됨 ( ? )
				m_FairyAnim->CreateAnimation(L"Fairy Turn Right Attack", rightFairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
					Vector2::Zero, 11, 0.04f);

				m_FairyAnim->CreateAnimation(L"Fairy Turn Left Attack", leftFairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
					Vector2::Zero, 11, 0.04f);

				m_FairyAnim->GetCompleteEvent(L"Fairy Turn Right Attack") = std::bind(&PlayerScript::FairyTurnEffOff, this);
				m_FairyAnim->GetCompleteEvent(L"Fairy Turn Left Attack") = std::bind(&PlayerScript::FairyTurnEffOff, this);

				//delete leftFairyTurn;
				//delete rightFairyTurn;

				// ** 내일 여쭤보기 **
				//std::function<void(bool)> test2 = std::bind(&PlayerScript::FairyEffOff, this, false);
				//m_FairyAnim->GetCompleteEvent2(L"Fairy Turn Left Attack") = std::bind(&PlayerScript::FairyEffOff, this, false);
		#pragma endregion

		#pragma region Boring Song
				m_BoringSong = object::Instantiate<GameObject>(enums::LayerType::Effect);
				graphics::Texture* LeftboringSongStart = Resources::Find<graphics::Texture>(L"LeftBoringSongStart");
				graphics::Texture* LeftboringSonging = Resources::Find<graphics::Texture>(L"LeftBoringSonging");
				graphics::Texture* LeftboringSongEnd = Resources::Find<graphics::Texture>(L"LeftBoringSongEnd");
				graphics::Texture* RightboringSongStart = Resources::Find<graphics::Texture>(L"RightBoringSongStart");
				graphics::Texture* RightboringSonging = Resources::Find<graphics::Texture>(L"RightBoringSonging");
				graphics::Texture* RightboringSongEnd = Resources::Find<graphics::Texture>(L"RightBoringSongEnd");
				m_BoringAnim = m_BoringSong->AddComponent<Animator>();
				m_BoringSong->AddComponent<Transform>();
				m_BoringSong->SetActive(false);

				m_BoringAnim->CreateAnimation(L"Boring Song Left Attack", LeftboringSongStart, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
					Vector2::Zero, 11, 0.02f);

				m_BoringAnim->CreateAnimation(L"Boring Song Right Attack", RightboringSongStart, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
					Vector2::Zero, 11, 0.02f);

				m_BoringAnim->CreateAnimation(L"Boring Song Left Attaking", LeftboringSonging, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
					Vector2::Zero, 6, 0.01f);

				m_BoringAnim->CreateAnimation(L"Boring Song Right Attaking", RightboringSonging, Vector2(0.0f, 0.0f), Vector2(604.0f, 494.0f),
					Vector2::Zero, 6, 0.01f);

				m_BoringAnim->CreateAnimation(L"Boring Song Left End", LeftboringSongEnd, Vector2(0.0f, 0.0f), Vector2(382.0f, 408.0f),
					Vector2::Zero, 10, 0.05f);

				m_BoringAnim->CreateAnimation(L"Boring Song Right End", RightboringSongEnd, Vector2(0.0f, 0.0f), Vector2(382.0f, 408.0f),
					Vector2::Zero, 10, 0.05f);

				m_BoringAnim->GetCompleteEvent(L"Boring Song Left Attack") = std::bind(&PlayerScript::BoringSongEffing, this);
				m_BoringAnim->GetCompleteEvent(L"Boring Song Right Attack") = std::bind(&PlayerScript::BoringSongEffing, this);

				m_BoringAnim->GetCompleteEvent(L"Boring Song Left End") = std::bind(&PlayerScript::BoringSongEffOff, this);
				m_BoringAnim->GetCompleteEvent(L"Boring Song Right End") = std::bind(&PlayerScript::BoringSongEffOff, this);
		#pragma endregion

		#pragma region Boring Arrow
				// Test ( 화살은 추후 동적할당 or 오브젝트 풀링으로 구현할 예정
				GameObject* arrow = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(900.0f, 1120.0f));
				graphics::Texture* boringArrow = Resources::Find<graphics::Texture>(L"BoringArrow");
				Animator* arrowAnim = arrow->AddComponent<Animator>();
				//arrow->AddComponent<Transform>();
				arrow->SetActive(false);
				arrowAnim->CreateAnimation(L"Boring Arrow Left", boringArrow, Vector2(0.0f, 0.0f), Vector2(203.0f, 72.0f),
					Vector2::Zero, 3, 0.035f);
				arrowAnim->PlayAnimation(L"Boring Arrow Left");
		#pragma endregion

		#pragma region Howling Gale
				m_HowlingGale = object::Instantiate<GameObject>(enums::LayerType::Effect);
				graphics::Texture* LefthowlingStart = Resources::Find<graphics::Texture>(L"LeftHowlingStart");
				//graphics::Texture* RighthowlingStart = Resources::Find<graphics::Texture>(L"RightBoringSongStart");
				graphics::Texture* howlingAttack = Resources::Find<graphics::Texture>(L"HowlingAttack");
				graphics::Texture* howlingAttackEnd = Resources::Find<graphics::Texture>(L"HowlingAttackEnd");
				m_HowlingAnim = m_HowlingGale->AddComponent<Animator>();
				m_HowlingGale->AddComponent<Transform>();
				m_HowlingGale->SetActive(false);

				m_HowlingAnim->CreateAnimation(L"Howling Left Start", LefthowlingStart, Vector2(0.0f, 0.0f), Vector2(615.0f, 556.0f),
					Vector2(-50.0f, -20.0f), 15, 0.05f);

				m_HowlingAnim->CreateAnimation(L"Howling Attack", howlingAttack, Vector2(0.0f, 0.0f), Vector2(372.0f, 605.0f),
					Vector2(-100.0f, -270.0f), 14, 0.07f);

				m_HowlingAnim->CreateAnimation(L"Howling Attack End", howlingAttackEnd, Vector2(0.0f, 0.0f), Vector2(360.0f, 615.0f),
					Vector2(-100.0f, -270.0f), 5, 0.07f);

				m_HowlingAnim->GetCompleteEvent(L"Howling Left Start") = std::bind(&PlayerScript::HowlingEffing, this);
				m_HowlingAnim->GetCompleteEvent(L"Howling Attack") = std::bind(&PlayerScript::HowlingEffend, this);
				m_HowlingAnim->GetCompleteEvent(L"Howling Attack End") = std::bind(&PlayerScript::HowlingEffOff, this);
		#pragma endregion
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
		case YH::PlayerScript::State::Jump:
			Jump();
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
		case YH::PlayerScript::State::HowlingGale:
			HowlingGale();
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

	void PlayerScript::HowlingEff()
	{
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			m_HowlingGale->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x, m_PlayerPos.y));

			m_HowlingAnim->PlayAnimation(L"Howling Right Start", false);
			break;
		case YH::PlayerScript::Direction::Left:
			m_HowlingGale->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x, m_PlayerPos.y));

			m_HowlingAnim->PlayAnimation(L"Howling Left Start", false);
			break;
		}
	}

	void PlayerScript::HowlingEffing()
	{
		switch (m_Dir)
		{
		case YH::PlayerScript::Direction::Right:
			//m_HowlingGale->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x + 100.0f, m_PlayerPos.y));

			m_HowlingAnim->PlayAnimation(L"Howling Attack", false);
			break;
		case YH::PlayerScript::Direction::Left:
			//m_HowlingGale->GetComponent<Transform>()->SetPosition(Vector2(m_PlayerPos.x - 100.0f, m_PlayerPos.y));

			m_HowlingAnim->PlayAnimation(L"Howling Attack", false);
			break;
		}
	}

	void PlayerScript::HowlingEffend()
	{
		m_HowlingAnim->PlayAnimation(L"Howling Attack End", false);
	}

	void PlayerScript::HowlingEffOff()
	{
		if(m_HowlingAnim->IsComplete())
			m_HowlingGale->SetActive(false);
	}

	void PlayerScript::FairyTurnEffOff()
	{
		m_FairyTurn->SetActive(false);
	}

	void PlayerScript::BoringSongEffOff()
	{
		m_BoringSong->SetActive(false);
	}

	void PlayerScript::Idle()
	{
		#pragma region Player Normal State
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

				if (Input::GetKeyDown(KeyCode::LeftAlt))
				{
					m_State = PlayerScript::State::Jump;

					switch (m_Dir)
					{
					case YH::PlayerScript::Direction::Right:
						m_Animator->PlayAnimation(L"Player Right Jump");
						break;
					case YH::PlayerScript::Direction::Left:
						m_Animator->PlayAnimation(L"Player Left Jump");
						break;
					default:
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
		#pragma endregion

		#pragma region Player Skill
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
						if (m_BoringSong->GetState() == GameObject::State::Paused)
							m_BoringSong->SetActive(true);

						m_Animator->PlayAnimation(L"Player Boring Right Attack");
						break;
					case YH::PlayerScript::Direction::Left:
						if (m_BoringSong->GetState() == GameObject::State::Paused)
							m_BoringSong->SetActive(true);

						m_Animator->PlayAnimation(L"Player Boring Left Attack");
						break;
					default:
						break;
					}
				}

				if (Input::GetKeyDown(KeyCode::X))
				{
					m_State = PlayerScript::State::HowlingGale;

					switch (m_Dir)
					{
					case YH::PlayerScript::Direction::Right:
						if (m_HowlingGale->GetState() == GameObject::State::Paused)
							m_HowlingGale->SetActive(true);

						m_Animator->PlayAnimation(L"Player Howling Right Attack");
						break;
					case YH::PlayerScript::Direction::Left:
						if (m_HowlingGale->GetState() == GameObject::State::Paused)
							m_HowlingGale->SetActive(true);

						m_Animator->PlayAnimation(L"Player Howling Left Attack");
						break;
					default:
						break;
					}
				}
		#pragma endregion
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

	void PlayerScript::Jump()
	{
		// Anim Test > 이후 Ground Check 해서 풀 예정
		// GetKey 가 지금 이상함 눌렀다 떼도 Up 이 안됨
		if (Input::GetKeyUp(KeyCode::LeftAlt))
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

	void PlayerScript::HowlingGale()
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