#include "YH_Texture.h"
#include "YH_Application.h"

// 해당 전역변수가 존재함을 알리는 키워드
extern YH::Application App; 

namespace YH::graphics
{
	Texture::Texture() : Resource(enums::ResourceType::Texture)
	{

	}

	Texture::~Texture()
	{

	}

	bool Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")
		{
			m_Type = TextureType::Bmp;
			m_Bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (!m_Bitmap)
				return false;

			BITMAP info = { };
			GetObject(m_Bitmap, sizeof(BITMAP), &info);

			m_Width = info.bmWidth;
			m_Height = info.bmHeight;

			HDC mainDC = App.GetHdc();
			m_Hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			m_Type = TextureType::Png;
			m_Image = Gdiplus::Image::FromFile(path.c_str());

			if (!m_Image)
				return false;

			m_Width = m_Image->GetWidth();
			m_Height = m_Image->GetHeight();
		}

		return true;
	}
}