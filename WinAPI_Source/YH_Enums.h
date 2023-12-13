#pragma once

namespace YH::enums
{
	enum class ComponentType
	{
		Transform,
		Collider,
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
		UI,
		Tree,
		Ground,
		Boss,
		Monster,
		Player,
		Effect,
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
	};

	enum class ColliderShapeType
	{
		Circle2D,
		Rect2D,
		End,
	};
}