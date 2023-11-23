#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class LobbyScene : public Scene
	{
	public:
		LobbyScene();
		~LobbyScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* bg[50];
		class GameObject* logo;
	};
}

