#include "YH_UIHUD.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"

namespace YH
{
	UIHUD::UIHUD()
		: UIBase(UIType::HpBar)
	{

	}

	UIHUD::~UIHUD()
	{

	}

	void UIHUD::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"StatusBar");
	}

	void UIHUD::OnActive()
	{

	}

	void UIHUD::OnInActive()
	{

	}

	void UIHUD::OnUpdate()
	{

	}

	void UIHUD::OnLateUpdate()
	{

	}

	void UIHUD::OnRender(HDC hdc)
	{
		/*TransparentBlt(hdc
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth() / 2.0f
			, m_Texture->GetHeight()
			, RGB(255, 0, 255));*/

		Rectangle(hdc
			, 2768.0f, 760.0f,
			2868.0f, 860.0f);

		Vector2 pos = Vector2(2768.0f, 760.0f);
		pos = renderer::mainCamera->CaluatePosition(pos);

		Gdiplus::ImageAttributes imgAtt = {};

		// 투명화 시킬 픽셀의 색 범위
		//imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

		Gdiplus::Graphics graphics(hdc);

		graphics.TranslateTransform(pos.x, pos.y);
		graphics.TranslateTransform(-pos.x, -pos.y);

		graphics.DrawImage(m_Texture->GetImage()
			, Gdiplus::Rect(
				pos.x, pos.y
				, m_Texture->GetWidth()
				, m_Texture->GetHeight()
			)
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, Gdiplus::UnitPixel
			, nullptr
		);
	}

	void UIHUD::OnClear()
	{

	}
}