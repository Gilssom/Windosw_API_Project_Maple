#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class BossReadyScene : public Scene
	{
	public:
		BossReadyScene();
		~BossReadyScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class GameObject* m_Bg;

		float m_Width, m_Height;
		bool check = false;
	};
}