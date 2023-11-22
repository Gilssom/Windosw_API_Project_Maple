#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

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
		#pragma region BackGround Settings
		bg[0] = object::Instantiate<Player>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Play_Bg_1");
		renderer->SetTexture(bg_1);

		bg[0] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(bg_1->GetWidth(), 0));

		renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(bg_1);

		bg[1] = object::Instantiate<Player>(enums::LayerType::Tree);

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_2 = Resources::Find<graphics::Texture>(L"Play_Bg_2");
		renderer->SetTexture(bg_2);

		bg[1] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(bg_2->GetWidth(), 0));

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(bg_2);

		bg[2] = object::Instantiate<Player>(enums::LayerType::Ground, Vector2(0, 300));

		renderer = bg[2]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_3 = Resources::Find<graphics::Texture>(L"Play_Bg_3");
		renderer->SetTexture(bg_3);

		bg[2] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(bg_3->GetWidth(), 300));

		renderer = bg[2]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(bg_3);

		bg[3] = object::Instantiate<Player>(enums::LayerType::BackGround);

		renderer = bg[3]->AddComponent<SpriteRenderer>();
		graphics::Texture* cloud = Resources::Find<graphics::Texture>(L"Play_Cloud");
		renderer->SetTexture(cloud);

		bg[4] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(320, 0));

		renderer = bg[4]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(cloud);

		bg[5] = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(640, 0));

		renderer = bg[5]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(cloud);
		#pragma endregion
		
		Scene::Initialize();
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