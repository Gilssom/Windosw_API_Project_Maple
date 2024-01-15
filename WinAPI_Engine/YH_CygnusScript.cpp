#include "YH_CygnusScript.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_HitEffect.h"
#include "YH_Resources.h"

#include "YH_BoxCollider2D.h"

#include "YH_ArrowScript.h"
#include "YH_DarkGenesis.h"

#include "..\\WinAPI_Source\\YH_UIManager.h"

namespace YH
{
	CygnusScript::CygnusScript() : m_State(CygnusScript::State::Idle)
		, m_Animator(nullptr), m_Dir(CygnusScript::Direction::Left)
		, m_Time(0.0f), m_DeathTime(0.0f), m_SkillDelay(0.0f), m_DoSkill(false)
		, m_MaxHp(63000000000), m_Hp(63000000000)
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
		case YH::CygnusScript::State::Death:
			Death();
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

	void CygnusScript::OnCollisionEnter(Collider* other)
	{
		enums::ColliderType type = other->GetCollType();

		if (m_State != CygnusScript::State::Death)
		{
			switch (type)
			{
				case enums::ColliderType::FairyTurn:
				{
					GameObject* fariyHit = object::Instantiate<GameObject>(enums::LayerType::Effect, GetOwner()->GetComponent<Transform>()->GetPostion());

					graphics::Texture* fariyHiteff = Resources::Find<graphics::Texture>(L"FairyTurnHit");
					Animator* FHanim = fariyHit->AddComponent<Animator>();
					FHanim->CreateAnimation(L"Fairy Hit Effect", fariyHiteff, Vector2(0.0f, 0.0f), Vector2(169.0f, 176.0f),
						Vector2::Zero, 6, 0.1f);
					FHanim->PlayAnimation(L"Fairy Hit Effect", false);

					fariyHit->AddComponent<HitEffect>();

					m_Hp -= 50000000;

					//DeathCheck();
					break;
				}
				case enums::ColliderType::HowlingGale:
				{
					GameObject* howlingHit = object::Instantiate<GameObject>(enums::LayerType::Effect, GetOwner()->GetComponent<Transform>()->GetPostion());

					graphics::Texture* howlingHiteff = Resources::Find<graphics::Texture>(L"HowlingHit");
					Animator* HHanim = howlingHit->AddComponent<Animator>();
					HHanim->CreateAnimation(L"Howling Hit Effect", howlingHiteff, Vector2(0.0f, 0.0f), Vector2(272.0f, 252.0f),
						Vector2::Zero, 6, 0.1f);
					HHanim->PlayAnimation(L"Howling Hit Effect", false);

					howlingHit->AddComponent<HitEffect>();

					m_Hp -= 70000000;
					break;
				}
				case enums::ColliderType::BoringArrow:
				{
					GameObject* arrowHit = object::Instantiate<GameObject>(enums::LayerType::Effect, GetOwner()->GetComponent<Transform>()->GetPostion());

					graphics::Texture* arrowHiteff = Resources::Find<graphics::Texture>(L"BoringHit");
					Animator* AHanim = arrowHit->AddComponent<Animator>();
					AHanim->CreateAnimation(L"Boring Hit Effect", arrowHiteff, Vector2(0.0f, 0.0f), Vector2(149.0f, 136.0f),
						Vector2::Zero, 7, 0.03f);
					AHanim->PlayAnimation(L"Boring Hit Effect", false);

					arrowHit->AddComponent<HitEffect>();

					m_Hp -= 20000000;

					object::Destroy(other->GetOwner());
					break;
				}
			}
		}
	}

	void CygnusScript::OnCollisionStay(Collider* other)
	{

	}

	void CygnusScript::OnCollisionExit(Collider* other)
	{

	}

	#pragma region Skill Effect
	void CygnusScript::Skill1Ball()
	{
		graphics::Texture* genesisTexture = Resources::Find<graphics::Texture>(L"CygnusSkill1Ball");

		for (int i = 0; i < 6; i++)
		{
			GameObject* genesis = object::Instantiate<GameObject>(enums::LayerType::Effect, m_GPos[i]);

			DarkGenesis* skillSc = genesis->AddComponent<DarkGenesis>();
			skillSc->SetSkillDelay(3.85f);
			skillSc->SetSkillSize(Vector2(2.3f, 5.5f));
			skillSc->SetSkillOffset(Vector2(-20.0f, 0.0f));

			Animator* genesisAnim = genesis->AddComponent<Animator>();

			genesisAnim->CreateAnimation(L"Dark Genesis", genesisTexture, Vector2(0.0f, 0.0f), Vector2(300.0f, 558.0f),
				Vector2(0.0f, 0.0f), 39, 0.15f);

			genesisAnim->PlayAnimation(L"Dark Genesis", false);
		}	
	}

