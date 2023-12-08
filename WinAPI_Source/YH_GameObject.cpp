#include "YH_GameObject.h"
#include "YH_Input.h"
#include "YH_Time.h"
#include "YH_Application.h"
#include "YH_Transform.h"

namespace YH::object
{
	void Destroy(GameObject* gameObject)
	{
		if (gameObject)
			gameObject->Death();
	}
}

namespace YH
{
	GameObject::GameObject() : m_LookState(Lookfor::None), m_State(State::Active)
	{
		m_Components.resize((UINT)enums::ComponentType::End);
		InitTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : m_Components)
		{
			if (!comp)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : m_Components)
		{
			if (!comp)
				continue;

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : m_Components)
		{
			if (!comp)
				continue;

			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : m_Components)
		{
			if (!comp)
				continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : m_Components)
		{
			if (!comp)
				continue;

			comp->Render(hdc);
		}
	}

	void GameObject::OnCollisionEnter(Collider* other)
	{

	}

	void GameObject::OnCollisionStay(Collider* other)
	{

	}

	void GameObject::OnCollisionExit(Collider* other)
	{

	}

	void GameObject::InitTransform()
	{
		AddComponent<Transform>();
	}
}
