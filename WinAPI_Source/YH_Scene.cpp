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
		// ���� ��� for ��
		for (GameObject* gameObj : m_GameObjects)
		{
			gameObj->Update();
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
			gameObj->Render(hdc);
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