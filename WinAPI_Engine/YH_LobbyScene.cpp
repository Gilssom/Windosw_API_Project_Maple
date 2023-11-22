#include "YH_LobbyScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

namespace YH
{
	LobbyScene::LobbyScene()
	{

	}
	LobbyScene::~LobbyScene()
	{

	}

	void LobbyScene::Initialize()
	{
		bg = object::Instantiate<Player>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg->AddComponent<SpriteRenderer>();
		renderer->SetName(L"Sprite Renderer");
		renderer->SetSize(Vector2(0.84f, 0.84f));

		// ���� ������Ʈ ����� ���� ���ҽ��� ���� Load �س����� ����.
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Lobby_Bg");
		renderer->SetTexture(bg);

		// �� �۾����� ���� ���� ��� ã�ƺ���
		logo = object::Instantiate<Player>(enums::LayerType::UI, Vector2(500, 100));

		renderer = logo->AddComponent<SpriteRenderer>();

		graphics::Texture* logo = Resources::Find<graphics::Texture>(L"Lobby_Logo");
		renderer->SetTexture(logo);

		Scene::Initialize();
	}

	void LobbyScene::Update()
	{
		Scene::Update();
	}

	void LobbyScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LobbyScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Lobby Scene";

		TextOut(hdc, 0, 0, str, 11);
	}
}