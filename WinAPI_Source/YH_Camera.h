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

		bool CameraAreaCheck();
		void CameraSettings();

		Vector2 GetPosition() { return m_LookPosition; }
		GameObject* GetPlayer() { return m_Target; }
		void SetTarget(GameObject* target) { m_Target = target; }

		void GetBackWidth(float width) { m_BackWidth = width; }
		void GetBackHeight(float height) { m_BackHeight = height; }

	private:
		//std::vector<GameObject*> m_GameObjects;
		class GameObject* m_Target;
		Vector2 m_Distance;
		Vector2 m_Resolution;
		Vector2 m_LookPosition;

		bool isSetting;
		float m_BackWidth;
		float m_BackHeight;
	};
}

