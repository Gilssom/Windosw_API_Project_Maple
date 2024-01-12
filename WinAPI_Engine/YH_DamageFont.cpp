#include "YH_DamageFont.h"
#include "YH_GameObject.h"
#include "YH_UIManager.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"
#include "YH_Animator.h"

namespace YH
{
	DamageFont::DamageFont() :
		m_NumberImage{},
		m_Damage(0.f)
	{
		
	}

	DamageFont::~DamageFont()
	{

	}

	void DamageFont::Initialize()
	{
		for (int i = 0; i < 10; i++)
		{
			m_NumberImage[i] = new GameObject();
			SpriteRenderer* renderer = m_NumberImage[i]->AddComponent<SpriteRenderer>();
			renderer->SetName(m_Name[i]);
			graphics::Texture* texture = Resources::Find<graphics::Texture>(m_Name[i]);
			renderer->SetTexture(texture);
		}
	}

	void DamageFont::Update()
	{

	}

	void DamageFont::LateUpdate()
	{

	}

	void DamageFont::Render(HDC hdc)
	{

	}

	void DamageFont::ViewDamageFont()
	{
		Vector2 pos = GetOwner()->GetComponent<Transform>()->GetPostion();
		m_NumberImage[4]->GetComponent<Transform>()->SetPosition(Vector2(pos.x, pos.x - 100.0f));
	}
}