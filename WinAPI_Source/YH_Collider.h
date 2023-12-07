#pragma once
#include "YH_Component.h"

namespace YH
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		Vector2 GetOffset() { return m_Offset; }
		void SetOffset(Vector2 offset) { m_Offset = offset; }

	private:
		Vector2 m_Offset;
	};
}