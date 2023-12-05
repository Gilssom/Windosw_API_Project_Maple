#pragma once
#include "YH_Component.h"
#include "YH_GameObject.h"
#include "YH_Layer.h"
#include "YH_Scene.h"
#include "YH_SceneManager.h"
#include "YH_Transform.h"

namespace YH::object
{
	template <typename T>
	static T* Instantiate(YH::enums::LayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(YH::enums::LayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* transform = gameObject->GetComponent<Transform>();
		transform->SetPosition(position);

		return gameObject;
	}

	/*static void Destroy(GameObject* gameObject)
	{
		if (!gameObject)
			return;

		gameObject->Death();
	}*/
}