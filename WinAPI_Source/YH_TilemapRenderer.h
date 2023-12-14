#pragma once
#include "YH_Entity.h"
#include "YH_Component.h"
#include "YH_Texture.h"

namespace YH
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { m_Texture = texture; }
		void SetSize(math::Vector2 size) { m_Size = size; }

	private:
		Vector2 m_TileSize;

		graphics::Texture* m_Texture;
		Vector2 m_Size;
		Vector2 m_Index;
	};
}