#include "YH_DarkGenesis.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"

#include "YH_BoxCollider2D.h"

namespace YH
{
	DarkGenesis::DarkGenesis() :
		m_Animator(nullptr), m_AttackTime(0.0f), m_Attack(false), m_SkillDelay(0.0f)
	{

	}

	DarkGenesis::~DarkGenesis()
	{

	}

	void DarkGenesis::Initialize()
	{

	}

	void DarkGenesis::Update()
	{
		m_AttackTime += Time::DeltaTime();

		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		if (m_Animator->IsComplete())
		{
			object::Destroy(GetOwner());
		}

		if (!m_Attack && m_AttackTime > m_SkillDelay)
		{
			BoxCollider2D* genesisColl = GetOwner()->AddComponent<BoxCollider2D>();
			//genesisColl->SetCollType(enums::ColliderType::HowlingGale);
			genesisColl->SetOffset(m_SkillOffset);
			//genesisColl->SetSize(Vector2(2.3f, 5.5f));
			genesisColl->SetSize(m_SkillSize);

			m_Attack = true;
		}
	}

	void DarkGenesis::LateUpdate()
	{

	}

	void DarkGenesis::Render(HDC hdc)
	{

	}
}