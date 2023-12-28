#pragma once
#include "../WinAPI_Source/YH_Script.h"

namespace YH
{
	class PortalScript : public Script
	{
	public:
		PortalScript();
		~PortalScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetNextScene(const std::wstring& sceneName) { m_ConnectionScene = sceneName; }
		void SetSpawnPos(Vector2 pos) { m_SpawnPosition = pos; }

	private:
		std::wstring m_ConnectionScene;
		Vector2 m_SpawnPosition;
	};
}