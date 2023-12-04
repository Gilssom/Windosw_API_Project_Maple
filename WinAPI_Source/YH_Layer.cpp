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

			GameObject::State state = gameObj->GetActive();
			if (state == GameObject::State::Paused || state == GameObject::State::Dead)
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

			GameObject::State state = gameObj->GetActive();
			if (state == GameObject::State::Paused || state == GameObject::State::Dead)
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

			GameObject::State state = gameObj->GetActive();
			if (state == GameObject::State::Paused || state == GameObject::State::Dead)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjectIter iter = m_GameObjects.begin();
			iter != m_GameObjects.end();)
		{
			GameObject::State active = (*iter)->GetActive();

			if (active == GameObject::State::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = m_GameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (!gameObject)
			return;

		m_GameObjects.push_back(gameObject);
	}
}