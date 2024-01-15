#include "..\\WinAPI_Source\\YH_Application.h"
#include "YH_LobbyScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Time.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

#include "YH_Animator.h"

#include "YH_AudioClip.h"
#include "YH_AudioListener.h"
#include "YH_AudioSource.h"

#include "YH_UIManager.h"

extern YH::Application App;

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
		bg[0] = object::Instantiate<GameObject>(enums::LayerType::BackGround, Vector2(510.0f, 380.0f));

		graphics::Texture* bg_0 = Resources::Find<graphics::Texture>(L"WorldSelect");

		Animator* worldSelect = bg[0]->AddComponent<Animator>();
		worldSelect->CreateAnimation(L"World Select Movie", bg_0, Vector2(0.0f, 0.0f), Vector2(1024.0f, 768.0f),
			Vector2::Zero, 16, 0.125f);

		//bg[0]->GetComponent<Transform>()->SetScale(Vector2(1.57f, 1.18f));

		worldSelect->PlayAnimation(L"World Select Movie");

		SetAudioSource(bg[0]->AddComponent<AudioSource>());
		SetAudioClip(Resources::Load<AudioClip>(L"Lobby", L"..\\\Resources\\SoundResource\\TitleBgm.mp3"));
		GetAudioClip()->SetLoop(true);
		
		#pragma endregion

		Scene::Initialize();
	}

	void LobbyScene::Update()
	{
		Scene::Update();
	}

	void LobbyScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void LobbyScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Lobby Scene";

		TextOut(hdc, 0, 0, str, 11);
	}

	void LobbyScene::OnEnter()
	{
		GetAudioSource()->SetClip(GetAudioClip());
		GetAudioSource()->Play();

		UIManager::Push(UIType::Button);

		Scene::OnEnter();
	}

	void LobbyScene::OnExit()
	{
		GetAudioSource()->Stop();

		HWND hwnd = App.GetHwnd();
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 1381, 808, SWP_SHOWWINDOW);

		UIManager::Pop(UIType::Button);

		Scene::OnExit();
	}

	void LobbyScene::WorldSelect()
	{

	}
}