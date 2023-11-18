#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"

namespace YH
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		Player* bg = new Player();

		Transform* transform = bg->AddComponent<Transform>();
		transform->SetPos(Vector2(0, 0));
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_284.png");

		AddGameObject(bg);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}