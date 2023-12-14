#include "YH_TilemapRenderer.h"
#include "YH_GameObject.h"
#include "YH_Transform.h"
#include "YH_Renderer.h"

namespace YH
{
	TilemapRenderer::TilemapRenderer()
		: Component(enums::ComponentType::SpriteRenderer)
		, m_Texture(nullptr)
		, m_Size(Vector2::One)
		, m_Index(Vector2::Zero)
		, m_TileSize(16.0f, 16.0f)
	{

	}

	TilemapRenderer::~TilemapRenderer()
	{

	}

	void TilemapRenderer::Initialize()
	{

	}
	void TilemapRenderer::Update()
	{

	}
	void TilemapRenderer::LateUpdate()
	{

	}
	void TilemapRenderer::Render(HDC hdc)
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
					, pos.x, pos.y
					, m_TileSize.x * m_Size.x * scale.x
					, m_TileSize.y * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, m_Index.x * m_TileSize.x
					, m_Index.y * m_TileSize.y
					, m_TileSize.x
					, m_TileSize.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x, pos.y
					, m_TileSize.x * m_Size.x * scale.x
					, m_TileSize.y * m_Size.y * scale.y
					, m_Texture->GetHdc()
					, m_Index.x * m_TileSize.x
					, m_Index.y * m_TileSize.y
					, m_TileSize.x
					, m_TileSize.y
					, RGB(255, 0, 255));
			}
		}
		// 타일맵은 PNG 로 안된다.
	}
}