#pragma once
#include "../WinAPI_Source/YH_SceneManager.h"
#include "YH_TitleScene.h"
#include "YH_LobbyScene.h"
#include "YH_PlayScene.h"
#include "YH_BossCygnusScene.h"

namespace YH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<BossCygnusScene>(L"BossCygnusScene");

		//SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"LobbyScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}