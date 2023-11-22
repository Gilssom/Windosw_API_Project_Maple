#pragma once
#include "YH_Entity.h"
#include "YH_Component.h"
#include "YH_Texture.h"

namespace YH
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { m_Texture = texture; }
		void SetSize(math::Vector2 size) { m_Size = size; }

	private:
		graphics::Texture* m_Texture;
		math::Vector2 m_Size;
	};
}

