#include "YH_SpriteRenderer.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"

namespace YH
{
	SpriteRenderer::SpriteRenderer()
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(125, 255, 255));

		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

		Transform* transform = GetOwner()->GetComponent<Transform>();

		Rectangle(hdc, transform->GetX(), transform->GetY() , 100 + transform->GetX(), 100 + transform->GetY());

		SelectObject(hdc, oldbrush);

		DeleteObject(brush);
	}
}