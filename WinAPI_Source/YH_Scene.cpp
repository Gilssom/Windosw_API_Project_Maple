#include "YH_Scene.h"

namespace YH
{
	Scene::Scene() : m_GameObjects { }
	{

	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		/*for (size_t i = 0; i < m_GameObjects.size(); i++)
		{
			m_GameObjects[i]->Update(0);
		}*/

		// 범위 기반 for 문
		for (GameObject* gameObj : m_GameObjects)
		{
			gameObj->Update(0);
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			gameObj->Render(hdc, 0);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		m_GameObjects.push_back(gameObject);
	}

	GameObject* Scene::GetGameObject()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			return gameObj;
		}
	}
}