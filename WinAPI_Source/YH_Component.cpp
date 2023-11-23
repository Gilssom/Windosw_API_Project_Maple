#include "YH_Component.h"

namespace YH
{
	Component::Component(enums::ComponentType type) : m_Owner(nullptr), m_Type(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}