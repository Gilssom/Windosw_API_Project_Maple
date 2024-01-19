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
#include "YH_Time.h"

namespace YH
{
	DamageFont::DamageFont() :
		m_NumberImage{},
		m_Damage(0.f),
		m_Count(0),
		m_DeathTime(0.0f),
		m_DamageFonts{},
		m_CriEffect(nullptr)
	{
		
	}

	DamageFont::~DamageFont()
	{

	}

	void DamageFont::Initialize()
	{

	}

	void DamageFont::Update()
	{
		m_DeathTime += Time::DeltaTime();

		if (m_DeathTime > 2.0f)
		{
			for (int i = 0; i < m_DamageFonts.size(); i++)
			{
				m_DamageFonts[i]->SetActive(false);
			}

			m_DamageFonts.erase(m_DamageFonts.begin(), m_DamageFonts.end());
			object::Destroy(GetOwner());
		}
	}

	void DamageFont::LateUpdate()
	{
		for (int i = 0; i < m_DamageFonts.size(); i++)
		{
			Transform* transform = m_DamageFonts[i]->GetComponent<Transform>();

			Vector2 pos = transform->GetPostion();

			pos.y -= 10.f * Time::DeltaTime();

			transform->SetPosition(pos);
		}
	}

	void DamageFont::Render(HDC hdc)
	{

	}

	void DamageFont::ViewDamageFont(bool critical)
	{
		Vector2 pos = m_Monster->GetComponent<Transform>()->GetPostion();

		int Xcnt = 0;

		if (critical)
		{
			m_CriEffect = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(0.0f, 0.0f));
			SpriteRenderer* renderer = m_CriEffect->AddComponent<SpriteRenderer>();
			graphics::Texture* texture = Resources::Find<graphics::Texture>(L"CriEffect");
			renderer->SetTexture(texture);
			m_DamageFonts.push_back(m_CriEffect);
		}

		while (m_Damage != 0)
		{
			int temp = m_Damage % 10;

			m_NumberImage[temp] = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(0.0f, 0.0f));
			SpriteRenderer* renderer = m_NumberImage[temp]->AddComponent<SpriteRenderer>();
			renderer->SetName(m_Name[temp]);
			graphics::Texture* texture = nullptr;

			if (!critical)
			{
				texture = Resources::Find<graphics::Texture>(m_Name[temp]);
				renderer->SetTexture(texture);
			}
			else
			{
				texture = Resources::Find<graphics::Texture>(L"Cri" + m_Name[temp]);
				renderer->SetTexture(texture);
			}

			m_NumberImage[temp]->GetComponent<Transform>()->SetPosition(Vector2(pos.x - ((texture->GetWidth() - 10.0f) * Xcnt), pos.y - (100.0f + 24.5f * m_Count)));

			if (m_CriEffect)
				m_CriEffect->GetComponent<Transform>()->SetPosition(
					Vector2(pos.x - ((texture->GetWidth() - 10.0f) * Xcnt) - 23.0f
							, pos.y - (100.0f + 24.5f * m_Count) - 18.0f));

			m_DamageFonts.push_back(m_NumberImage[temp]);

			Xcnt++;
			m_Damage /= 10;
		}
	}
}