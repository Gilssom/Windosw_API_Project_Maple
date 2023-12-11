#include "YH_Collider.h"
#include "YH_GameObject.h"
#include "YH_Script.h"

namespace YH
{
	UINT Collider::CollisionID = 1;

	Collider::Collider() 
		: Component(enums::ComponentType::Collider)
		, m_ID(CollisionID++)
		, m_Size(Vector2::One)
		, m_CollType(enums::ColliderType::None)
	{

	}

	Collider::~Collider()
	{

	}

	void Collider::Initialize()
	{

	}

	void Collider::Update()
	{

	}

	void Collider::LateUpdate()
	{

	}

	void Collider::Render(HDC hdc)
	{

	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* scr = GetOwner()->GetComponent<Script>();
		scr->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* scr = GetOwner()->GetComponent<Script>();
		scr->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* scr = GetOwner()->GetComponent<Script>();
		scr->OnCollisionExit(other);
	}
}