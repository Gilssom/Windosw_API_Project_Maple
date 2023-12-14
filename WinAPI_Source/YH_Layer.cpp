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
		EraseDeadGameObject();
		DeleteGameObjects(deleteObjects);
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (!gameObject)
			return;

		m_GameObjects.push_back(gameObject);
	}

	void Layer::EraseGameObject(GameObject* eraseGameObj)
	{
		// std::erase() iter 를 넣어줘서 해당 iter 과 같은 객체를 삭제해준다.
		// 람다식 에서는 원래 외부 변수를 받아서 사용할 수 없다.
		// 하지만 캡처 기능을 사용하여 받을 수 있다.
		// [=] : 값 복사 , [&] : 값 참조

		std::erase_if(m_GameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
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

	void Layer::EraseDeadGameObject()
	{
		std::erase_if(m_GameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}