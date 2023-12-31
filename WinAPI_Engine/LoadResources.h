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
																					
		Resources::Load<graphics::Texture>(L"R_BoringArrow",		L"..\\Resources\\Skill\\RightBoringArrow.png");
		Resources::Load<graphics::Texture>(L"L_BoringArrow",		L"..\\Resources\\Skill\\LeftBoringArrow.png");
																					 
		Resources::Load<graphics::Texture>(L"LeftHowlingStart",		L"..\\Resources\\Skill\\LeftHowlingStart.png");
		Resources::Load<graphics::Texture>(L"RightHowlingStart",	L"..\\Resources\\Skill\\RightHowlingStart.png");																				
		Resources::Load<graphics::Texture>(L"HowlingAttack",		L"..\\Resources\\Skill\\HowlingAttack.png");
		Resources::Load<graphics::Texture>(L"HowlingAttackEnd",		L"..\\Resources\\Skill\\HowlingAttackEnd.png");

		Resources::Load<graphics::Texture>(L"SharpEyes",			L"..\\Resources\\Buff\\SharpEyes.png");

		Resources::Load<graphics::Texture>(L"DoubleJump",			L"..\\Resources\\Skill\\DoubleJump.png");
		Resources::Load<graphics::Texture>(L"HighJump",				L"..\\Resources\\Skill\\HighJump.png");

		// Hit Effect
		Resources::Load<graphics::Texture>(L"BoringHit",			L"..\\Resources\\Hit\\BoringHit.png");
		Resources::Load<graphics::Texture>(L"FairyTurnHit",			L"..\\Resources\\Hit\\FairyTurnHit.png");
		Resources::Load<graphics::Texture>(L"HowlingHit",			L"..\\Resources\\Hit\\HowlingHit.png");

		// Monster
		Resources::Load<graphics::Texture>(L"Mushroom",				L"..\\Resources\\Monster\\Mushroom_Sprite.png");
		Resources::Load<graphics::Texture>(L"Tigurue",				L"..\\Resources\\Monster\\Tigurue_Sprite.png");
		Resources::Load<graphics::Texture>(L"Tirue",				L"..\\Resources\\Monster\\Tiru_Sprite.png");

		// Boss_Cygnus
		Resources::Load<graphics::Texture>(L"Cygnus",				L"..\\Resources\\Boss\\CygnusCommon.png");

		Resources::Load<graphics::Texture>(L"LeftCygnusSkill1",		L"..\\Resources\\Boss\\LeftCygnusSkill1.png");
		Resources::Load<graphics::Texture>(L"RightCygnusSkill1",	L"..\\Resources\\Boss\\RightCygnusSkill1.png");
		Resources::Load<graphics::Texture>(L"CygnusSkill1Ball",		L"..\\Resources\\Boss\\Skill1Ball.png");

		Resources::Load<graphics::Texture>(L"LeftCygnusSkill2",		L"..\\Resources\\Boss\\LeftCygnusSkill2.png");
		Resources::Load<graphics::Texture>(L"RightCygnusSkill2",	L"..\\Resources\\Boss\\RightCygnusSkill2.png");
		Resources::Load<graphics::Texture>(L"CygnusSkill2Ball",		L"..\\Resources\\Boss\\Skill2Ball.png");

		Resources::Load<graphics::Texture>(L"LeftCygnusSkill3",		L"..\\Resources\\Boss\\LeftCygnusSkill3.png");
		Resources::Load<graphics::Texture>(L"RightCygnusSkill3",	L"..\\Resources\\Boss\\RightCygnusSkill3.png");
		Resources::Load<graphics::Texture>(L"CygnusSkill3Ball",		L"..\\Resources\\Boss\\Skill3Ball.png");
		
		Resources::Load<graphics::Texture>(L"LeftCygnusDeath",		L"..\\Resources\\Boss\\LeftCygnusDeath.png");
		Resources::Load<graphics::Texture>(L"RightCygnusDeath",		L"..\\Resources\\Boss\\RightCygnusDeath.png");

		// Map
		Resources::Load<graphics::Texture>(L"QueensRoad",			L"..\\Resources\\Map\\QueensRoad.png");
		Resources::Load<graphics::Texture>(L"ErebVillage",			L"..\\Resources\\Map\\ErebVillage.png");
		Resources::Load<graphics::Texture>(L"RainDropFlower",		L"..\\Resources\\Map\\RainDropFlower.png");

		Resources::Load<graphics::Texture>(L"BossArenaReady",		L"..\\Resources\\Map\\BossArenaReady.png");
		Resources::Load<graphics::Texture>(L"BossCygnusArena",		L"..\\Resources\\Map\\BossArena.png");

		// UI
		Resources::Load<graphics::Texture>(L"StatusBar",			L"..\\Resources\\UI\\StatusBar.png");
		Resources::Load<graphics::Texture>(L"HpBar",				L"..\\Resources\\UI\\HpBar.png");
		Resources::Load<graphics::Texture>(L"MpBar",				L"..\\Resources\\UI\\MpBar.png");

		Resources::Load<graphics::Texture>(L"Test",					L"..\\Resources\\UI\\Test.bmp");

		// 단풍나무의 숲 -> ... -> 시그너스의 전당 ( 여제 레이드 )
	}
}