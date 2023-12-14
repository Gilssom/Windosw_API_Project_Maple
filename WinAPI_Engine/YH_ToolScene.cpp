#include "YH_ToolScene.h"
#include "YH_Object.h"
#include "YH_Tile.h"
#include "YH_TilemapRenderer.h"
#include "YH_Resources.h"
#include "YH_Texture.h"
#include "YH_Camera.h"
#include "YH_Renderer.h"

namespace YH
{
	ToolScene::ToolScene()
	{

	}

	ToolScene::~ToolScene()
	{

	}

	void ToolScene::Initialize()
	{
		//GameObject* camera = object::Instantiate<GameObject>(enums::LayerType::None/*, Vector2(800.0f, 400.0f)*/);
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(LayerType::Tile);
		TilemapRenderer* tileRender = tile->AddComponent<TilemapRenderer>();
		//tileRender->SetTexture(Resources::Find<graphics::Texture>(L""));

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, (16 * 3) * i, 0, NULL);
			LineTo(hdc, (16 * 3) * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, (16 * 3) * i, NULL);
			LineTo(hdc, 1000, (16 * 3) * i);
		}
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}