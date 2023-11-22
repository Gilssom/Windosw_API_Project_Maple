#pragma once

namespace YH::enums
{
	enum class LayerType
	{
		None,
		BackGround,
		UI,
		Tree,
		Ground,
		Character,
		Player,
		Max = 20,
		// ...
	};

	enum class ResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}