#pragma once
#include "YH_Scene.h"

namespace YH
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Destroy() override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}