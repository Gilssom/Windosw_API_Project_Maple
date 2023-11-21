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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> m_Scene;
		// 트리구조 map
		static std::map<std::wstring, Scene*> m_Scene;
		static Scene* m_ActiveScene;
	};
}