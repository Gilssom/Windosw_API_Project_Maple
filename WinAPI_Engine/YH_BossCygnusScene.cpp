#include "YH_BossCygnusScene.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"
#include "YH_Animator.h"

#include "YH_Cygnus.h"
#include "YH_CygnusScript.h"

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
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Back Ground");
		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"BossCygnusArena");
		renderer->SetTexture(bg_0);
		renderer->SetSize(Vector2(1.2f, 1.2f));
		#pragma endregion

		#pragma region Cygnus Settings
		m_Cygnus = object::Instantiate<Cygnus>(enums::LayerType::Boss, Vector2(800.0f, 400.0f));
		m_Cygnus->AddComponent<CygnusScript>();
		graphics::Texture* cygnusTex = Resources::Find<graphics::Texture>(L"Cygnus");
		graphics::Texture* cygnusLeftSkill2Tex = Resources::Find<graphics::Texture>(L"LeftCygnusSkill2");
		graphics::Texture* cygnusRightSkill2Tex = Resources::Find<graphics::Texture>(L"RightCygnusSkill2");
		Animator* cygnusAnim = m_Cygnus->AddComponent<Animator>();

		cygnusAnim->CreateAnimation(L"Cygnus Left Idle", cygnusTex, Vector2(0.0f, 0.0f), Vector2(143.0f, 201.0f),
			Vector2::Zero, 8, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Idle", cygnusTex, Vector2(0.0f, 201.0f), Vector2(143.0f, 201.0f),
			Vector2::Zero, 8, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Left Move", cygnusTex, Vector2(0.0f, 402.0f), Vector2(141.0f, 201.0f),
			Vector2::Zero, 8, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Move", cygnusTex, Vector2(0.0f, 603.0f), Vector2(141.0f, 201.0f),
			Vector2::Zero, 8, 0.1f);
		cygnusAnim->CreateAnimation(L"Cygnus Left Skill2", cygnusLeftSkill2Tex, Vector2(0.0f, 0.0f), Vector2(565.0f, 342.0f),
			Vector2(-45.0f, -70.0f), 19, 0.05f);
		cygnusAnim->CreateAnimation(L"Cygnus Right Skill2", cygnusRightSkill2Tex, Vector2(0.0f, 0.0f), Vector2(565.0f, 342.0f),
			Vector2(45.0f, -70.0f), 19, 0.05f, true);

		cygnusAnim->PlayAnimation(L"Cygnus Left Idle");
		#pragma endregion

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
		Scene::OnEnter();
		/*ameObject* camera = object::Instantiate<GameObject>(enums::LayerType::None, Vector2(800.0f, 400.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;*/
	}
	void BossCygnusScene::OnExit()
	{
		Scene::OnExit();
	}
}