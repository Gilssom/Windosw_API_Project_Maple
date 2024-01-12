#include "YH_UIHpBar.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"
#include "..\\WinAPI_Engine\\\YH_PlayerScript.h"

namespace YH
{
	UIHpBar::UIHpBar()
		: UIBase(UIType::HpBar)
	{

	}

	UIHpBar::~UIHpBar()
	{

	}

	void UIHpBar::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"HpBar");
	}

	void UIHpBar::OnActive()
	{

	}

	void UIHpBar::OnInActive()
	{

	}

	void UIHpBar::OnUpdate()
	{

	}

	void UIHpBar::OnLateUpdate()
	{

	}

	void UIHpBar::OnRender(HDC hdc)
	{
		const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		Vector2 pos = camera.front()->GetComponent<Camera>()->GetPosition();
		Vector2 offset = Vector2(-73.0f, 333.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		const std::vector<GameObject*>& player = SceneManager::GetGameObjects(LayerType::Player);
		PlayerScript* playerSc = player.front()->GetComponent<PlayerScript>();
		float hp_percent = playerSc->GetHpPercent();

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

	void UIHpBar::OnClear()
	{

	}
}