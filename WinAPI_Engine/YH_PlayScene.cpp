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

#include "YH_Animator.h"

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
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Back Ground");
		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Leferae");

		// 애니메이션 추가 과정
		Animator* animator = bg[0]->AddComponent<Animator>();
		animator->CreateAnimation(L"Test", bg_1, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f),
			Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"Test");
		//renderer->SetTexture(bg_1);	
		#pragma endregion
		
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(2340.0f, 1300.0f));

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