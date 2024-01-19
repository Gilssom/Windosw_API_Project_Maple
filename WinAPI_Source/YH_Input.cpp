#include "YH_Input.h"
#include "YH_Application.h"

extern YH::Application App;

namespace YH
{
	std::vector<Input::Key> Input::m_Keys = {};
	math::Vector2 Input::m_MousePosition = math::Vector2::One;

	int ASCII[(UINT)KeyCode::End]
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
		VK_LCONTROL, VK_LMENU,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
		VK_DELETE,
	};

	void Input::Initailize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		for (size_t i = 0; i < (UINT)KeyCode::End; i++)
		{
			Key key = { };
			key.pressed = false;
			key.state = KeyState::None;
			key.keyCode = (KeyCode)i;

			m_Keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		std::for_each(m_Keys.begin(), m_Keys.end(),
			[](Key& p_key) -> void
			{
				UpdateKey(p_key);
			});
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (IsKeyDown(key.keyCode))
				UpdateKeyDown(key);
			else
				UpdateKeyUp(key);

			GetMousePositionByWindow();
		}
		else
		{
			ClearKeys();
		}
		
	}

	bool Input::IsKeyDown(KeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.pressed)
			key.state = KeyState::Pressed;
		else
			key.state = KeyState::Down;

		key.pressed = true;
	}

	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.pressed)
			key.state = KeyState::Up;
		else
			key.state = KeyState::None;

		key.pressed = false;
	}

	void Input::GetMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(App.GetHwnd(), &mousePos);

		m_MousePosition.x = mousePos.x;
		m_MousePosition.y = mousePos.y;
	}

	void Input::ClearKeys()
	{
		for (Key& key : m_Keys)
		{
			if (key.state == KeyState::Down || key.state == KeyState::Pressed)
				key.state = KeyState::Up;
			else if (key.state == KeyState::Up)
				key.state = KeyState::None;

			key.pressed = false;
		}
	}
}
