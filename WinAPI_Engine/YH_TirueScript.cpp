#include "YH_TirueScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_HitEffect.h"
#include "YH_Transform.h"

#include "YH_Resources.h"
#include "YH_AudioSource.h"

namespace YH
{
	TirueScript::TirueScript() : m_State(TirueScript::State::Idle)
		, m_Animator(nullptr), m_Dir(TirueScript::Direction::Left), m_Time(0.0f), m_DeathTime(0.0f)
	{

	}

	TirueScript::~TirueScript()
	{

	}

	void TirueScript::Initialize()
	{

	}

	void TirueScript::Update()
	{
		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		switch (m_State)
		{
		case YH::TirueScript::State::Idle:
			Idle();
			break;
		case YH::TirueScript::State::Walk:
			Move();
			break;
		case YH::TirueScript::State::Attack:
			Attack();
			break;
		case YH::TirueScript::State::Death:
			Death();
			break;
		default:
			break;
		}
	}

	void TirueScript::LateUpdate()
	{

	}

	void TirueScript::Render(HDC hdc)
	{

	}

	void TirueScript::OnCollisionEnter(Collider* other)
	{
		enums::ColliderType type = other->GetCollType();

		if (!isDeath)
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

					AudioSource* as = GetOwner()->GetComponent<AudioSource>();
					AudioClip* ac = Resources::Load<AudioClip>(L"Fairy Turn Sound", L"..\\Resources\\SoundResource\\FairyTurnHit.mp3");
					as->SetClip(ac);
					as->Play();

					m_State = TirueScript::State::Death;
					m_Animator->PlayAnimation(L"Tirue Die");
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
				case enums::ColliderType::RimitGround:
				{
					if (m_Dir == (Direction::Right))
						m_Dir = (Direction::Left);
					else
						m_Dir = (Direction::Right);

					PlayWalkAnimationByDirection(m_Dir);
					break;
				}
			}
		}
	}

	void TirueScript::OnCollisionStay(Collider* other)
	{

	}

	void TirueScript::OnCollisionExit(Collider* other)
	{

	}

	void TirueScript::DeathEvent()
	{
		GetOwner()->SetActive(false);
		m_Time = 0.0f;
	}

	void TirueScript::ReSpawn()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > 5.0f)
		{
			GetOwner()->GetComponent<Transform>()->SetPosition(m_SpawnPos);
			GetOwner()->SetActive(true);
			m_Time = 0.0f;
			isDeath = false;

			m_State = TirueScript::State::Idle;

			switch (m_Dir)
			{
			case YH::TirueScript::Direction::Right:
				m_Animator->PlayAnimation(L"Tirue Right Idle");
				break;
			case YH::TirueScript::Direction::Left:
				m_Animator->PlayAnimation(L"Tirue Left Idle");
				break;
			}
		}
	}

	void TirueScript::Idle()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > m_NextFsmTime)
		{
			m_State = TirueScript::State::Walk;

			int direction = (rand() % 2);
			m_NextFsmTime = (rand() % 3 + 2);
			m_Dir = (Direction)direction;
			PlayWalkAnimationByDirection(m_Dir);
			m_Time = 0.0f;
		}
	}

	void TirueScript::Move()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > m_NextFsmTime)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				m_State = State::Idle;

				m_NextFsmTime = (rand() % 5 + 4);

				switch (m_Dir)
				{
				case YH::TirueScript::Direction::Right:
					m_Animator->PlayAnimation(L"Tirue Right Idle");
					break;
				case YH::TirueScript::Direction::Left:
					m_Animator->PlayAnimation(L"Tirue Left Idle");
					break;
				default:
					break;
				}
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);
	}

	void TirueScript::Attack()
	{

	}

	void TirueScript::Death()
	{
		isDeath = true;
	}

	void TirueScript::PlayWalkAnimationByDirection(Direction dir)
	{
		switch (dir)
		{
		case YH::TirueScript::Direction::Right:
			m_Animator->PlayAnimation(L"Tirue Right Move");
			break;
		case YH::TirueScript::Direction::Left:
			m_Animator->PlayAnimation(L"Tirue Left Move");
			break;
		default:
			break;
		}
	}

	void TirueScript::Translate(Transform* transform)
	{
		Vector2 pos = transform->GetPostion();

		switch (m_Dir)
		{
		case YH::TirueScript::Direction::Right:
			pos.x += 80.f * Time::DeltaTime();
			break;
		case YH::TirueScript::Direction::Left:
			pos.x -= 80.f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		transform->SetPosition(pos);
	}
}