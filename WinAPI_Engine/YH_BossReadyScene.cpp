#include "YH_BossReadyScene.h"
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

#include "YH_Ground.h"
#include "YH_GroundScript.h"
#include "YH_PortalScript.h"

#include "YH_AudioClip.h"
#include "YH_AudioListener.h"
#include "YH_AudioSource.h"

#include "YH_UIFadeInOut.h"

namespace YH
{
	BossReadyScene::BossReadyScene()
	{

	}

	BossReadyScene::~BossReadyScene()
	{

	}

	void BossReadyScene::Initialize()
	{
		#pragma region BackGround Settings
		SetSceneNumber(2);

		m_Bg = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SetAudioSource(m_Bg->AddComponent<AudioSource>());

		SpriteRenderer* renderer = m_Bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Back Ground");
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BossArenaReady");
		renderer->SetTexture(bg);

		m_Width = bg->GetWidth();
		m_Height = bg->GetHeight();
		#pragma endregion

		#pragma region Collider Settings
		Ground* ground = object::Instantiate<Ground>(LayerType::Ground, Vector2(10.0f, 637.0f));
		BoxCollider2D* groundColl = ground->AddComponent<BoxCollider2D>();
		groundColl->SetSize(Vector2(70.0f, 1.0f));
		ground->AddComponent<GroundScript>();
		#pragma endregion

		#pragma region Portal
		GameObject* portal_0 = object::Instantiate<GameObject>(enums::LayerType::Portal, Vector2(226.0f, 542.0f));
		BoxCollider2D* portal_0_Coll = portal_0->AddComponent<BoxCollider2D>();
		portal_0_Coll->SetSize(Vector2(0.75f, 1.0f));
		portal_0_Coll->SetCollType(ColliderType::Portal);

		PortalScript* portalSc_0 = portal_0->AddComponent<PortalScript>();
		portalSc_0->SetNextScene(L"FlowerScene");
		portalSc_0->SetSpawnPos(Vector2(160.0f, 760.0f));

		GameObject* portal_1 = object::Instantiate<GameObject>(enums::LayerType::Portal, Vector2(1500.0f, 542.0f));
		BoxCollider2D* portal_1_Coll = portal_1->AddComponent<BoxCollider2D>();
		portal_1_Coll->SetCollType(ColliderType::Portal);

		PortalScript* portalSc_1 = portal_1->AddComponent<PortalScript>();
		portalSc_1->SetNextScene(L"BossCygnusScene");
		portalSc_1->SetSpawnPos(Vector2(153.0f, 586.0f));
		#pragma endregion

		SetAudioClip(Resources::Load<AudioClip>(L"BossReadyArena", L"..\\\Resources\\SoundResource\\CygnusReadyBgm.mp3"));
		GetAudioClip()->SetLoop(true);

		Scene::Initialize();
	}

	void BossReadyScene::Update()
	{
		if (UIFadeInOut::GetNeedPop() && !check)
		{
			UIManager::Pop(UIType::FadeInOut);
			check = true;
		}

		Scene::Update();
	}

	void BossReadyScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void BossReadyScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void BossReadyScene::OnEnter()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::LayerType::Camera);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		const std::vector<GameObject*>& player = SceneManager::GetGameObjects(LayerType::Player);

		cameraComp->GetBackWidth(m_Width);
		cameraComp->GetBackHeight(m_Height);
		cameraComp->SetTarget(player.front());

		GetAudioSource()->SetClip(GetAudioClip());
		GetAudioSource()->Play();

		Scene::OnEnter();
	}

	void BossReadyScene::OnExit()
	{
		GetAudioSource()->Stop();

		check = false;

		Scene::OnExit();
	}
}