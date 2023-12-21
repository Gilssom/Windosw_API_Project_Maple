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
		End,
	};

	enum class LayerType
	{
		None,
		Sky,
		BackGround,
		Tile,
		Tree,
		Boss,
		Monster,
		Player,
		Ground,
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