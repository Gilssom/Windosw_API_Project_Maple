#pragma once
#include "YH_Entity.h"
#include "YH_Component.h"

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

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* m_Image;
		UINT m_Width;
		UINT m_Height;
	};
}

