#pragma once
#include "CommonInclude.h"
#include "YH_Component.h"
#include "YH_Input.h"

namespace YH
{
	enum class Lookfor
	{
		Left, Right, Up, Down, None,
	};

	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();

			comp->Initialize();
			comp->SetOwner(this);

			m_Components[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* target = nullptr;
			
			for (Component* comp : m_Components)
			{
				// 부모 자식간의 형변환
				target = dynamic_cast<T*>(comp);

				if (target)
					break;
			}

			return target;
		}

		void MonsterRender(HDC hdc);
		void MonsterMoving();

		// 미사일 발사
		bool isAttack() { return Input::GetKeyDown(KeyCode::Space); }

		Lookfor m_LookState;

	private:
		void InitTransform();

	private:
		std::vector<Component*> m_Components;

		// 몬스터 움직임 좌표 및 속도
		float dir[3] = { -0.5f, 0, 0.5f };
	};
}