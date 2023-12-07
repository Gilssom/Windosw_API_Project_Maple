#include "YH_BoxCollider2D.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"

namespace YH
{
	BoxCollider2D::BoxCollider2D() : Collider()
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC hdc)
	{
		// Collider �׸���
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, pos.x + offset.x + 100
			, pos.y + offset.y + 100);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}