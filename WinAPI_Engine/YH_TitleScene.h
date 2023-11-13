#pragma once
#include "../WinAPI_Source/YH_Scene.h"

namespace YH
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}