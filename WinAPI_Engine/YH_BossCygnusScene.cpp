#include "YH_BossCygnusScene.h"
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

#include "YH_Cygnus.h"
#include "YH_CygnusScript.h"
#include "YH_Ground.h"
#include "YH_GroundScript.h"
#include "YH_PortalScript.h"

#include "YH_AudioClip.h"
#include "YH_AudioListener.h"
#include "YH_AudioSource.h"

namespace YH
{
	BossCygnusScene::BossCygnusScene()
	{

	}

	BossCygnusScene::~BossCygnusScene()
	{

	}

	void BossCygnusScene::Initialize()
	{
		#pragma region BackGround Settings
		SetSceneNumber(3);

		m_Bg = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SetAudioSource(m_Bg->AddComponent<AudioSource>());

		SpriteRenderer* renderer = m_Bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Back Ground");
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BossCygnusArena");
		renderer->SetTexture(bg);

		m_Width = bg->GetWidth();
		m_Height = bg->GetHeight();
		#pragma endregion

		#pragma region Collider Settings
		Ground* ground = object::Instantiate<Ground>(LayerType::Ground, Vector2(10.0f, 647.0f));
		BoxCollider2D* groundColl = ground->AddComponent<BoxCollider2D>();
		groundColl->SetSize(Vector2(70.0f, 1.0f));
		ground->AddComponent<GroundScript>();
		#pragma endregion

		#pragma region Cygnus Settings
		m_Cygnus = object::Instantiate<Cygnus>(enums::LayerType::Boss, Vector2(800.0f, 500.0f));
		m_Cygnus->AddComponent<CygnusScript>();
		graphics::Texture* cygnusTex = Resources::Find<graphics::Texture>(L"Cygnus");
		graphics::Texture* cygnusLeftSkill1Tex = Resources::Find<graphics::Texture>(L"LeftCygnusSkill1");
		graphics::Texture* cygnusRightSkill1Tex = Resources::Find<graphics::Texture>(L"RightCygnusSkill1");
		graphics::Texture* cygnusLeftSkill2Tex = Resources::Find<graphics::Texture>(L"LeftCygnusSkill2");
		graphics::Texture* cygnusRightSkill2Tex = Resources::Find<graphics::Texture>(L"RightCygnusSkill2");
		graphics::Texture* cygnusLeftSkill3Tex = Resources::Find<graphics::Texture>(L"LeftCygnusSkill3");
		graphics::Texture* cygnusRightSkill3Tex = Resources::Find<graphics::Texture>(L"RightCygnusSkill3");
		graphics::Texture* cygnusLeftDeathTex = Resources::Find<graphics::Texture>(L"LeftCygnusDeath");
		graphics::Texture* cygnusRightDeathTex = Resources::Find<graphics::Texture>(L"RightCygnusDeath");

		BoxCollider2D* cygnusColl = m_Cygnus->AddComponent<BoxCollider2D>();
		cygnusColl->SetSize(Vector2(1.5f, 2.0f));

		Animator* cygnusAnim = m_Cygnus->AddComponent<Animator>();

		cygnusAnim->CreateAnimation(L"Cygnus Left Idle", cygnusTex, Vector2(0.0f, 0.0f), Vector2(143.0f, 201.0f),
			Vector2::Zero, 8, 0.2f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Idle", cygnusTex, Vector2(0.0f, 201.0f), Vector2(143.0f, 201.0f),
			Vector2::Zero, 8, 0.2f);
		cygnusAnim->CreateAnimation(L"Cygnus Left Move", cygnusTex, Vector2(0.0f, 402.0f), Vector2(141.0f, 201.0f),
			Vector2::Zero, 8, 0.2f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Move", cygnusTex, Vector2(0.0f, 603.0f), Vector2(141.0f, 201.0f),
			Vector2::Zero, 8, 0.2f);

		cygnusAnim->CreateAnimation(L"Cygnus Left Skill1", cygnusLeftSkill1Tex, Vector2(0.0f, 0.0f), Vector2(342.0f, 351.0f),
			Vector2(0.0f, -50.0f), 32, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Skill1", cygnusRightSkill1Tex, Vector2(0.0f, 0.0f), Vector2(342.0f, 351.0f),
			Vector2(0.0f, -50.0f), 32, 0.1f, true);

		cygnusAnim->CreateAnimation(L"Cygnus Left Skill2", cygnusLeftSkill2Tex, Vector2(0.0f, 0.0f), Vector2(565.0f, 342.0f),
			Vector2(-45.0f, -70.0f), 19, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Skill2", cygnusRightSkill2Tex, Vector2(0.0f, 0.0f), Vector2(565.0f, 342.0f),
			Vector2(45.0f, -70.0f), 19, 0.1f, true);

		cygnusAnim->CreateAnimation(L"Cygnus Left Skill3", cygnusLeftSkill3Tex, Vector2(0.0f, 0.0f), Vector2(147.0f, 272.0f),
			Vector2(0.0f, -40.0f), 24, 0.15f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Skill3", cygnusRightSkill3Tex, Vector2(0.0f, 0.0f), Vector2(147.0f, 272.0f),
			Vector2(0.0f, -40.0f), 24, 0.15f, true);

		cygnusAnim->CreateAnimation(L"Cygnus Left Death", cygnusLeftDeathTex, Vector2(0.0f, 0.0f), Vector2(258.0f, 314.0f),
			Vector2(0.0f, -60.0f), 29, 0.15f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Death", cygnusRightDeathTex, Vector2(0.0f, 0.0f), Vector2(258.0f, 314.0f),
			Vector2(0.0f, -60.0f), 29, 0.15f, true);

		cygnusAnim->PlayAnimation(L"Cygnus Left Idle");
		#pragma endregion

		SetAudioClip(Resources::Load<AudioClip>(L"CygnusGarden", L"..\\\Resources\\SoundResource\\CygnusGardenBgm.mp3"));
		GetAudioClip()->SetLoop(true);

		Scene::Initialize();
	}

	void BossCygnusScene::Update()
	{
		Scene::Update();
	}

	void BossCygnusScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void BossCygnusScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void BossCygnusScene::OnEnter()
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

		m_Cygnus->GetComponent<CygnusScript>()->SetTarget(cameraComp->GetPlayer());

		UIManager::Push(UIType::BossHpBarBack);
		UIManager::Push(UIType::BossHpBar);

		Scene::OnEnter();
	}

	void BossCygnusScene::OnExit()
	{
		//GetAudioSource()->Stop();

		Scene::OnExit();
	}
}