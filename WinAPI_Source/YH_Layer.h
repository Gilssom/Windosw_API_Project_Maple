#pragma once
#include "YH_Entity.h"
#include "CommonInclude.h"
#include "YH_GameObject.h"

namespace YH
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObject(GameObject* eraseGameObj);

		const std::vector<GameObject*> GetGameObjects() { return m_GameObjects; }

	private:
		void FindDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void DeleteGameObjects(std::vector<GameObject*> gameObj);
		void EraseDeadGameObject();

	private:
		enums::LayerType m_Type;

		std::vector<GameObject*> m_GameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}

