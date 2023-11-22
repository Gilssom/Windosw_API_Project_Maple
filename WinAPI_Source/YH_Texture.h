#pragma once
#include "YH_Resource.h"

namespace YH::graphics
{
	class Texture : public Resource
	{
	public:
		enum class TextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();

		// �θ� ���� ���� �Լ��� ������ ������ �����;� ��
		virtual bool Load(const std::wstring& path) override;

		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }
		HDC GetHdc() { return m_Hdc; }
		TextureType GetTextureType() { return m_Type; }
		Gdiplus::Image* GetImage() { return m_Image; }

	private:
		TextureType m_Type;
		Gdiplus::Image* m_Image;
		HBITMAP m_Bitmap;
		HDC m_Hdc;

		UINT m_Width;
		UINT m_Height;
	};
}

