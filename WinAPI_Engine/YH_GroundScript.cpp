#include "YH_GroundScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"
#include "YH_Rigidbody.h"
#include "YH_PlayerScript.h"

namespace YH
{
	GroundScript::GroundScript()
	{

	}

	GroundScript::~GroundScript()
	{

	}

	void GroundScript::Initialize()
	{

	}

	void GroundScript::Update()
	{

	}

	void GroundScript::LateUpdate()
	{

	}

	void GroundScript::Render(HDC hdc)
	{

	}

	void GroundScript::OnCollisionEnter(Collider* other)
	{
		if (!other->GetOwner()->GetComponent<PlayerScript>()->GetisJumpUp())
		{
			Rigidbody* playerRigid = other->GetOwner()->GetComponent<Rigidbody>();
			Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
			Collider* playerColl = other;

			Rigidbody* groundRigid = this->GetOwner()->GetComponent<Rigidbody>();
			Transform* groundTr = this->GetOwner()->GetComponent<Transform>();
			Collider* groundColl = this->GetOwner()->GetComponent<Collider>();

			float len = fabs(playerTr->GetPostion().y - groundTr->GetPostion().y);
			float scale = fabs(playerColl->GetSize().y * 100 / 2.0f - groundColl->GetSize().y * 100 / 2.0f);

			if (len < scale)
			{
				Vector2 playerPos = playerTr->GetPostion();
				playerPos.y -= (scale - len) - 1.0f;

				playerTr->SetPosition(playerPos);
			}

			playerRigid->SetGround(true);
		}
	}

	void GroundScript::OnCollisionStay(Collider* other)
	{

	}

	void GroundScript::OnCollisionExit(Collider* other)
	{
		Rigidbody* playerRigid = other->GetOwner()->GetComponent<Rigidbody>();

		if(!(other->GetOwner()->GetComponent<PlayerScript>()->GetPlayerisRope()))
			playerRigid->SetGround(false);
	}
}