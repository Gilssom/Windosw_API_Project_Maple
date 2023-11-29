#include "YH_TitleScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

#include "YH_Animator.h"

namespace YH
{
	TitleScene::TitleScene()
	{

	}
	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		bg = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(800.0f, 400.0f));

		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Title");

		Animator* title = bg->AddComponent<Animator>();
		title->CreateAnimation(L"Title Movie", bg_1, Vector2(0.0f, 0.0f), Vector2(456.0f, 285.0f),
			Vector2::Zero, 25, 0.1f);
		title->PlayAnimation(L"Title Movie", false);

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"LobbyScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";

		TextOut(hdc, 0, 0, str, 11);
	}
}