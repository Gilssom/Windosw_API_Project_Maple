#pragma once
#include "../WinAPI_Source/YH_Script.h"
#include "../WinAPI_Source/YH_Transform.h"

namespace YH
{
	class TigurueScript : public Script
	{
	public:
		enum class State
		{
			Idle,
			Walk,
			Attack,
			Death,
		};

		enum class Direction
		{
			Right,
			Left,
		};

		TigurueScript();
		~TigurueScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetSpawnPos(Vector2 spawnPos) { m_SpawnPos = spawnPos; }
		void DeathEvent();
		void ReSpawn();

	private:
		void Idle();
		void Move();
		void Attack();
		void Death();

		void PlayWalkAnimationByDirection(Direction dir);

		void Translate(Transform* transform);

		void SetDamage(int damage)
		{
			m_Damage = damage;
			ViewDamageFont(m_Damage);
		}
		void ViewDamageFont(int damage);

	private:
		State m_State;
		Direction m_Dir;
		Vector2 m_SpawnPos;
		class Animator* m_Animator;
		float m_Time;
		float m_NextFsmTime;
		float m_DeathTime;
		bool isDeath;

		class GameObject* m_NumberImage[10];
		int m_Damage;

		std::wstring m_Name[10] =
		{
			L"Zero",
			L"One",
			L"Two",
			L"Three",
			L"Four",
			L"Five",
			L"Six",
			L"Seven",
			L"Eight",
			L"Nine",
		};
	};
}