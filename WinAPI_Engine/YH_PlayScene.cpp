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
	PlayScene::PlayScene() : bg { }
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		bg[0] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(0, 0));

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		renderer->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_284.png");

		bg[1] = object::Instantiate<Player>(enums::LayerType::Tree, Vector2(0, 0));

		SpriteRenderer* renderer2 = bg[1]->AddComponent<SpriteRenderer>();
		renderer2->SetName(L"Sprite Renderer"); 
		renderer2->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_52.png");

		bg[2] = object::Instantiate<Player>(enums::LayerType::Ground, Vector2(0, 300));

		SpriteRenderer* renderer3 = bg[2]->AddComponent<SpriteRenderer>();
		renderer3->SetName(L"Sprite Renderer");
		renderer3->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_222.png");
		
		bg[3] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(0, 0));

		SpriteRenderer* renderer4 = bg[3]->AddComponent<SpriteRenderer>();
		renderer4->SetName(L"Sprite Renderer");
		renderer4->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Cloud_7.png");

		bg[4] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(320, 0));

		SpriteRenderer* renderer5 = bg[4]->AddComponent<SpriteRenderer>();
		renderer5->SetName(L"Sprite Renderer");
		renderer5->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Cloud_7.png");

		bg[5] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(640, 0));

		SpriteRenderer* renderer6 = bg[5]->AddComponent<SpriteRenderer>();
		renderer6->SetName(L"Sprite Renderer");
		renderer6->ImageLoad(L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Cloud_7.png");
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