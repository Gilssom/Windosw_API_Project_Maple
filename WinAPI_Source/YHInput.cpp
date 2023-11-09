#include "YHInput.h"

namespace YH
{
	std::vector<Input::Key> Input::m_Keys = { };

	int ASCII[(UINT)KeyCode::End]
	{
		'W','A','S','D',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
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

	void Input::Update()
	{
		for (size_t i = 0; i < m_Keys.size(); i++)
		{
			// 키가 눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (m_Keys[i].pressed == true)
				{
					m_Keys[i].state = KeyState::Pressed;
				}
				else
				{
					m_Keys[i].state = KeyState::Down;
				}

				m_Keys[i].pressed = true;
			}
			// 키가 안눌림
			else
			{
				if (m_Keys[i].pressed == true)
				{
					m_Keys[i].state = KeyState::Up;
				}
				else
				{
					m_Keys[i].state = KeyState::None;
				}

				m_Keys[i].pressed = false;
			}
		}
	}
}
