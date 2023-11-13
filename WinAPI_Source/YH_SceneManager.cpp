#include "YH_SceneManager.h"

namespace YH
{
	std::map<std::wstring, Scene*> SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;

	void SceneManager::Initialize()
	{

	}

	void SceneManager::Update()
	{
		m_ActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		m_ActiveScene->Render(hdc);
	}
}