#include "YH_UIMinimap.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"
#include "..\\WinAPI_Engine\\YH_PlayerScript.h"

namespace YH
{
	UIMinimap::UIMinimap()
		: UIBase(UIType::Minimap)
	{

	}

	UIMinimap::~UIMinimap()
	{

	}

	void UIMinimap::OnInit()
	{
		m_Texture[0] = Resources::Find<graphics::Texture>(L"QueensRoadmap");
		m_Texture[1] = Resources::Find<graphics::Texture>(L"Flowermap");
		m_Texture[2] = Resources::Find<graphics::Texture>(L"BossReadymap");
		m_Texture[3] = Resources::Find<graphics::Texture>(L"BossAreamap");
	}

	void UIMinimap::OnActive()
	{

	}

	void UIMinimap::OnInActive()
	{

	}

	void UIMinimap::OnUpdate()
	{

	}

	void UIMinimap::OnLateUpdate()
	{

	}

	void UIMinimap::OnRender(HDC hdc)
	{
		const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		Vector2 pos = camera.front()->GetComponent<Camera>()->GetPosition();
		Vector2 offset = Vector2(-683.0f, -381.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		int sceneNumber = SceneManager::GetScene()->GetSceneNumber();

		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		blend.SourceConstantAlpha = 255; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, m_Texture[sceneNumber]->GetWidth()
			, m_Texture[sceneNumber]->GetHeight()
			, m_Texture[sceneNumber]->GetHdc()
			, 0, 0
			, m_Texture[sceneNumber]->GetWidth()
			, m_Texture[sceneNumber]->GetHeight()
			, blend);
	}

	void UIMinimap::OnClear()
	{

	}
}