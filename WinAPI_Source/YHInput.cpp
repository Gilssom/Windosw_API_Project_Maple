#include "YHInput.h"

namespace YH
{
	std::vector<Input::Key> Input::m_Keys = { };

	int ASCII[(UINT)KeyCode::End]
	{ 
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
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
		if (IsKeyDown(key.keyCode))
			UpdateKeyDown(key);
		else
			UpdateKeyUp(key);
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
}
