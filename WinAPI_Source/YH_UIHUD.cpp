#include "YH_UIHUD.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"

namespace YH
{
	UIHUD::UIHUD()
		: UIBase(UIType::HpBar)
	{

	}

	UIHUD::~UIHUD()
	{

	}

	void UIHUD::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"StatusBar");
	}

	void UIHUD::OnActive()
	{

	}

	void UIHUD::OnInActive()
	{

	}

	void UIHUD::OnUpdate()
	{

	}

	void UIHUD::OnLateUpdate()
	{

	}

	void UIHUD::OnRender(HDC hdc)
	{
		const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		Vector2 pos = camera.front()->GetComponent<Camera>()->GetPosition();
		Vector2 offset = Vector2(-100.0f, 300.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		blend.SourceConstantAlpha = 255; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, blend);
	}

	void UIHUD::OnClear()
	{

	}
}