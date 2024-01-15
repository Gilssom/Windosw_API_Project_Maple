#include "YH_UIButton.h"
#include "YH_Input.h"
#include "YH_Resources.h"
#include "YH_Renderer.h"
#include "YH_SceneManager.h"

namespace YH
{
	UIButton::UIButton()
		: UIBase(UIType::Button)
	{

	}

	UIButton::~UIButton()
	{

	}

	void UIButton::OnInit()
	{
		m_Texture = Resources::Find<graphics::Texture>(L"WorldButton");

		SetPos(Vector2(910.0f, 82.0f));
		SetSize(Vector2(m_Texture->GetWidth(), m_Texture->GetHeight()));

		m_OnClick = std::bind(&UIButton::ButtonClick, this);
	}

	void UIButton::OnActive()
	{

	}

	void UIButton::OnInActive()
	{

	}

	void UIButton::OnUpdate()
	{
		Vector2 mousePos = Input::GetMousePosition();

		if (m_Position.x <= mousePos.x && mousePos.x <= m_Position.x + m_Size.x
			&& m_Position.y <= mousePos.y && mousePos.y <= m_Position.y + m_Size.y)
		{
			isMouseOn = true;
			m_Texture = Resources::Find<graphics::Texture>(L"WorldButtonOver");
		}
		else
		{
			isMouseOn = false;
			m_Texture = Resources::Find<graphics::Texture>(L"WorldButton");
		}

		if (Input::GetKey(KeyCode::LeftMouse))
		{
			if (isMouseOn)
			{
				m_Texture = Resources::Find<graphics::Texture>(L"WorldButtonPress");
			}
		}

		if(Input::GetKeyUp(KeyCode::LeftMouse))
			m_OnClick();
	}

	void UIButton::OnLateUpdate()
	{

	}

	void UIButton::OnRender(HDC hdc)
	{
		Gdiplus::ImageAttributes imgAtt = {};

		BLENDFUNCTION blend = {};
		blend.BlendOp = AC_SRC_OVER;
		blend.BlendFlags = 0;

		blend.SourceConstantAlpha = 255; // 0 ~ 255
		blend.AlphaFormat = AC_SRC_ALPHA; // 0

		AlphaBlend(hdc
			, m_Position.x
			, m_Position.y
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, m_Texture->GetHdc()
			, 0, 0
			, m_Texture->GetWidth()
			, m_Texture->GetHeight()
			, blend);
	}

	void UIButton::OnClear()
	{

	}

	void UIButton::ButtonClick()
	{
		SceneManager::LoadScene(L"PlayScene");
	}
}