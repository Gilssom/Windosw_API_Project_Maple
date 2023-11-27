#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		// Title Scene
		Resources::Load<graphics::Texture>(L"Title", L"..\\Resources\\Title_Test.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"WorldSelect", L"..\\Resources\\WorldSelect_Test.png");

		// Play Scene
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player_Walk0_Test.png");

		Resources::Load<graphics::Texture>(L"Leferae", L"..\\Resources\\Leferae_Test.png");
	}
}