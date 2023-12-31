#pragma once
#include "YH_Scene.h"

namespace YH
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			m_ActiveScene = scene;
			scene->Initialize();

			m_Scene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetScene() { return m_ActiveScene; }
		static Scene* GetDontDestroyOnLoad() { return m_DontDestroyOnLoad; }
		static std::vector<GameObject*> GetGameObjects(LayerType layer);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

	private:
		// Ʈ������ map
		static std::map<std::wstring, Scene*> m_Scene;
		static Scene* m_ActiveScene;
		static Scene* m_DontDestroyOnLoad;
	};
}