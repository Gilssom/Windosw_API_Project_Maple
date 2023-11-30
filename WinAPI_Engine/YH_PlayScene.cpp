#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"
#include "YH_Animator.h"

#include "YH_Player.h"
#include "YH_PlayerScript.h"
#include "YH_Mushroom.h"
#include "YH_MushScript.h"

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
		m_Mushroom = object::Instantiate<Mushroom>(enums::LayerType::Character, Vector2(2255.f, 1325.f));
		m_Mushroom->AddComponent<MushScript>();

		graphics::Texture* mushroomTex = Resources::Find<graphics::Texture>(L"Mushroom");

		Animator* mushAnim = m_Mushroom->AddComponent<Animator>();
		mushAnim->CreateAnimation(L"Mush Left Idle", mushroomTex, Vector2(0.0f, 0.0f), Vector2(60.0f, 60.0f),
			Vector2::Zero, 2, 0.2f);
		mushAnim->CreateAnimation(L"Mush Left Move", mushroomTex, Vector2(0.0f, 60.0f), Vector2(60.0f, 60.0f),
			Vector2::Zero, 3, 0.2f);
		mushAnim->CreateAnimation(L"Mush Right Idle", mushroomTex, Vector2(120.0f, 0.0f), Vector2(60.0f, 60.0f),
			Vector2::Zero, 2, 0.2f);
		mushAnim->CreateAnimation(L"Mush Right Move", mushroomTex, Vector2(180.0f, 60.0f), Vector2(60.0f, 60.0f),
			Vector2::Zero, 3, 0.2f);
		mushAnim->CreateAnimation(L"Mush Die", mushroomTex, Vector2(0.0f, 120.0f), Vector2(60.0f, 60.0f),
			Vector2::Zero, 12, 0.1f);

		mushAnim->PlayAnimation(L"Mush Left Idle");

		// 이펙트 적용
		m_Effect[0] = object::Instantiate<GameObject>(enums::LayerType::Effect, Vector2(2145.f, 1350.f));

		graphics::Texture* fairyTurn = Resources::Find<graphics::Texture>(L"FairyTurn");

		Animator* animator = m_Effect[0]->AddComponent<Animator>();
		animator->CreateAnimation(L"Fairy Turn Attack", fairyTurn, Vector2(0.0f, 0.0f), Vector2(580.0f, 348.0f),
			Vector2::Zero, 11, 0.02f);

		animator->PlayAnimation(L"Fairy Turn Attack");
		#pragma endregion
		
		#pragma region Player Setting
		// 플레이어 적용
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(2340.0f, 1350.0f));

		graphics::Texture* player = Resources::Find<graphics::Texture>(L"Player");
		//graphics::Texture* player_Walk = Resources::Find<graphics::Texture>(L"Player_Walk");
		//graphics::Texture* player_Att = Resources::Find<graphics::Texture>(L"Player_Attack");

		m_Player->AddComponent<PlayerScript>();

		Animator* playerAnim = m_Player->AddComponent<Animator>();
		playerAnim->CreateAnimation(L"Player Left Idle", player, Vector2(0.0f, 0.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.5f);
		playerAnim->CreateAnimation(L"Player Right Idle", player, Vector2(680.0f, 0.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.5f);

		playerAnim->CreateAnimation(L"Player Left Walk", player, Vector2(0.0f, 170.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.3f);
		playerAnim->CreateAnimation(L"Player Right Walk", player, Vector2(680.0f, 170.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.3f);

		playerAnim->CreateAnimation(L"Player Left Attack", player, Vector2(0.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);
		playerAnim->CreateAnimation(L"Player Right Attack", player, Vector2(510.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);

		playerAnim->PlayAnimation(L"Player Left Idle");

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