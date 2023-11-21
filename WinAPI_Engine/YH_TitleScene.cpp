#include "YH_TitleScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Input.h"
#include "YH_PlayScene.h"
#include "YH_SceneManager.h"
#include "YH_Object.h"

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
		/*bg = new Player();

		Transform* transform = bg->AddComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_1.png");

		AddGameObject(bg, enums::LayerType::BackGround);*/

		bg = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(0, 0));

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_1.png");
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