#pragma once

namespace YH::enums
{
	enum class ComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
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
		Character,
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
}