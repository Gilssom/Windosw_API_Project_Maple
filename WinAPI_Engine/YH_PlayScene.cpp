#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"
#include "YH_PlayerScript.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"

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
		// main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::LayerType::None, Vector2(800.0f, 400.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		#pragma region BackGround Settings
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(0, 100));

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Play_Mountain");
		renderer->SetTexture(bg_1);
		renderer->SetSize(Vector2(1.5f, 1.5f));

		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(bg_1->GetWidth() * 1.5f, 100));

		renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(bg_1);
		renderer->SetSize(Vector2(1.5f, 1.5f));

		bg[1] = object::Instantiate<GameObject>(enums::LayerType::Ground, Vector2(0, -40));

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_2 = Resources::Find<graphics::Texture>(L"Play_Ground");
		renderer->SetTexture(bg_2);
		renderer->SetSize(Vector2(1.2f, 1.2f));

		bg[1] = object::Instantiate<GameObject>(enums::LayerType::Ground, Vector2(bg_2->GetWidth() * 1.2f, -40));

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(bg_2);
		renderer->SetSize(Vector2(1.2f, 1.2f));

		bg[2] = object::Instantiate<GameObject>(enums::LayerType::Sky, Vector2(0, -800));

		renderer = bg[2]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_3 = Resources::Find<graphics::Texture>(L"Play_Sky");
		renderer->SetTexture(bg_3);
		renderer->SetSize(Vector2(2.0f, 2.0f));

		bg[3] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		renderer = bg[3]->AddComponent<SpriteRenderer>();
		graphics::Texture* cloud = Resources::Find<graphics::Texture>(L"Play_Cloud");
		renderer->SetTexture(cloud);

		bg[3] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(400, 0));

		renderer = bg[3]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(cloud);

		bg[3] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(800, 0));

		renderer = bg[3]->AddComponent<SpriteRenderer>();
		renderer->SetTexture(cloud);
		#pragma endregion
		
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(800.0f, 450.0f));

		SpriteRenderer* playerRender = m_Player->AddComponent<SpriteRenderer>();
		playerRender->SetName(L"Sprite Renderer");
		graphics::Texture* player = Resources::Find<graphics::Texture>(L"Player");
		playerRender->SetTexture(player);
		m_Player->AddComponent<PlayerScript>();

		cameraComp->SetTarget(m_Player);
		
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

		/*wchar_t str[50] = L"Play Scene";

		TextOut(hdc, 0, 0, str, 10);*/
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