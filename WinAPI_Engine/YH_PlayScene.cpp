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
#include "YH_TigurueScript.h"
#include "YH_TirueScript.h"
#include "YH_Ground.h"
#include "YH_GroundScript.h"
#include "YH_RopeScript.h"
#include "YH_PortalScript.h"

#include "YH_AudioClip.h"
#include "YH_AudioListener.h"
#include "YH_AudioSource.h"

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
		#pragma region Collision Settings
		CollisionManager::CollisionLayerCheck(LayerType::Player, LayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(LayerType::Player, LayerType::Ground, true);
		CollisionManager::CollisionLayerCheck(LayerType::Player, LayerType::Rope, true);

		CollisionManager::CollisionLayerCheck(LayerType::Monster, LayerType::Player, true);
		CollisionManager::CollisionLayerCheck(LayerType::Portal, LayerType::Player, true);
		CollisionManager::CollisionLayerCheck(LayerType::Rope, LayerType::Player, true);
		CollisionManager::CollisionLayerCheck(LayerType::Effect, LayerType::Monster, true);
		#pragma endregion

		#pragma region BackGround Settings
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SetAudioSource(bg[0]->AddComponent<AudioSource>());

		SpriteRenderer* renderer0 = bg[0]->AddComponent<SpriteRenderer>();
		renderer0->SetName(L"Back Ground");
		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"QueensRoad");
		renderer0->SetTexture(bg_0);

		m_Width = bg_0->GetWidth();
		m_Height = bg_0->GetHeight();

		Ground* ground = object::Instantiate<Ground>(LayerType::Ground, Vector2(10.0f, 800.0f));
		BoxCollider2D* groundColl = ground->AddComponent<BoxCollider2D>();
		groundColl->SetSize(Vector2(70.0f, 1.0f));
		ground->AddComponent<GroundScript>();

		GameObject* portal = object::Instantiate<GameObject>(enums::LayerType::Portal, Vector2(160.0f, 760.0f));
		BoxCollider2D* portal_0 = portal->AddComponent<BoxCollider2D>();
		portal_0->SetOffset(Vector2(-50.0f, -50.0f));
		portal_0->SetSize(Vector2(0.75f, 1.0f));
		portal->AddComponent<Script>();
		portal_0->SetCollType(ColliderType::Portal);

		PortalScript* portalSc = portal->AddComponent<PortalScript>();
		portalSc->SetNextScene(L"FlowerScene");
		portalSc->SetSpawnPos(Vector2(1829.0f, 1465.0f));
		#pragma endregion
		
		#pragma region Player Setting
		m_Player = object::Instantiate<Player>(enums::LayerType::Player, Vector2(2768.0f, 760.0f));
		object::DontDestroyOnLoad(m_Player);

		m_Player->AddComponent<Rigidbody>();
		m_Player->AddComponent<AudioListener>();
		m_Player->AddComponent<AudioSource>();

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

		#pragma endregion
		
		SetAudioClip(Resources::Load<AudioClip>(L"QueensGarden", L"..\\\Resources\\SoundResource\\QueensGarden.mp3"));
		GetAudioClip()->SetLoop(true);

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
		m_Camera = object::Instantiate<GameObject>(enums::LayerType::Camera);
		Camera* cameraComp = m_Camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		const std::vector<GameObject*>& player = SceneManager::GetGameObjects(LayerType::Player);

		cameraComp->GetBackWidth(m_Width);
		cameraComp->GetBackHeight(m_Height);
		cameraComp->SetTarget(player.front());

		GetAudioSource()->SetClip(GetAudioClip());
		GetAudioSource()->Play();

		UIManager::Push(UIType::HpBar);

		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		GetAudioSource()->Stop();

		Scene::OnExit();
	}
}