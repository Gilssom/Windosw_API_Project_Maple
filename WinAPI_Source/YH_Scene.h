#pragma once
#include "YH_Entity.h"
#include "YH_GameObject.h"
#include "YH_Layer.h"

namespace YH
{
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
		Layer* GetLayer(enums::LayerType layerType) { return m_Layers[(UINT)layerType]; };

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> m_Layers;
 	};
}

