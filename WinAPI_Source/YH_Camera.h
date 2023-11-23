#pragma once
#include "YH_Component.h"

namespace YH
{
	using namespace YH::math;

	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - m_Distance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { m_Target = target; }

	private:
		//std::vector<GameObject*> m_GameObjects;
		class GameObject* m_Target;
		Vector2 m_Distance;
		Vector2 m_Resolution;
		Vector2 m_LookPosition;
	};
}

