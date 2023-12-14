#include "YH_SceneManager.h"
#include "YH_DontDestroyOnLoad.h"

namespace YH
{
	std::map<std::wstring, Scene*> SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;
	Scene* SceneManager::m_DontDestroyOnLoad = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (m_ActiveScene)
			m_ActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = m_Scene.find(name);

		if (iter == m_Scene.end())
			return nullptr;

		m_ActiveScene = iter->second;

		m_ActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
		m_DontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneManager::Update()
	{
		m_ActiveScene->Update();
		m_DontDestroyOnLoad->Update();
	}

	void SceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
		m_DontDestroyOnLoad->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		m_ActiveScene->Render(hdc);
		m_DontDestroyOnLoad->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		m_ActiveScene->Destroy();
		m_DontDestroyOnLoad->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : m_Scene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}