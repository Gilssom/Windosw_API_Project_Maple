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

	private:
		enums::LayerType m_Type;

		std::vector<GameObject*> m_GameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}