	void CygnusScript::Skill2Ball()
	{
		GameObject* ball = object::Instantiate<GameObject>(enums::LayerType::Effect);

		Animator* ballAnim = ball->AddComponent<Animator>();
		graphics::Texture* ballTexture = Resources::Find<graphics::Texture>(L"CygnusSkill2Ball");

		ballAnim->CreateAnimation(L"Left Ball", ballTexture, Vector2(0.0f, 0.0f), Vector2(162.0f, 79.0f),
			Vector2(0.0f, 38.0f), 1, 0.0f);
		ballAnim->CreateAnimation(L"Right Ball", ballTexture, Vector2(162.0f, 0.0f), Vector2(162.0f, 79.0f),
			Vector2(0.0f, 38.0f), 1, 0.0f);

		ArrowScript* ballScript = ball->AddComponent<ArrowScript>();
		ballScript->SetPlayer(GetOwner());
		ballScript->SetSpeed(500.0f);

		BoxCollider2D* ballColl = ball->AddComponent<BoxCollider2D>();
		//ballColl->SetCollType(enums::ColliderType::BoringArrow);
		ballColl->SetSize(Vector2(1.f, 0.5f));

		Transform* cygnusTf = GetOwner()->GetComponent<Transform>();

		switch (m_Dir)
		{
		case YH::CygnusScript::Direction::Right:
			ballAnim->PlayAnimation(L"Right Ball");

			ballScript->m_Dest = Vector2::Right;
			ballColl->SetOffset(Vector2(20.0f, 35.0f));
			break;
		case YH::CygnusScript::Direction::Left:
			ballAnim->PlayAnimation(L"Left Ball");

			ballScript->m_Dest = Vector2::Left;
			ballColl->SetOffset(Vector2(-20.0f, 35.0f));
			break;
		}

		ball->GetComponent<Transform>()->SetPosition(cygnusTf->GetPostion());
	}

	void CygnusScript::Skill3Ball()
	{
		GameObject* fireArea = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(m_TargetPos.x, 430.0f));

		DarkGenesis* skillSc = fireArea->AddComponent<DarkGenesis>();
		skillSc->SetSkillDelay(2.65f);
		skillSc->SetSkillSize(Vector2(4.5f, 2.0f));
		skillSc->SetSkillOffset(Vector2(0.0f, 50.0f));

		Animator* fireAreaAnim = fireArea->AddComponent<Animator>();
		graphics::Texture* fireAreaTexture = Resources::Find<graphics::Texture>(L"CygnusSkill3Ball");

		fireAreaAnim->CreateAnimation(L"Fire Area", fireAreaTexture, Vector2(0.0f, 0.0f), Vector2(625.0f, 345.0f),
			Vector2(0.0f, 0.0f), 26, 0.15f);

		fireAreaAnim->PlayAnimation(L"Fire Area", false);
	}
	#pragma endregion

	void CygnusScript::DeathCheck()
	{
		m_State = CygnusScript::State::Death;

		switch (m_Dir)
		{
		case YH::CygnusScript::Direction::Right:
			m_Animator->PlayAnimation(L"Cygnus Right Death", false);
			break;
		case YH::CygnusScript::Direction::Left:
			m_Animator->PlayAnimation(L"Cygnus Left Death", false);
			break;
		}
	}

	void CygnusScript::Idle()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > 5.0f)
		{
			m_TargetPos = m_Target->GetComponent<Transform>()->GetPostion();

			if (m_CygnusPos.x >= m_TargetPos.x)
				m_Dir = Direction::Left;
			else
				m_Dir = Direction::Right;

			int pattern = (rand() % 4);

			//pattern = 2;

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
				m_State = CygnusScript::State::Skill1;

				switch (m_Dir)
				{
				case YH::CygnusScript::Direction::Right:
					m_Animator->PlayAnimation(L"Cygnus Right Skill1", false);
					break;
				case YH::CygnusScript::Direction::Left:
					m_Animator->PlayAnimation(L"Cygnus Left Skill1", false);
					break;
				default:
					break;
				}
			}
			else if (pattern == 2)
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
			else if (pattern == 3)
			{
				m_State = CygnusScript::State::Skill3;

				switch (m_Dir)
				{
				case YH::CygnusScript::Direction::Right:
					m_Animator->PlayAnimation(L"Cygnus Right Skill3", false);
					break;
				case YH::CygnusScript::Direction::Left:
					m_Animator->PlayAnimation(L"Cygnus Left Skill3", false);
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
		if (!m_DoSkill)
		{
			m_SkillDelay += Time::DeltaTime();

			if (m_SkillDelay > 0.55f)
			{
				Skill1Ball();
				m_DoSkill = true;
			}
		}

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

			m_SkillDelay = 0.0f;
			m_DoSkill = false;
		}
	}

	void CygnusScript::Skill2()
	{
		if (!m_DoSkill)
		{
			m_SkillDelay += Time::DeltaTime();

			if (m_SkillDelay > 0.85f)
			{
				Skill2Ball();
				m_DoSkill = true;
			}
		}

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

			m_SkillDelay = 0.0f;
			m_DoSkill = false;
		}
	}

	void CygnusScript::Skill3()
	{
		if (!m_DoSkill)
		{
			m_SkillDelay += Time::DeltaTime();

			if (m_SkillDelay > 0.55f)
			{
				Skill3Ball();
				m_DoSkill = true;
			}
		}

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

			m_SkillDelay = 0.0f;
			m_DoSkill = false;
		}
	}

	void CygnusScript::Death()
	{
		UIManager::Pop(UIType::BossHpBarBack);
		UIManager::Pop(UIType::BossHpBar);

		if (m_Animator->IsComplete())
			object::Destroy(GetOwner());
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