#pragma once
#include "CommonInclude.h"
#include "YH_BoxCollider2D.h"
#include "YH_CircleCollider2D.h"

namespace YH
{
	using namespace enums;

	union CollisionID
	{
		struct 
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Clear();

		static void CollisionLayerCheck(LayerType left, LayerType right, bool enable);
		static void LayerCollision(class Scene* scene, LayerType left, LayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);

	private:
		// Max ũ���� Bit �� �������
		static std::bitset<(UINT)LayerType::Max> m_CollisionLayerMatrix[(UINT)LayerType::Max];
		// unordered map �� �ؽ� ���̺� ��� map ( = �ð����⵵ O(1) )
		static std::unordered_map<UINT64, bool> m_CollisiononMap;
	};
}