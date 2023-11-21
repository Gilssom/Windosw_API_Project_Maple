#include "YH_Player.h"
#include "YH_Input.h"
#include "YH_Transform.h"
#include "YH_Time.h"

namespace YH
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(KeyCode::Right))
		{
			/*Transform* transform = GetComponent<Transform>();
			Vector2 pos = transform->GetPostion();
			pos.x += 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);*/
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
