#include "YH_TitleScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

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
		bg = object::Instantiate<Player>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		renderer->SetSize(Vector2(0.84f, 0.84f));
		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Title_Bg");
		renderer->SetTexture(bg_1);

		logo = object::Instantiate<Player>(enums::LayerType::UI);

		renderer = logo->AddComponent<SpriteRenderer>();
		renderer->SetSize(Vector2(0.84f, 0.84f));
		graphics::Texture* logo_1 = Resources::Find<graphics::Texture>(L"Title_Logo");
		renderer->SetTexture(logo_1);

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