#include "YH_UIExp.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"
#include "..\\WinAPI_Engine\\YH_PlayerScript.h"

namespace YH
{
	UIExp::UIExp()
		: UIBase(UIType::ExpBar)
	{

	}

	UIExp::~UIExp()
	{

	}

	void UIExp::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"MainExpBar");
	}

	void UIExp::OnActive()
	{

	}

	void UIExp::OnInActive()
	{

	}

	void UIExp::OnUpdate()
	{

	}

	void UIExp::OnLateUpdate()
	{

	}

	void UIExp::OnRender(HDC hdc)
	{
		const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		Vector2 pos = camera.front()->GetComponent<Camera>()->GetPosition();
		Vector2 offset = Vector2(-683.0f, -384.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		const std::vector<GameObject*>& player = SceneManager::GetGameObjects(LayerType::Player);
		PlayerScript* playerSc = player.front()->GetComponent<PlayerScript>();
		float exp_percent = playerSc->GetExpPercent();

		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		blend.SourceConstantAlpha = 255; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, m_Texture->GetWidth() * exp_percent
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, blend);
	}

	void UIExp::OnClear()
	{

	}
}