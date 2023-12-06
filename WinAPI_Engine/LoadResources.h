#pragma once
#include "../WinAPI_Source/YH_Resources.h"
#include "../WinAPI_Source/YH_Texture.h"

namespace YH
{
	void LoadResources()
	{
		// Title Scene
		Resources::Load<graphics::Texture>(L"Title",				L"..\\Resources\\Title.png");

		// Lobby Scene
		Resources::Load<graphics::Texture>(L"WorldSelect",			L"..\\Resources\\WorldSelect.png");

		// Player
		Resources::Load<graphics::Texture>(L"Player",				L"..\\Resources\\Player_Sprite.png");

		// Skill
		Resources::Load<graphics::Texture>(L"FairyTurn",			L"..\\Resources\\Skill\\FairyTurn.png");
		Resources::Load<graphics::Texture>(L"LeftFairyTurn",		L"..\\Resources\\Skill\\LeftFairyTurn.png");
		Resources::Load<graphics::Texture>(L"RightFairyTurn",		L"..\\Resources\\Skill\\RightFairyTurn.png");
																					 
		Resources::Load<graphics::Texture>(L"LeftBoringSongStart",	L"..\\Resources\\Skill\\LeftBoringSongStart.png");
		Resources::Load<graphics::Texture>(L"LeftBoringSonging",	L"..\\Resources\\Skill\\LeftBoringSonging.png");
		Resources::Load<graphics::Texture>(L"LeftBoringSongEnd",	L"..\\Resources\\Skill\\LeftBoringSongEnd.png");
		Resources::Load<graphics::Texture>(L"RightBoringSongStart",	L"..\\Resources\\Skill\\RightBoringSongStart.png");
		Resources::Load<graphics::Texture>(L"RightBoringSonging",	L"..\\Resources\\Skill\\RightBoringSonging.png");
		Resources::Load<graphics::Texture>(L"RightBoringSongEnd",	L"..\\Resources\\Skill\\RightBoringSongEnd.png");
																					
		Resources::Load<graphics::Texture>(L"BoringArrow",			L"..\\Resources\\Skill\\BoringArrow.png");
																					 
		Resources::Load<graphics::Texture>(L"LeftHowlingStart",		L"..\\Resources\\Skill\\LeftHowlingStart.png");
		Resources::Load<graphics::Texture>(L"RightHowlingStart",	L"..\\Resources\\Skill\\RightHowlingStart.png");																				
		Resources::Load<graphics::Texture>(L"HowlingAttack",		L"..\\Resources\\Skill\\HowlingAttack.png");
		Resources::Load<graphics::Texture>(L"HowlingAttackEnd",		L"..\\Resources\\Skill\\HowlingAttackEnd.png");

		// Boss & Monster
		Resources::Load<graphics::Texture>(L"Mushroom",				L"..\\Resources\\Monster\\Mushroom_Sprite.png");

		Resources::Load<graphics::Texture>(L"Cygnus",				L"..\\Resources\\Boss\\CygnusCommon.png");
		Resources::Load<graphics::Texture>(L"LeftCygnusSkill2",		L"..\\Resources\\Boss\\LeftCygnusSkill2.png");
		Resources::Load<graphics::Texture>(L"RightCygnusSkill2",	L"..\\Resources\\Boss\\RightCygnusSkill2.png");

		// Map
		Resources::Load<graphics::Texture>(L"Mapleisland_0",		L"..\\Resources\\Map\\Mapleisland_0.png");

		Resources::Load<graphics::Texture>(L"BossCygnusArena",		L"..\\Resources\\Map\\BossArena.png");

		// ��ǳ������ �� -> ... -> �ñ׳ʽ��� ���� ( ���� ���̵� )
	}
}