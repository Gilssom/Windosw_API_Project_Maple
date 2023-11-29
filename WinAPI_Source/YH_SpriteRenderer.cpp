#include "YH_SpriteRenderer.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"
#include "YH_Renderer.h"

namespace YH
{
	SpriteRenderer::SpriteRenderer() 
		: Component(enums::ComponentType::SpriteRenderer)
		, m_Texture(nullptr)
		, m_Size(Vector2::One)
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
		if (!m_Texture) // Texture Setting !!
			assert(false);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();
		float rot = transform->GetRotation();
		Vector2 scale = transform->GetScale();

		pos = renderer::mainCamera->CaluatePosition(pos);

		if (m_Texture->GetTextureType() == graphics::Texture::TextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, m_Texture->GetWidth() * m_Size.x, m_Texture->GetHeight() * m_Size.y, 
				m_Texture->GetHdc(), 0, 0, m_Texture->GetWidth(), 
				m_Texture->GetHeight(), RGB(255, 0, 255));
		}
		else if (m_Texture->GetTextureType() == graphics::Texture::TextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);

			//graphics.TranslateTransform(pos.x, pos.y);
			//graphics.RotateTransform(rot);
			//graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(m_Texture->GetImage(), Gdiplus::Rect
				(
					pos.x, pos.y, m_Texture->GetWidth() * m_Size.x, m_Texture->GetHeight() * m_Size.y
				));
		}
	}
}