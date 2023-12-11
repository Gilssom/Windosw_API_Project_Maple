#pragma once
#include "../WinAPI_Source/YH_Script.h"
#include "../WinAPI_Source/YH_Transform.h"

namespace YH
{
	class ArrowScript : public Script
	{
	public:
		enum class Direction
		{
			Right,
			Left,
		};

		ArrowScript();
		~ArrowScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(GameObject* player) { m_Player = player; }
		void SetSpeed(float speed) { m_Speed = speed; }

		Vector2 m_Dest;

	private:
		void Move();
		void Attack();

	private:
		class Animator* m_Animator;
		Direction m_Direction;
		float m_Speed;
		float m_Time;
		float m_DeathTime;

		GameObject* m_Player;
		float m_Radian;
	};
}