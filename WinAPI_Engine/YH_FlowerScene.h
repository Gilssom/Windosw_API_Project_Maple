#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class FlowerScene : public Scene
	{
	public:
		FlowerScene();
		~FlowerScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class GameObject* bg;
		class Monster* m_Monster[50];

		float m_Width, m_Height;
	};
}