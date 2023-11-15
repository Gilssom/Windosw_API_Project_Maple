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
		Player* player = new Player();

		Transform* transform = player->AddComponent<Transform>();
		transform->SetPos(800.f, 450.f);
		transform->SetSpeed(100.f);
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = player->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		AddGameObject(player);
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