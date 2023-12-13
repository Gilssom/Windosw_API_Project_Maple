#include "YH_CollisionManager.h"
#include "YH_Scene.h"
#include "YH_SceneManager.h"
#include "YH_GameObject.h"
#include "YH_Collider.h"
#include "YH_Transform.h"

namespace YH
{
	std::bitset<(UINT)LayerType::Max> CollisionManager::m_CollisionLayerMatrix[(UINT)LayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::m_CollisiononMap = {};

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
			col = (UINT)left;
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
		// 충돌체크로직 작성
		// 두 충돌체의 고유 번호로 가져온 ID 를 확인하여 CollisionID Setting
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보를 확인
		// 1-1. 만약 충돌정보가 없는 상태라면 충돌정보를 생성
		auto iter = m_CollisiononMap.find(id.id);
		if (iter == m_CollisiononMap.end())
		{
			m_CollisiononMap.insert(std::make_pair(id.id, false));
			iter = m_CollisiononMap.find(id.id);
		}
		// 1-2. 충돌 체크 실행
		if (Intersect(left, right))
		{
			// 2-1. 최초 충돌
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}
			// 2-2. 이미 충돌 중
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// 2-3. 충돌을 빠져 나간 상태
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPostion() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPostion() + right->GetOffset();

		// Size 1, 1 일때, 기본 크기는 100 * 100
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		enums::ColliderShapeType leftType = left->GetCollShapeType();
		enums::ColliderShapeType rightType = right->GetCollShapeType();

		if (leftType == enums::ColliderShapeType::Rect2D
			&& rightType == enums::ColliderShapeType::Rect2D)
		{
			// AABB 충돌
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::ColliderShapeType::Circle2D
			&& rightType == enums::ColliderShapeType::Circle2D)
		{
			// Circle 충돌
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);

			float distance = (leftCirclePos - rightCirclePos).length();

			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
				return true;
		}

		if (leftType == enums::ColliderShapeType::Rect2D && rightType == enums::ColliderShapeType::Circle2D
			|| leftType == enums::ColliderShapeType::Circle2D && rightType == enums::ColliderShapeType::Rect2D)
		{
			// Box - Circle 충돌
			return true;
		}

		return false;
	}
}