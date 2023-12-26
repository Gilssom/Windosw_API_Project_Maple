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

		Gdiplus::Graphics graphics(hdc);

		graphics.TranslateTransform(pos.x, pos.y);
		graphics.TranslateTransform(-pos.x, -pos.y);

		graphics.DrawImage(m_Texture->GetImage()
			, Gdiplus::Rect(
				pos.x + offset.x
				, pos.y + offset.y
				, m_Texture->GetWidth() 
				, m_Texture->GetHeight()
			)
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, Gdiplus::UnitPixel
			, nullptr
		);
	}

	void UIHUD::OnClear()
	{

	}
}