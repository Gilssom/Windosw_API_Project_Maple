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
			scene->Initialize();

			m_Scene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter = m_Scene.find(name);

			if (iter == m_Scene.end())
				return nullptr;

			m_ActiveScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static Scene* GetScene() { return m_ActiveScene; }

	private:
		//static std::vector<Scene*> m_Scene;
		// 트리구조 map
		static std::map<std::wstring, Scene*> m_Scene;
		static Scene* m_ActiveScene;
	};
}