#include "YH_MushScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_HitEffect.h"

#include "YH_Resources.h"

namespace YH
{
	MushScript::MushScript() : m_State(MushScript::State::Idle)
		, m_Animator(nullptr), m_Dir(MushScript::Direction::Left), m_Time(0.0f), m_DeathTime(0.0f)
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

		//m_DeathTime += Time::DeltaTime();
		//if (m_DeathTime > 6.0f)
			//object::Destroy(GetOwner());

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
		case YH::MushScript::State::Death:
			Death();
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

	void MushScript::OnCollisionEnter(Collider* other)
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

	void MushScript::OnCollisionStay(Collider* other)
	{

	}

	void MushScript::OnCollisionExit(Collider* other)
	{

	}

	void MushScript::Idle()
	{
		m_Time += Time::DeltaTime();

		if (m_Time > 5.0f)
		{
			m_State = MushScript::State::Walk;

			int direction = (rand() % 2);
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
				m_State = State::Idle;

				switch (m_Dir)
				{
				case YH::MushScript::Direction::Right:
					m_Animator->PlayAnimation(L"Tigurue Right Idle");
					break;
				case YH::MushScript::Direction::Left:
					m_Animator->PlayAnimation(L"Tigurue Left Idle");
					break;
				default:
					break;
				}
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Translate(tr);
	}

	void MushScript::Attack()
	{

	}

	void MushScript::Death()
	{
		m_Animator->PlayAnimation(L"Tigurue Die");
	}

	void MushScript::PlayWalkAnimationByDirection(Direction dir)
	{
		switch (dir)
		{
		case YH::MushScript::Direction::Right:
			m_Animator->PlayAnimation(L"Tigurue Right Move");
			break;
		case YH::MushScript::Direction::Left:
			m_Animator->PlayAnimation(L"Tigurue Left Move");
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
			pos.x += 80.f * Time::DeltaTime();
			break;
		case YH::MushScript::Direction::Left:
			pos.x -= 80.f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		transform->SetPosition(pos);
	}
}