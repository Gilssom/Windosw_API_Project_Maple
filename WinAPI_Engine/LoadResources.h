#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Mushroom", L"..\\Resources\\Alpha_Test.bmp");

		// Title Scene
		Resources::Load<graphics::Texture>(L"Title", L"..\\Resources\\Title.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"WorldSelect", L"..\\Resources\\WorldSelect.png");

		// Play Scene
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player_Walk0_Test.png");

		Resources::Load<graphics::Texture>(L"Player_Idle", L"..\\Resources\\Player_Idle.png");
		Resources::Load<graphics::Texture>(L"Player_Walk", L"..\\Resources\\Player_Walk.png");
		Resources::Load<graphics::Texture>(L"Player_Attack", L"..\\Resources\\Player_Attack.png");

		Resources::Load<graphics::Texture>(L"FairyTurn", L"..\\Resources\\FairyTurn.png");

		Resources::Load<graphics::Texture>(L"Leferae", L"..\\Resources\\Leferae_Test.png");


		// 단풍나무의 숲 -> ... -> 시그너스의 전당 ( 여제 레이드 )
	}
}