#include "YH_FlowerScene.h"
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
#include "YH_Monster.h"
#include "YH_Mushroom.h"
#include "YH_MushScript.h"
#include "YH_TigurueScript.h"
#include "YH_TirueScript.h"
#include "YH_Ground.h"
#include "YH_GroundScript.h"

namespace YH
{
	FlowerScene::FlowerScene() : m_Monster{}, bg(nullptr)
	{

	}

	FlowerScene::~FlowerScene()
	{

	}

	void FlowerScene::Initialize()
	{
		bg = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Back Ground");
		graphics::Texture* bgTex = Resources::Find<graphics::Texture>(L"RainDropFlower");
		renderer->SetTexture(bgTex);

		m_Width = bgTex->GetWidth();
		m_Height = bgTex->GetHeight();

		#pragma region Ground Collilder
		Ground* ground = object::Instantiate<Ground>(LayerType::Ground, Vector2(10.0f, 1508.0f));
		BoxCollider2D* groundColl = ground->AddComponent<BoxCollider2D>();
		groundColl->SetSize(Vector2(70.0f, 1.0f));
		ground->AddComponent<GroundScript>();

		GameObject* rope = object::Instantiate<GameObject>(LayerType::Rope, Vector2(1407.0f, 1246.0f));
		BoxCollider2D* ropeColl = rope->AddComponent<BoxCollider2D>();
		rope->AddComponent<Script>();
		ropeColl->SetOffset(Vector2(-12.0f, -135.0f));
		ropeColl->SetSize(Vector2(0.2f, 3.2f));
		ropeColl->SetCollType(ColliderType::Rope);
		#pragma endregion

		#pragma region Monster
		// 몬스터 적용
		m_Monster[0] = object::Instantiate<Monster>(enums::LayerType::Monster, Vector2(1240.0f, 1445.0f));
		m_Monster[0]->AddComponent<TigurueScript>();
		//m_Mushroom->GetComponent<Transform>()->SetScale(Vector2(1.2f, 1.2f));

		graphics::Texture* tigurueTex = Resources::Find<graphics::Texture>(L"Tigurue");

		BoxCollider2D* tigurueColl = m_Monster[0]->AddComponent<BoxCollider2D>();
		tigurueColl->SetOffset(Vector2(-30.0f, -30.0f));
		tigurueColl->SetSize(Vector2(0.6f, 0.8f));

		Animator* tigurueAnim = m_Monster[0]->AddComponent<Animator>();
		tigurueAnim->CreateAnimation(L"Tigurue Left Idle", tigurueTex, Vector2(0.0f, 0.0f), Vector2(60.0f, 82.0f),
			Vector2::Zero, 6, 0.1f);
		tigurueAnim->CreateAnimation(L"Tigurue Left Move", tigurueTex, Vector2(0.0f, 82.0f), Vector2(65.0f, 91.0f),
			Vector2::Zero, 6, 0.1f);
		tigurueAnim->CreateAnimation(L"Tigurue Right Idle", tigurueTex, Vector2(360.0f, 0.0f), Vector2(60.0f, 82.0f),
			Vector2::Zero, 6, 0.1f);
		tigurueAnim->CreateAnimation(L"Tigurue Right Move", tigurueTex, Vector2(390.0f, 82.0f), Vector2(65.0f, 91.0f),
			Vector2::Zero, 6, 0.1f);
		tigurueAnim->CreateAnimation(L"Tigurue Die", tigurueTex, Vector2(0.0f, 173.0f), Vector2(93.0f, 93.0f),
			Vector2::Zero, 12, 0.1f);

		tigurueAnim->PlayAnimation(L"Tigurue Left Idle");

		m_Monster[1] = object::Instantiate<Monster>(enums::LayerType::Monster, Vector2(1265.0f, 1455.0f));
		m_Monster[1]->AddComponent<TirueScript>();
		//m_Mushroom->GetComponent<Transform>()->SetScale(Vector2(1.2f, 1.2f));

		graphics::Texture* tirueTex = Resources::Find<graphics::Texture>(L"Tirue");

		BoxCollider2D* tirueColl = m_Monster[1]->AddComponent<BoxCollider2D>();
		tirueColl->SetOffset(Vector2(-30.0f, -30.0f));
		tirueColl->SetSize(Vector2(0.6f, 0.8f));

		Animator* tirueAnim = m_Monster[1]->AddComponent<Animator>();
		tirueAnim->CreateAnimation(L"Tirue Left Idle", tirueTex, Vector2(0.0f, 0.0f), Vector2(57.0f, 70.0f),
			Vector2::Zero, 6, 0.1f);
		tirueAnim->CreateAnimation(L"Tirue Left Move", tirueTex, Vector2(0.0f, 70.0f), Vector2(61.0f, 82.0f),
			Vector2::Zero, 6, 0.1f);
		tirueAnim->CreateAnimation(L"Tirue Right Idle", tirueTex, Vector2(342.0f, 0.0f), Vector2(57.0f, 70.0f),
			Vector2::Zero, 6, 0.1f);
		tirueAnim->CreateAnimation(L"Tirue Right Move", tirueTex, Vector2(366.0f, 70.0f), Vector2(61.0f, 82.0f),
			Vector2::Zero, 6, 0.1f);
		tirueAnim->CreateAnimation(L"Tirue Die", tirueTex, Vector2(0.0f, 152.0f), Vector2(82.0f, 93.0f),
			Vector2::Zero, 12, 0.1f);

		tirueAnim->PlayAnimation(L"Tirue Left Idle");
		#pragma endregion

		Scene::Initialize();
	}

	void FlowerScene::Update()
	{
		Scene::Update();
	}

	void FlowerScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void FlowerScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void FlowerScene::OnEnter()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::LayerType::Camera);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		//const std::vector<GameObject*>& camera = SceneManager::GetGameObjects(LayerType::Camera);
		const std::vector<GameObject*>& player = SceneManager::GetGameObjects(LayerType::Player);

		cameraComp->GetBackWidth(m_Width);
		cameraComp->GetBackHeight(m_Height);
		cameraComp->SetTarget(player.front());

		//camera.front()->GetComponent<Camera>()->GetBackWidth(m_Width);
		//camera.front()->GetComponent<Camera>()->GetBackHeight(m_Height);

		Scene::OnEnter();
	}

	void FlowerScene::OnExit()
	{
		Scene::OnExit();
	}
}
