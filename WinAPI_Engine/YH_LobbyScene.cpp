#include "YH_LobbyScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"

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
		Player* bg = new Player();

		Transform* transform = bg->AddComponent<Transform>();
		transform->SetPos(Vector2(0, 0));
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_9_0.png");

		AddGameObject(bg);
	}

	void LobbyScene::Update()
	{
		Scene::Update();
	}

	void LobbyScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void LobbyScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}