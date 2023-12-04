#pragma once
#include "CommonInclude.h"
#include "YH_Component.h"
#include "YH_Input.h"
//#include "YH_Object.h"

namespace YH
{
	enum class Lookfor
	{
		Left, Right, Up, Down, None,
	};

	class GameObject
	{
	public:
		/*friend void object::Destroy(GameObject* obj);*/

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
				// �θ� �ڽİ��� ����ȯ
				target = dynamic_cast<T*>(comp);

				if (target)
					break;
			}

			return target;
		}

		State GetActive() { return m_State; }

		void SetActive(bool power)
		{
			if (power) m_State = State::Active;
			if (!power) m_State = State::Paused;
		}

		void Death() { m_State = State::Dead; }

		void MonsterRender(HDC hdc);
		void MonsterMoving();

		// �̻��� �߻�
		bool isAttack() { return Input::GetKeyDown(KeyCode::Space); }

		Lookfor m_LookState;

	private:
		void InitTransform();

	private:
		State m_State;

		std::vector<Component*> m_Components;

		// ���� ������ ��ǥ �� �ӵ�
		float dir[3] = { -0.5f, 0, 0.5f };
	};
}