#include "YH_BoxCollider2D.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Renderer.h"

namespace YH
{
	bool BoxCollider2D::isDraw = false;

	BoxCollider2D::BoxCollider2D() : Collider(ColliderShapeType::Rect2D)
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
		if (isDraw)
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();

			if (renderer::mainCamera)
				pos = renderer::mainCamera->CaluatePosition(pos);

			Vector2 offset = GetOffset();

			HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

			HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
			HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

			/*Rectangle(hdc
				, pos.x + offset.x
				, pos.y + offset.y
				, pos.x + offset.x + 100 * GetSize().x
				, pos.y + offset.y + 100 * GetSize().y);*/

			Rectangle(hdc
				, (pos.x + offset.x) - ((100 * GetSize().x) / 2.0f)
				, (pos.y + offset.y) - ((100 * GetSize().y) / 2.0f)
				, (pos.x + offset.x) + ((100 * GetSize().x) / 2.0f)
				, (pos.y + offset.y) + ((100 * GetSize().y) / 2.0f));

			SelectObject(hdc, oldBrush);
			SelectObject(hdc, oldPen);

			DeleteObject(greenPen);
		}	
	}
}