#include "YH_SpriteRenderer.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"

namespace YH
{
	SpriteRenderer::SpriteRenderer() : m_Image(nullptr), m_Width(0), m_Height(0)
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
		Transform* transform = GetOwner()->GetComponent<Transform>();

		Vector2 pos = transform->GetPostion();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(m_Image, Gdiplus::Rect(pos.x, pos.y, m_Width, m_Height));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		m_Image = Gdiplus::Image::FromFile(path.c_str());

		//m_Width = m_Image->GetWidth();
		//m_Height = m_Image->GetHeight();
		m_Width = 1600;
		m_Height = 900;
	}
}