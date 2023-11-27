#include "YH_LobbyScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Time.h"
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
		#pragma region BackGround Settings
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround);

		SpriteRenderer* renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetSize(Vector2(1.57f, 1.18f));
		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"WorldSelect");
		renderer->SetTexture(bg_0);6

		/*bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(bg_0->GetWidth() * 1.2f, 150));

		renderer = bg[0]->AddComponent<SpriteRenderer>();
		renderer->SetSize(Vector2(1.2f, 1.2f));
		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Lobby_Mountain");
		renderer->SetTexture(bg_1);

		bg[1] = object::Instantiate<GameObject>(enums::LayerType::Sky, Vector2(0, -150));

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		renderer->SetSize(Vector2(1.5f, 1.5f));
		graphics::Texture* bg_2 = Resources::Find<graphics::Texture>(L"Lobby_Sky");
		renderer->SetTexture(bg_2);

		bg[1] = object::Instantiate<GameObject>(enums::LayerType::Sky, Vector2(bg_2->GetWidth() * 1.5f, -150));

		renderer = bg[1]->AddComponent<SpriteRenderer>();
		renderer->SetSize(Vector2(1.5f, 1.5f));
		graphics::Texture* bg_3 = Resources::Find<graphics::Texture>(L"Lobby_Sky");
		renderer->SetTexture(bg_3);

		bg[2] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(0, 0));

		renderer = bg[2]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_4 = Resources::Find<graphics::Texture>(L"Lobby_Cloud");
		renderer->SetTexture(bg_4);

		bg[3] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(-2048, 0));

		renderer = bg[3]->AddComponent<SpriteRenderer>();
		graphics::Texture* bg_5 = Resources::Find<graphics::Texture>(L"Lobby_Cloud");
		renderer->SetTexture(bg_5);

		logo = object::Instantiate<GameObject>(enums::LayerType::UI, Vector2(500, 100));
		renderer = logo->AddComponent<SpriteRenderer>();
		graphics::Texture* logo = Resources::Find<graphics::Texture>(L"Lobby_Logo");
		renderer->SetTexture(logo);*/
		#pragma endregion

		Scene::Initialize();
	}

	void LobbyScene::Update()
	{
		Scene::Update();

		/*bg[2]->GetComponent<Transform>()->SetPosition(
			Vector2(bg[2]->GetComponent<Transform>()->GetPostion().x + 7.5f * Time::DeltaTime(),
			bg[2]->GetComponent<Transform>()->GetPostion().y));

		bg[3]->GetComponent<Transform>()->SetPosition(
			Vector2(bg[3]->GetComponent<Transform>()->GetPostion().x + 7.5f * Time::DeltaTime(),
				bg[3]->GetComponent<Transform>()->GetPostion().y));*/
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