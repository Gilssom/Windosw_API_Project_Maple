#pragma once
#include "YH_Entity.h"
#include "YH_GameObject.h"
#include "YH_Layer.h"

namespace YH
{
	class AudioSource;
	class AudioClip;

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::LayerType layerType);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(enums::LayerType layerType) { return m_Layers[(UINT)layerType]; };

		void SetAudioSource(AudioSource* as) { m_AudioSource = as; }
		AudioSource* GetAudioSource() { return m_AudioSource; }
		void SetAudioClip(AudioClip* as) { m_BgSound = as; }
		AudioClip* GetAudioClip() { return m_BgSound; }
		void SetSceneNumber(int sceneNumber) { m_SceneNumber = sceneNumber; }
		int GetSceneNumber() { return m_SceneNumber; }

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> m_Layers;
		int m_SceneNumber;

		AudioSource* m_AudioSource;
		AudioClip* m_BgSound;
 	};
}

