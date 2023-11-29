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
		renderer->SetTexture(bg_1);

		// 몬스터 애니메이션 적용
		m_Monster[0] = object::Instantiate<GameObject>(enums::LayerType::Character, Vector2(2255.f, 1325.f));
		
		graphics::Texture* mushroom = Resources::Find<graphics::Texture>(L"Mushroom");

		Animator* mushAnim = m_Monster[0]->AddComponent<Animator>();
		mushAnim->CreateAnimation(L"Mushroom Move", mushroom, Vector2(0.0f, 0.0f), Vector2(65.0f, 70.0f),
			Vector2::Zero, 3, 0.3f);

		mushAnim->PlayAnimation(L"Mushroom Move");

		// 이펙트 적용
		m_Effect[0] = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(2145.f, 1350.f));

		graphics::Texture* fairyTurn = Resources::Find<graphics::Texture>(L"FairyTurn");

		Animator* animator = m_Effect[0]->AddComponent<Animator>();
		animator->CreateAnimation(L"Fairy Turn Attack", fairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.02f);

		animator->PlayAnimation(L"Fairy Turn Attack");
		#pragma endregion
		
		#pragma region Player Setting
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(2340.0f, 1350.0f));

		graphics::Texture* player = Resources::Find<graphics::Texture>(L"Player_Idle");
		graphics::Texture* player_Walk = Resources::Find<graphics::Texture>(L"Player_Walk");
		graphics::Texture* player_Att = Resources::Find<graphics::Texture>(L"Player_Attack");

		m_Player->AddComponent<PlayerScript>();

		Animator* playerAnim = m_Player->AddComponent<Animator>();
		playerAnim->CreateAnimation(L"Player Idle", player, Vector2(0.0f, 0.0f), Vector2(140.0f, 91.0f),
			Vector2(55.0f, 91.0f), 4, 0.5f);

		playerAnim->CreateAnimation(L"Player Walk", player_Walk, Vector2(0.0f, 0.0f), Vector2(141.0f, 76.0f),
			Vector2(91.0f, 76.0f), 4, 0.3f);

		playerAnim->CreateAnimation(L"Player Attack", player_Att, Vector2(0.0f, 0.0f), Vector2(220.0f, 227.0f),
			Vector2(116.0f, 131.0f), 3, 0.15f);

		playerAnim->PlayAnimation(L"Player Idle");

		//m_Player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		#pragma endregion

		

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