#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		// Title Scene
		Resources::Load<graphics::Texture>(L"Title_Bg", L"..\\Resources\\Images\\SplashScreens\\Splash_1_0.png");
		Resources::Load<graphics::Texture>(L"Title_Logo", L"..\\Resources\\Images\\SplashScreens\\Splash_1_2.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"Lobby_Mountain", L"..\\Resources\\Images\\Background_116.png");
		Resources::Load<graphics::Texture>(L"Lobby_Sky", L"..\\Resources\\Images\\Background_179.png");
		Resources::Load<graphics::Texture>(L"Lobby_Cloud", L"..\\Resources\\Images\\Background_112.png");
		Resources::Load<graphics::Texture>(L"Lobby_Logo", L"..\\Resources\\Images\\Logo.png");

		// Play Scene
		Resources::Load<graphics::Texture>(L"Play_Mountain", L"..\\Resources\\Images\\Background_178.png");
		Resources::Load<graphics::Texture>(L"Play_Ground", L"..\\Resources\\Images\\Background_286.png");
		Resources::Load<graphics::Texture>(L"Play_Sky", L"..\\Resources\\Images\\Background_176.png");
		Resources::Load<graphics::Texture>(L"Play_Cloud", L"..\\Resources\\Images\\Cloud_7.png");

		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.png");
	}
}