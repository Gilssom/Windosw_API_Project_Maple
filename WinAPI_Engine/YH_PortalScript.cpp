#include "YH_PortalScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Rigidbody.h"

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
			other->GetOwner()->GetComponent<Transform>()->SetPosition(m_SpawnPosition);
			SceneManager::LoadScene(m_ConnectionScene);
		}
	}

	void PortalScript::OnCollisionExit(Collider* other)
	{

	}
}