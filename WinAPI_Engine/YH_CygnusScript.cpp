#include "YH_CygnusScript.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_HitEffect.h"
#include "YH_Resources.h"

#include "YH_ArrowScript.h"

namespace YH
{
	CygnusScript::CygnusScript() : m_State(CygnusScript::State::Idle)
		, m_Animator(nullptr), m_Dir(CygnusScript::Direction::Left)
		, m_Time(0.0f), m_DeathTime(0.0f), m_SkillDelay(0.0f), m_DoSkill(false)
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

	void CygnusScript::OnCollisionEnter(Collider* other)
	{
		enums::ColliderType type = other->GetCollType();

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

			object::Destroy(other->GetOwner());
			break;
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

		Transform* playerTf = GetOwner()->GetComponent<Transform>();

		switch (m_Dir)
		{
		case YH::CygnusScript::Direction::Right:
			ballAnim->PlayAnimation(L"Right Ball");

			ballScript->m_Dest = Vector2::Right;
			break;
		case YH::CygnusScript::Direction::Left:
			ballAnim->PlayAnimation(L"Left Ball");

			ballScript->m_Dest = Vector2::Left;
			break;
		}

		ball->GetComponent<Transform>()->SetPosition(playerTf->GetPostion()/* + (ballScript->m_Dest * 100.0f)*/);
		//ball->GetComponent<Transform>()->SetScale(Vector2(0.7f, 0.7f));
	}
	#pragma endregion

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
		if (!m_DoSkill)
		{
			m_SkillDelay += Time::DeltaTime();

			if (m_SkillDelay > 0.55f)
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