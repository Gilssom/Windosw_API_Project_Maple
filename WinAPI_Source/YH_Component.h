#pragma once
#include "YH_Entity.h"

namespace YH
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { m_Owner = owner; }
		GameObject* GetOwner() { return m_Owner; }

	private:
		// 전방 선언
		GameObject* m_Owner;
	};
}

