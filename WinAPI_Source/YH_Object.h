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
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(YH::enums::LayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* transform = gameObject->GetComponent<Transform>();
		transform->SetPosition(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetScene();
		// 현재 씬에서 게임오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObject);

		// 해당 게임 오브젝트 -> DontDestroyScene 으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}