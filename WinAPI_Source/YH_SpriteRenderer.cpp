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
			if (m_Texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, m_Texture->GetWidth() * m_Size.x * scale.x
					, m_Texture->GetHeight() * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, 0, 0
					, m_Texture->GetWidth()
					, m_Texture->GetHeight()
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x, pos.y
					, m_Texture->GetWidth() * m_Size.x * scale.x
					, m_Texture->GetHeight() * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, 0, 0
					, m_Texture->GetWidth()
					, m_Texture->GetHeight()
					, RGB(255, 0, 255));
			}
		}
		else if (m_Texture->GetTextureType() == graphics::Texture::TextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};

			// ����ȭ ��ų �ȼ��� �� ����
			//imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));
			BLENDFUNCTION blend = {};
			blend.BlendOp = AC_SRC_OVER;
			blend.BlendFlags = 0;

			blend.SourceConstantAlpha = 255; // 0 ~ 255
			blend.AlphaFormat = AC_SRC_ALPHA; // 0

			AlphaBlend(hdc
				, pos.x, pos.y				
				, m_Texture->GetWidth() * m_Size.x * scale.x
				, m_Texture->GetHeight() * m_Size.y * scale.y
				, m_Texture->GetHdc()
				, 0, 0
				, m_Texture->GetWidth()
				, m_Texture->GetHeight()
				, blend);

			//Gdiplus::Graphics graphics(hdc);

			//graphics.TranslateTransform(pos.x, pos.y);
			//graphics.RotateTransform(rot);
			//graphics.TranslateTransform(-pos.x, -pos.y);

			//graphics.DrawImage(m_Texture->GetImage()
			//	, Gdiplus::Rect(
			//		pos.x, pos.y
			//		, m_Texture->GetWidth() * m_Size.x * scale.x
			//		, m_Texture->GetHeight() * m_Size.y * scale.y
			//	)
			//	, 0, 0
			//	, m_Texture->GetWidth()
			//	, m_Texture->GetHeight()
			//	, Gdiplus::UnitPixel
			//	, nullptr
			//);
		}
	}
}