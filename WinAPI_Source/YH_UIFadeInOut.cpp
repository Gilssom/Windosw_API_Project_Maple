#include "YH_UIFadeInOut.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"
#include "YH_Time.h"

namespace YH
{
	bool UIFadeInOut::isComplete = false;
	bool UIFadeInOut::isNeedPop = false;

	UIFadeInOut::UIFadeInOut()
		: UIBase(UIType::FadeInOut)
		, m_Alpha(0.0f)
	{

	}

	UIFadeInOut::~UIFadeInOut()
	{

	}

	void UIFadeInOut::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"FadeInOut");
	}

	void UIFadeInOut::OnActive()
	{
		isNeedPop = false;
		m_Alpha = 0.0f;
	}

	void UIFadeInOut::OnInActive()
	{

	}

	void UIFadeInOut::OnUpdate()
	{

	}

	void UIFadeInOut::OnLateUpdate()
	{

	}

	void UIFadeInOut::OnRender(HDC hdc)
	{
		Vector2 pos = Vector2::Zero;

		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		AlphaCheck();

		blend.SourceConstantAlpha = m_Alpha; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, pos.x
			, pos.y
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, blend);
	}

	void UIFadeInOut::OnClear()
	{

	}

	void UIFadeInOut::AlphaCheck()
	{
		if (m_Alpha <= 255 && !isComplete)
		{
			m_Alpha += Time::DeltaTime() * 200.0f;

			if (m_Alpha > 255)
				isComplete = true;
		}
		else if (isComplete && m_Alpha >= 0)
		{
			m_Alpha -= Time::DeltaTime() * 200.0f;

			if (m_Alpha < 0)
			{
				isComplete = false;
				isNeedPop = true;
			}
		}
	}
}