#pragma once
#include "YH_Entity.h"
#include "YH_GameObject.h"

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

		void AddGameObject(GameObject* gameObject);
		GameObject* GetGameObject();

	private:
		std::vector<GameObject*> m_GameObjects;
 	};
}

