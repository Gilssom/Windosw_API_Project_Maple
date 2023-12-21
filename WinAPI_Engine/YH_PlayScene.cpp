#include "YH_PlayScene.h"
#include "YH_GameObject.h"
#include "YH_UIManager.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"
#include "YH_Animator.h"
#include "YH_BoxCollider2D.h"
#include "YH_CircleCollider2D.h"
#include "YH_CollisionManager.h"
#include "YH_Rigidbody.h"

#include "YH_Player.h"
#include "YH_PlayerScript.h"
#include "YH_Mushroom.h"
#include "YH_MushScript.h"
#include "YH_Ground.h"
#include "YH_GroundScript.h"

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
		CollisionManager::CollisionLayerCheck(LayerType::Player, LayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(LayerType::Player, LayerType::Ground, true);

		CollisionManager::CollisionLayerCheck(LayerType::Monster, LayerType::Player, true);
		CollisionManager::CollisionLayerCheck(LayerType::Portal, LayerType::Player, true);
		CollisionManager::CollisionLayerCheck(LayerType::Effect, LayerType::Monster, true);

		// main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::LayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		object::DontDestroyOnLoad(camera);

		#pragma region BackGround Settings
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SpriteRenderer* renderer0 = bg[0]->AddComponent<SpriteRenderer>();
		renderer0->SetName(L"Back Ground");
		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"QueensRoad");
		renderer0->SetTexture(bg_0);

		Ground* ground = object::Instantiate<Ground>(LayerType::Ground, Vector2(10.0f, 800.0f));
		BoxCollider2D* groundColl = ground->AddComponent<BoxCollider2D>();
		groundColl->SetSize(Vector2(-70.0f, 1.0f));
		ground->AddComponent<GroundScript>();

		GameObject* portal = object::Instantiate<GameObject>(enums::LayerType::Portal, Vector2(2800.0f, 760.0f));
		BoxCollider2D* portal_0 = portal->AddComponent<BoxCollider2D>();
		portal_0->SetOffset(Vector2(-50.0f, -50.0f));
		portal_0->SetSize(Vector2(0.75f, 1.0f));
		portal->AddComponent<Script>();
		portal_0->SetCollType(ColliderType::Portal);
		#pragma endregion

		#pragma region Monster
		// 몬스터 적용
		m_Mushroom = object::Instantiate<Mushroom>(enums::LayerType::Monster, Vector2(2650.0f, 760.0f));
		m_Mushroom->AddComponent<MushScript>();
		m_Mushroom->GetComponent<Transform>()->SetScale(Vector2(1.2f, 1.2f));

		graphics::Texture* mushroomTex = Resources::Find<graphics::Texture>(L"Mushroom");

		BoxCollider2D* mushColl = m_Mushroom->AddComponent<BoxCollider2D>();
		mushColl->SetOffset(Vector2(-22.5f, -10.0f));
		mushColl->SetSize(Vector2(0.5f, 0.5f));

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
		#pragma endregion
		
		#pragma region Player Setting
		// 플레이어 적용
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(2768.0f, 760.0f));
		object::DontDestroyOnLoad(m_Player);

		m_Player->AddComponent<Rigidbody>();

		graphics::Texture* player = Resources::Find<graphics::Texture>(L"Player");
		PlayerScript* playerScript = m_Player->AddComponent<PlayerScript>();

		BoxCollider2D* playerColl = m_Player->AddComponent<BoxCollider2D>();
		playerColl->SetOffset(Vector2(-20.0f, -32.5f));
		playerColl->SetSize(Vector2(0.4f, 0.5f));

		Animator* playerAnim = m_Player->AddComponent<Animator>();
		#pragma region Player Normal Animation
		playerAnim->CreateAnimation(L"Player Left Idle", player, Vector2(0.0f, 0.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.5f);
		playerAnim->CreateAnimation(L"Player Right Idle", player, Vector2(680.0f, 0.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.5f);

		playerAnim->CreateAnimation(L"Player Left Walk", player, Vector2(0.0f, 170.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.2f);
		playerAnim->CreateAnimation(L"Player Right Walk", player, Vector2(680.0f, 170.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 4, 0.2f);

		playerAnim->CreateAnimation(L"Player Left Attack", player, Vector2(0.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);
		playerAnim->CreateAnimation(L"Player Right Attack", player, Vector2(510.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);

		playerAnim->CreateAnimation(L"Player Left Down", player, Vector2(0.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);
		playerAnim->CreateAnimation(L"Player Right Down", player, Vector2(1020.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);

		playerAnim->CreateAnimation(L"Player Left Down Attack", player, Vector2(170.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.3f);
		playerAnim->CreateAnimation(L"Player Right Down Attack", player, Vector2(1190.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.3f);

		playerAnim->CreateAnimation(L"Player Left Jump", player, Vector2(340.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);
		playerAnim->CreateAnimation(L"Player Right Jump", player, Vector2(510.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);

		playerAnim->CreateAnimation(L"Player Fairy Left Attack", player, Vector2(0.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);
		playerAnim->CreateAnimation(L"Player Fairy Right Attack", player, Vector2(510.0f, 340.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 3, 0.15f);

		playerAnim->CreateAnimation(L"Player Boring Left Attack", player, Vector2(1020.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);
		playerAnim->CreateAnimation(L"Player Boring Right Attack", player, Vector2(1190.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);

		playerAnim->CreateAnimation(L"Player Howling Left Attack", player, Vector2(1020.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);
		playerAnim->CreateAnimation(L"Player Howling Right Attack", player, Vector2(1190.0f, 510.0f), Vector2(170.0f, 170.0f),
			Vector2::Zero, 1, 0.0f);
		#pragma endregion

		playerAnim->PlayAnimation(L"Player Left Idle");

		#pragma region Player Anim Event
		playerAnim->GetStartEvent(L"Player Fairy Left Attack") = std::bind(&PlayerScript::FairyTurnEff, playerScript);
		playerAnim->GetStartEvent(L"Player Fairy Right Attack") = std::bind(&PlayerScript::FairyTurnEff, playerScript);

		playerAnim->GetStartEvent(L"Player Boring Left Attack") = std::bind(&PlayerScript::BoringSongEff, playerScript);
		playerAnim->GetStartEvent(L"Player Boring Right Attack") = std::bind(&PlayerScript::BoringSongEff, playerScript);

		playerAnim->GetStartEvent(L"Player Howling Left Attack") = std::bind(&PlayerScript::HowlingEff, playerScript);
		playerAnim->GetStartEvent(L"Player Howling Right Attack") = std::bind(&PlayerScript::HowlingEff, playerScript);
#pragma endregion

		//m_Player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		#pragma endregion

		cameraComp->GetBackWidth(bg_0->GetWidth());
		cameraComp->GetBackHeight(bg_0->GetHeight());
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
			SceneManager::LoadScene(L"BossCygnusScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();

		UIManager::Push(UIType::HpBar);
	}

	void PlayScene::OnExit()
	{
		m_Player->GetComponent<Transform>()->SetPosition(Vector2(900.0f, 700.0f));

		Scene::OnExit();
	}
}