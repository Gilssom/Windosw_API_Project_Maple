#include "YH_CircleCollider2D.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Renderer.h"

namespace YH
{
	CircleCollider2D::CircleCollider2D() : Collider(ColliderShapeType::Circle2D)
	{

	}

	CircleCollider2D::~CircleCollider2D()
	{

	}

	void CircleCollider2D::Initialize()
	{

	}

	void CircleCollider2D::Update()
	{

	}

	void CircleCollider2D::LateUpdate()
	{

	}

	void CircleCollider2D::Render(HDC hdc)
	{
		// Collider �׸���
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();

		// ī�޶� ��ġ�� �����ͼ� �����ֱ�
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBotton;
		rightBotton.x = pos.x + offset.x + 100 * GetSize().x;
		rightBotton.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, rightBotton.x
			, rightBotton.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}