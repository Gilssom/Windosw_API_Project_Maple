#pragma once
#include "CommonInclude.h"
#include "YH_Component.h"
#include "YH_Input.h"
#include "YH_Collider.h"
//#include "YH_Object.h"

namespace YH::object
{
	void Destroy(GameObject* gameObject);
}

namespace YH
{
	enum class Lookfor
	{
		Left, Right, Up, Down, None,
	};

	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* obj);

		enum class State
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

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

		//State GetActive() { return m_State; }
		State GetState() { return m_State; }

		void SetActive(bool power)
		{
			if (power) m_State = State::Active;
			if (!power) m_State = State::Paused;
		}

		bool IsActive() { return m_State == State::Active; }
		bool IsDead() { return m_State == State::Dead; }

		// 미사일 발사
		bool isAttack() { return Input::GetKeyDown(KeyCode::Space); }

		Lookfor m_LookState;

	private:
		void InitTransform();
		void Death() { m_State = State::Dead; }

	private:
		State m_State;

		std::vector<Component*> m_Components;

		// 몬스터 움직임 좌표 및 속도
		float dir[3] = { -0.5f, 0, 0.5f };
	};
}