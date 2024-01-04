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

		static Texture* Create(const std::wstring& name, UINT width, UINT height);

		Texture();
		~Texture();

		// �θ� ���� ���� �Լ��� ������ ������ �����;� ��
		virtual bool Load(const std::wstring& path) override;

		UINT GetWidth() { return m_Width; }
		void SetWidth(UINT width) { m_Width = width; }
		UINT GetHeight() { return m_Height; }
		void SetHeight(UINT height) { m_Height = height; }
		HDC GetHdc() { return m_Hdc; }
		TextureType GetTextureType() { return m_Type; }
		Gdiplus::Image* GetImage() { return m_Image; }
		bool IsAlpha(){ return mbAlpha; }

	private:             
		bool mbAlpha;
		TextureType m_Type;
		Gdiplus::Image* m_Image;
		HBITMAP m_Bitmap;
		HDC m_Hdc;

		UINT m_Width;
		UINT m_Height;
	};
}

