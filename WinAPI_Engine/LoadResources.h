#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		// Title Scene
		Resources::Load<graphics::Texture>(L"Title_Bg", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_1_0.png");
		Resources::Load<graphics::Texture>(L"Title_Logo", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_1_2.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"Lobby_Bg", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\SplashScreens\\Splash_9_0.png");
		Resources::Load<graphics::Texture>(L"Lobby_Logo", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Logo.png");

		// Play Scene
		Resources::Load<graphics::Texture>(L"Play_Bg_1", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_284.png");
		Resources::Load<graphics::Texture>(L"Play_Bg_2", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_52.png");
		Resources::Load<graphics::Texture>(L"Play_Bg_3", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Background_222.png");
		Resources::Load<graphics::Texture>(L"Play_Cloud", L"C:\\Users\\user\\Documents\\GitHub\\Windosw_API_Project_Terraria\\Resources\\Images\\Cloud_7.png");
	}
}