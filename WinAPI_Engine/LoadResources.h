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

		// Player
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player_Sprite.png");
		Resources::Load<graphics::Texture>(L"Mushroom", L"..\\Resources\\Mushroom_Sprite.png");

		// Skill
		Resources::Load<graphics::Texture>(L"FairyTurn", L"..\\Resources\\FairyTurn.png");
		Resources::Load<graphics::Texture>(L"LeftFairyTurn", L"..\\Resources\\LeftFairyTurn.png");
		Resources::Load<graphics::Texture>(L"RightFairyTurn", L"..\\Resources\\RightFairyTurn.png");

		Resources::Load<graphics::Texture>(L"LeftBoringSongStart", L"..\\Resources\\LeftBoringSongStart.png");
		Resources::Load<graphics::Texture>(L"LeftBoringSonging", L"..\\Resources\\LeftBoringSonging.png");
		Resources::Load<graphics::Texture>(L"LeftBoringSongEnd", L"..\\Resources\\LeftBoringSongEnd.png");
		Resources::Load<graphics::Texture>(L"RightBoringSongStart", L"..\\Resources\\RightBoringSongStart.png");
		Resources::Load<graphics::Texture>(L"RightBoringSonging", L"..\\Resources\\RightBoringSonging.png");
		Resources::Load<graphics::Texture>(L"RightBoringSongEnd", L"..\\Resources\\RightBoringSongEnd.png");

		Resources::Load<graphics::Texture>(L"BoringArrow", L"..\\Resources\\BoringArrow.png");

		Resources::Load<graphics::Texture>(L"LeftHowlingStart", L"..\\Resources\\LeftHowlingStart.png");

		Resources::Load<graphics::Texture>(L"HowlingAttack", L"..\\Resources\\HowlingAttack.png");
		Resources::Load<graphics::Texture>(L"HowlingAttackEnd", L"..\\Resources\\HowlingAttackEnd.png");
		// Map

		Resources::Load<graphics::Texture>(L"Mapleisland_0", L"..\\Resources\\Mapleisland_0.png");


		// 단풍나무의 숲 -> ... -> 시그너스의 전당 ( 여제 레이드 )
	}
}