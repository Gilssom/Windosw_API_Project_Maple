#pragma once
#include "../WinAPI_Source/YH_SceneManager.h"
#include "YH_TitleScene.h"
#include "YH_LobbyScene.h"
#include "YH_PlayScene.h"

#pragma comment (lib, "x64/Debug/WinAPI_Engine.lib")

namespace YH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}