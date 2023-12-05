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

		/*if (type == 1)
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Ellipse(hdc, m_X, m_Y, 50 + m_X, 50 + m_Y);

			SelectObject(hdc, oldbrush);

			DeleteObject(brush);
		}*/
	}

	void GameObject::MonsterRender(HDC hdc)
	{
		/*HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, 100 + m_X, 100 + m_Y, 200 + m_X, 200 + m_Y);

		SelectObject(hdc, oldbrush);

		DeleteObject(brush);*/
	}

	void GameObject::MonsterMoving()
	{
		/*int nx = rand() % 3;
		int ny = rand() % 3;

		if (nx == ny)
			return;

		if (m_X + dir[nx] < -100 || m_X + dir[nx] > 1500 || m_Y + dir[ny] < -100 || m_Y + dir[ny] > 800)
			return;

		m_X += dir[nx];
		m_Y += dir[ny];*/
	}
	void GameObject::InitTransform()
	{
		AddComponent<Transform>();
	}
}
