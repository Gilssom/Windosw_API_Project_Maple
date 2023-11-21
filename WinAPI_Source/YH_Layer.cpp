#include "YH_Layer.h"

namespace YH
{
	Layer::Layer() : m_GameObjects { }
	{

	}
	Layer::~Layer()
	{

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

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (!gameObj)
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

			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (!gameObject)
			return;

		m_GameObjects.push_back(gameObject);
	}
}