#include "YH_PlayScene.h"
#include "YHGameObject.h"

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
		GameObject* obj = new GameObject();
		AddGameObject(obj);
	}

	void PlayScene::Update()
	{
		Scene::Update();
		/*for (GameObject* gameObj : m_GameObjects)
		{
			gameObj->Update(0);
		}*/
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