#include "..\\WinAPI_Source\\YH_Application.h"
#include "YH_TitleScene.h"
#include "YH_GameObject.h"
#include "YH_Player.h"
#include "YH_Transform.h"
#include "YH_SpriteRenderer.h"
#include "YH_Object.h"
#include "YH_Texture.h"
#include "YH_Resources.h"

#include "YH_Animator.h"

#include "YH_AudioClip.h"
#include "YH_AudioListener.h"
#include "YH_AudioSource.h"

extern YH::Application App;

namespace YH
{
	TitleScene::TitleScene()
	{

	}
	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		bg = object::Instantiate<Player>(enums::LayerType::BackGround, Vector2(535.0f, 350.0f));

		graphics::Texture* bg_1 = Resources::Find<graphics::Texture>(L"Title");

		Animator* title = bg->AddComponent<Animator>();
		title->CreateAnimation(L"Title Movie", bg_1, Vector2(0.0f, 0.0f), Vector2(456.0f, 285.0f),
			Vector2::Zero, 48, 0.1f);
		title->PlayAnimation(L"Title Movie", false);

		SetAudioSource(bg->AddComponent<AudioSource>());
		SetAudioClip(Resources::Load<AudioClip>(L"Logo", L"..\\\Resources\\SoundResource\\LogoBgm.mp3"));
		GetAudioClip()->SetLoop(false);

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (bg->GetComponent<Animator>()->IsComplete())
		{
			SceneManager::LoadScene(L"LobbyScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void TitleScene::OnEnter()
	{
		HWND hwnd = App.GetHwnd();
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 1037, 803, SWP_SHOWWINDOW);

		GetAudioSource()->SetClip(GetAudioClip());
		GetAudioSource()->Play();

		Scene::OnEnter();
	}

	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}