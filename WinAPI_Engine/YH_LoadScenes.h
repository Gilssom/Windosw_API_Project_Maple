#pragma once
#include "../WinAPI_Source/YH_SceneManager.h"
#include "YH_TitleScene.h"
#include "YH_LobbyScene.h"
#include "YH_PlayScene.h"
#include "YH_FlowerScene.h"
#include "YH_BossReadyScene.h"
#include "YH_BossCygnusScene.h"
#include "YH_ToolScene.h"

namespace YH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<FlowerScene>(L"FlowerScene");
		SceneManager::CreateScene<BossReadyScene>(L"BossReadyArena");
		SceneManager::CreateScene<BossCygnusScene>(L"BossCygnusScene");

		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		//SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"LobbyScene");
		//SceneManager::LoadScene(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}