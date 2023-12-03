#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		// Title Scene
		Resources::Load<graphics::Texture>(L"Title", L"..\\Resources\\Title.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"WorldSelect", L"..\\Resources\\WorldSelect.png");

		// Play Scene
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player_Sprite.png");
		Resources::Load<graphics::Texture>(L"Mushroom", L"..\\Resources\\Mushroom_Sprite.png");

		// Skill
		Resources::Load<graphics::Texture>(L"FairyTurn", L"..\\Resources\\FairyTurn.png");
		Resources::Load<graphics::Texture>(L"BoringSong", L"..\\Resources\\BoringSong.png");
		Resources::Load<graphics::Texture>(L"BoringSongEnd", L"..\\Resources\\BoringSongEnd.png");

		// Map
		Resources::Load<graphics::Texture>(L"Mapleisland_0", L"..\\Resources\\Mapleisland_0.png");


		// 단풍나무의 숲 -> ... -> 시그너스의 전당 ( 여제 레이드 )
	}
}