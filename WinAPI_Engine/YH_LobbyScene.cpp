#include "YH_LobbyScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Time.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

#include "YH_Animator.h"

namespace YH
{
	LobbyScene::LobbyScene()
	{

	}
	LobbyScene::~LobbyScene()
	{

	}

	void LobbyScene::Initialize()
	{
		#pragma region BackGround Settings
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(510.0f, 380.0f));

		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"WorldSelect");

		Animator* worldSelect = bg[0]->AddComponent<Animator>();
		worldSelect->CreateAnimation(L"World Select Movie", bg_0, Vector2(0.0f, 0.0f), Vector2(1024.0f, 768.0f),
			Vector2::Zero, 16, 0.125f);

		bg[0]->GetComponent<Transform>()->SetScale(Vector2(1.57f, 1.18f));

		worldSelect->PlayAnimation(L"World Select Movie");

		
		#pragma endregion

		Scene::Initialize();
	}

	void LobbyScene::Update()
	{
		Scene::Update();
	}

	void LobbyScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LobbyScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Lobby Scene";

		TextOut(hdc, 0, 0, str, 11);
	}
}