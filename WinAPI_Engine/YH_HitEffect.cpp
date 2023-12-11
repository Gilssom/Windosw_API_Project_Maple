#include "YH_HitEffect.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Resources.h"

namespace YH
{
	HitEffect::HitEffect() : m_Anim(nullptr)
	{

	}

	HitEffect::~HitEffect()
	{

	}

	void HitEffect::Initialize()
	{

	}

	void HitEffect::Update()
	{
		if (!m_Anim)
			m_Anim = GetOwner()->GetComponent<Animator>();

		if (m_Anim->IsComplete())
			object::Destroy(GetOwner());
	}

	void HitEffect::LateUpdate()
	{

	}

	void HitEffect::Render(HDC hdc)
	{

	}
}