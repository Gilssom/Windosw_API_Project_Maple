#pragma once

namespace YH::enums
{
	enum class ComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		AudioListener,
		AudioSource,
		End,
	};

	enum class LayerType
	{
		None,
		Camera,
		Sky,
		BackGround,
		Tile,
		Tree,
		Boss,
		Monster,
		Player,
		Ground,
		Rope,
		RimitGround,
		Portal,
		Effect,
		UI,
		Max = 20,
		// ...
	};

	enum class ResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class ColliderType
	{
		None,
		FairyTurn,
		HowlingGale,
		BoringArrow,
		DarknessBall,
		Portal,
		Rope,
		RimitGround,
	};

	enum class ColliderShapeType
	{
		Circle2D,
		Rect2D,
		End,
	};

	enum class UIType
	{
		HpBar,
		Button,
		End,
	};
}