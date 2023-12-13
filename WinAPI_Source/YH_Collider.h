#pragma once
#include "YH_Component.h"
#include "YH_Transform.h"

namespace YH
{
	class Collider : public Component
	{
	public:
		Collider(ColliderShapeType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() { return m_Offset; }
		void SetOffset(Vector2 offset) { m_Offset = offset; }
		UINT32 GetID() { return m_ID; }
		Vector2 GetSize() { return m_Size; }
		void SetSize(Vector2 size) { m_Size = size; }
		ColliderType GetCollType() { return m_CollType; }
		void SetCollType(ColliderType type) { m_CollType = type; }
		ColliderShapeType GetCollShapeType() { return m_CollShapeType; }

		//Vector2 GetPos() { return GetOwner()->GetComponent<Transform>()->GetPostion(); }

	private:
		static UINT CollisionID;

		ColliderType m_CollType;
		ColliderShapeType m_CollShapeType;
		UINT32 m_ID;
		Vector2 m_Offset;
		Vector2 m_Size;
	};
}