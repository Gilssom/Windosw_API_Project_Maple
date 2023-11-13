#pragma once
#include "../WinAPI_Source/YH_SceneManager.h"
#include "YH_PlayScene.h"

#pragma comment (lib, "x64/Debug/WinAPI_Engine.lib")

namespace YH
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"PlayScene");
		//SceneManager::CreateScene<TitleScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}