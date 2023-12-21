#include "YH_UIButton.h"
#include "YH_Input.h"

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
		SetPos(Vector2(200.0f, 200.0f));
		SetSize(Vector2(200.0f, 200.0f));

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
		}
		else
		{
			isMouseOn = false;
		}

		if (Input::GetKeyDown(KeyCode::LeftMouse))
		{
			if (isMouseOn)
			{
				m_OnClick();
			}
		}
	}

	void UIButton::OnLateUpdate()
	{

	}

	void UIButton::OnRender(HDC hdc)
	{
		Rectangle(hdc
			, (int)m_Position.x, (int)m_Position.y
			, m_Position.x + m_Size.x, m_Position.y + m_Size.y);
	}

	void UIButton::OnClear()
	{

	}

	void UIButton::ButtonClick()
	{
		int a = 0;
	}
}