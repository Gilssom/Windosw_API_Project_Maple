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
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up, Space,
		LeftCtrl, LeftAlt,
		LeftMouse, MiddleMouse, RightMouse,
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

		__forceinline static bool GetKeyDown(KeyCode keyCode) { return m_Keys[(UINT)keyCode].state == KeyState::Down; }
		__forceinline static bool GetKeyUp(KeyCode keyCode)	{ return m_Keys[(UINT)keyCode].state == KeyState::Up; }
		__forceinline static bool GetKey(KeyCode keyCode)		{ return m_Keys[(UINT)keyCode].state == KeyState::Pressed; }
		__forceinline static math::Vector2 GetMousePosition() { return m_MousePosition; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(KeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);
		static void GetMousePositionByWindow();
		static void ClearKeys();

	private:
		static std::vector<Key> m_Keys;
		static math::Vector2 m_MousePosition;
	};
}

