#pragma once
#include "../WinAPI_Source/YH_GameObject.h"

namespace YH
{
	class Ground : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}