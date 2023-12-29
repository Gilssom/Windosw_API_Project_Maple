#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class BossCygnusScene : public Scene
	{
	public:
		BossCygnusScene();
		~BossCygnusScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class GameObject* m_Bg;
		class GameObject* m_Monster[50];
		class Cygnus* m_Cygnus;
		class GameObject* m_Effect[50];
		class Player* m_Player;

		float m_Width, m_Height;
	};
}