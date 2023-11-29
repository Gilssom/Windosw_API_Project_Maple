#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class GameObject* bg[50];
		class GameObject* m_Monster[50];
		class GameObject* m_Effect[50];
		class Player* m_Player;
	};
}