#include "YH_Layer.h"

namespace YH
{
	Layer::Layer() : m_Type(enums::LayerType::None), m_GameObjects{}
	{

	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
				continue;

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
				continue;

			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		std::vector<GameObject*> deleteObjects = {};
		FindDeadGameObjects(deleteObjects);
		EraseGameObject();
		DeleteGameObjects(deleteObjects);
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (!gameObject)
			return;

		m_GameObjects.push_back(gameObject);
	}

	void Layer::FindDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			GameObject::State active = gameObj->GetState();

			if (active == GameObject::State::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void Layer::DeleteGameObjects(std::vector<GameObject*> deleteObjs)
	{
		for (GameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::EraseGameObject()
	{
		std::erase_if(m_GameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}