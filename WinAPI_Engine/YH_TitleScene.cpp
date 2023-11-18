#include "YH_TitleScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"

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
		Player* bg = new Player();

		Transform* transform = bg->AddComponent<Transform>();
		transform->SetPos(Vector2(0, 0));
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_1.png");

		AddGameObject(bg);
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}