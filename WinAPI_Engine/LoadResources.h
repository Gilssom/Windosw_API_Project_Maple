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
		Resources::Load<graphics::Texture>(L"PlayMainUI",			L"..\\Resources\\UI\\PlayMainUI.png");
		Resources::Load<graphics::Texture>(L"MainExpBar",			L"..\\Resources\\UI\\MainExpBar.png");

		Resources::Load<graphics::Texture>(L"StatusBar",			L"..\\Resources\\UI\\StatusBar.png");
		Resources::Load<graphics::Texture>(L"HpBar",				L"..\\Resources\\UI\\HpBar.png");
		Resources::Load<graphics::Texture>(L"MpBar",				L"..\\Resources\\UI\\MpBar.png");

		Resources::Load<graphics::Texture>(L"BossHpBarBg",			L"..\\Resources\\UI\\BossHpBackGround.png");
		Resources::Load<graphics::Texture>(L"BossHpBar",			L"..\\Resources\\UI\\BossHpBar.png");

		Resources::Load<graphics::Texture>(L"NormalDamage",			L"..\\Resources\\UI\\DamageFont.png");

		Resources::Load<graphics::Texture>(L"QueensRoadmap",		L"..\\Resources\\UI\\QueensRoadMinimap.png");
		Resources::Load<graphics::Texture>(L"Flowermap",			L"..\\Resources\\UI\\FlowerMinimap.png");
		Resources::Load<graphics::Texture>(L"BossReadymap",			L"..\\Resources\\UI\\BossReadyMinimap.png");
		Resources::Load<graphics::Texture>(L"BossAreamap",			L"..\\Resources\\UI\\BossAreaMinimap.png");

		Resources::Load<graphics::Texture>(L"WorldButton",			L"..\\Resources\\UI\\WorldSelectButton.png");
		Resources::Load<graphics::Texture>(L"WorldButtonOver",		L"..\\Resources\\UI\\WorldSelectButtonOver.png");
		Resources::Load<graphics::Texture>(L"WorldButtonPress",		L"..\\Resources\\UI\\WorldSelectButtonPress.png");

		Resources::Load<graphics::Texture>(L"FadeInOut",			L"..\\Resources\\UI\\FadeInOut.png");

		Resources::Load<graphics::Texture>(L"LevelUp",				L"..\\Resources\\UI\\LevelUpSprite.png");

		Resources::Load<graphics::Texture>(L"Zero",					L"..\\Resources\\UI\\DamageFont\\Zero.png");
		Resources::Load<graphics::Texture>(L"One",					L"..\\Resources\\UI\\DamageFont\\One.png");
		Resources::Load<graphics::Texture>(L"Two",					L"..\\Resources\\UI\\DamageFont\\Two.png");
		Resources::Load<graphics::Texture>(L"Three",				L"..\\Resources\\UI\\DamageFont\\Three.png");
		Resources::Load<graphics::Texture>(L"Four",					L"..\\Resources\\UI\\DamageFont\\Four.png");
		Resources::Load<graphics::Texture>(L"Five",					L"..\\Resources\\UI\\DamageFont\\Five.png");
		Resources::Load<graphics::Texture>(L"Six",					L"..\\Resources\\UI\\DamageFont\\Six.png");
		Resources::Load<graphics::Texture>(L"Seven",				L"..\\Resources\\UI\\DamageFont\\Seven.png");
		Resources::Load<graphics::Texture>(L"Eight",				L"..\\Resources\\UI\\DamageFont\\Eight.png");
		Resources::Load<graphics::Texture>(L"Nine",					L"..\\Resources\\UI\\DamageFont\\Nine.png");

		Resources::Load<graphics::Texture>(L"CriZero",				L"..\\Resources\\UI\\DamageFont\\CriZero.png");
		Resources::Load<graphics::Texture>(L"CriOne",				L"..\\Resources\\UI\\DamageFont\\CriOne.png");
		Resources::Load<graphics::Texture>(L"CriTwo",				L"..\\Resources\\UI\\DamageFont\\CriTwo.png");
		Resources::Load<graphics::Texture>(L"CriThree",				L"..\\Resources\\UI\\DamageFont\\CriThree.png");
		Resources::Load<graphics::Texture>(L"CriFour",				L"..\\Resources\\UI\\DamageFont\\CriFour.png");
		Resources::Load<graphics::Texture>(L"CriFive",				L"..\\Resources\\UI\\DamageFont\\CriFive.png");
		Resources::Load<graphics::Texture>(L"CriSix",				L"..\\Resources\\UI\\DamageFont\\CriSix.png");
		Resources::Load<graphics::Texture>(L"CriSeven",				L"..\\Resources\\UI\\DamageFont\\CriSeven.png");
		Resources::Load<graphics::Texture>(L"CriEight",				L"..\\Resources\\UI\\DamageFont\\CriEight.png");
		Resources::Load<graphics::Texture>(L"CriNine",				L"..\\Resources\\UI\\DamageFont\\CriNine.png");
		Resources::Load<graphics::Texture>(L"CriEffect",			L"..\\Resources\\UI\\DamageFont\\CriEffect.png");


		Resources::Load<graphics::Texture>(L"Test",					L"..\\Resources\\UI\\Test.bmp");

		// 단풍나무의 숲 -> ... -> 시그너스의 전당 ( 여제 레이드 )
	}
}