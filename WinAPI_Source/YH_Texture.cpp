#include "YH_Texture.h"
#include "YH_Application.h"
#include "YH_Resources.h"

// �ش� ���������� �������� �˸��� Ű����
extern YH::Application App; 

namespace YH::graphics
{
	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<graphics::Texture>(name);

		if (image)
			return image;

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = App.GetHdc();
		HWND hwnd = App.GetHwnd();

		image->m_Bitmap = CreateCompatibleBitmap(hdc, width, height);
		image->m_Hdc = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->m_Hdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->m_Hdc, image->m_Bitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name + L" Image", image);

		return image;
	}

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

			BITMAP info = {};
			GetObject(m_Bitmap, sizeof(BITMAP), &info);

			m_Width = info.bmWidth;
			m_Height = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;

			HDC mainDC = App.GetHdc();
			m_Hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			m_Type = TextureType::Png;

			ULONG_PTR gdiplusToken = 0;
			GdiplusStartupInput gidstartupInput = {};
			GdiplusStartup(&gdiplusToken, &gidstartupInput, nullptr);
			Image* pImg = Image::FromFile(path.c_str(), false);

			Bitmap* pBitmap = (Bitmap*)pImg->Clone();
			Status stat = pBitmap->GetHBITMAP(Color(0, 0, 0, 0), &m_Bitmap);

			BITMAP info = {};
			GetObject(m_Bitmap, sizeof(BITMAP), &info);

			m_Width = info.bmWidth;
			m_Height = info.bmHeight;

			HDC mainDC = App.GetHdc();
			m_Hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_Hdc, m_Bitmap);
			DeleteObject(oldBitmap);
		}

		return true;
	}
}