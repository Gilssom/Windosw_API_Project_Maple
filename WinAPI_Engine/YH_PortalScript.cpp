#include "YH_PortalScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Rigidbody.h"
#include "YH_UIManager.h"
#include "YH_UIFadeInOut.h"

namespace YH
{
	PortalScript::PortalScript()
	{

	}

	PortalScript::~PortalScript()
	{

	}

	void PortalScript::Initialize()
	{

	}

	void PortalScript::Update()
	{

	}

	void PortalScript::LateUpdate()
	{
		if (UIFadeInOut::GetComplete() && isPortal)
		{
			m_Other->GetOwner()->GetComponent<Transform>()->SetPosition(m_SpawnPosition);
			SceneManager::LoadScene(m_ConnectionScene);
			isPortal = false;
		}
	}

	void PortalScript::Render(HDC hdc)
	{

	}

	void PortalScript::OnCollisionEnter(Collider* other)
	{

	}

	void PortalScript::OnCollisionStay(Collider* other)
	{
		if (Input::GetKeyDown(KeyCode::Up))
		{
			UIManager::Push(UIType::FadeInOut);

			m_Other = other;
			isPortal = true;
		}
	}

	void PortalScript::OnCollisionExit(Collider* other)
	{

	}
}