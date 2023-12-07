#pragma once
#include "CommonInclude.h"
#include "YH_BoxCollider2D.h"
#include "YH_CircleCollider2D.h"

namespace YH
{
	using namespace enums;

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(LayerType left, LayerType right, bool enable);
		static void LayerCollision(class Scene* scene, LayerType left, LayerType right);
		static void ColliderCollision(Collider* left, Collider* right);

	private:
		// Max 크기의 Bit 를 만들어줌
		static std::bitset<(UINT)LayerType::Max> m_CollisionLayerMatrix[(UINT)LayerType::Max];
	};
}