#include "YH_PlayerScript.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"

namespace YH
{
	PlayerScript::PlayerScript()
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(KeyCode::Right))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();
			pos.x += 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}

		if (Input::GetKey(KeyCode::Left))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();
			pos.x -= 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}

		if (Input::GetKey(KeyCode::Up))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();
			pos.y -= 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}

		if (Input::GetKey(KeyCode::Down))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();
			pos.y += 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}
}
