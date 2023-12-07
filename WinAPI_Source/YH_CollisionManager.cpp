#include "YH_CollisionManager.h"
#include "YH_Scene.h"
#include "YH_SceneManager.h"
#include "YH_GameObject.h"
#include "YH_Collider.h"

namespace YH
{
	std::bitset<(UINT)LayerType::Max> CollisionManager::m_CollisionLayerMatrix[(UINT)LayerType::Max] = {};

	void CollisionManager::Initialize()
	{

	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetScene();

		for (UINT row = 0; row < (UINT)LayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)LayerType::Max; col++)
			{
				if (m_CollisionLayerMatrix[row][col])
				{
					LayerCollision(scene, (LayerType)row, (LayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render(HDC hdc)
	{

	}

	void CollisionManager::CollisionLayerCheck(LayerType left, LayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			row = (UINT)left;
		}

		m_CollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, LayerType left, LayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;

			Collider* leftColl = left->GetComponent<Collider>();

			if (leftColl == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;

				Collider* rightColl = right->GetComponent<Collider>();

				if (rightColl == nullptr)
					continue;

				if (left == right)
					continue;

				ColliderCollision(leftColl, rightColl);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 面倒眉农肺流 累己
	}
}