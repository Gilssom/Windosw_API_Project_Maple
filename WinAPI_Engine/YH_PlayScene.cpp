#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Input.h"
#include "YH_TitleScene.h"
#include "YH_SceneManager.h"
#include "YH_Object.h"

namespace YH
{
	PlayScene::PlayScene() : bg(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		/*bg = new Player();

		Transform* transform = bg->AddComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));
		transform->SetName(L"Transform");

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");

		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_284.png");

		AddGameObject(bg, LayerType::BackGround);*/
		bg = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(0, 0));

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_284.png");
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";

		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		/*Transform* transform = bg->GetComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));*/
	}
}