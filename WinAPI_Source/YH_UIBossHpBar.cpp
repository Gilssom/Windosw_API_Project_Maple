#include "YH_UIBossHpBar.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"
#include "..\\WinAPI_Engine\\YH_CygnusScript.h"

namespace YH
{
	UIBossHpBar::UIBossHpBar()
		: UIBase(UIType::BossHpBar)
	{

	}

	UIBossHpBar::~UIBossHpBar()
	{

	}

	void UIBossHpBar::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"BossHpBar");
	}

	void UIBossHpBar::OnActive()
	{

	}

	void UIBossHpBar::OnInActive()
	{

	}

	void UIBossHpBar::OnUpdate()
	{

	}

	void UIBossHpBar::OnLateUpdate()
	{

	}

	void UIBossHpBar::OnRender(HDC hdc)
	{
		const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		Vector2 pos = camera.front()->GetComponent<Camera>()->GetPosition();
		Vector2 offset = Vector2(-359.0f, -377.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		const std::vector<GameObject*>& boss = SceneManager::GetGameObjects(LayerType::Boss);
		CygnusScript* bossSc = boss.front()->GetComponent<CygnusScript>();
		float hp_percent = bossSc->GetHpPercent();

		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		blend.SourceConstantAlpha = 255; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, m_Texture->GetWidth() * hp_percent
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, blend);
	}

	void UIBossHpBar::OnClear()
	{

	}
}