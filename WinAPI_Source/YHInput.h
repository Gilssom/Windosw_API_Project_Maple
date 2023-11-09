#pragma once
#include "CommonInclude.h"

namespace YH
{
	enum class KeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class KeyCode
	{
		W, A, S, D,
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			KeyCode keyCode;
			KeyState state;
			bool pressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKeyDown(KeyCode keyCode) { return m_Keys[(UINT)keyCode].state == KeyState::Down; }
		static bool GetKeyUp(KeyCode keyCode)	{ return m_Keys[(UINT)keyCode].state == KeyState::Up; }
		static bool GetKey(KeyCode keyCode)		{ return m_Keys[(UINT)keyCode].state == KeyState::Pressed; }

	private:
		static std::vector<Key> m_Keys;
	};
}

