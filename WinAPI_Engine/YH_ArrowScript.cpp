#include "YH_ArrowScript.h"
#include "YH_Transform.h"
#include "YH_Time.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Object.h"

namespace YH
{
	ArrowScript::ArrowScript() 
		: m_Direction(ArrowScript::Direction::Left)
		, m_Animator(nullptr), m_Player(nullptr)
		, m_Time(0.0f), m_DeathTime(0.0f), m_Speed(800.0f)
		, m_Dest(Vector2::Zero), m_Radian(0.0f)
	{

	}

	ArrowScript::~ArrowScript()
	{

	}

	void ArrowScript::Initialize()
	{

	}

	void ArrowScript::Update()
	{
		m_DeathTime += Time::DeltaTime();

		if (m_DeathTime > 3.0f)
			object::Destroy(GetOwner());

		if (!m_Animator)
			m_Animator = GetOwner()->GetComponent<Animator>();

		Move();
	}

	void ArrowScript::LateUpdate()
	{

	}

	void ArrowScript::Render(HDC hdc)
	{

	}

	void ArrowScript::Move()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();

		// 상하좌우 위치 이동
		Transform* plTr = m_Player->GetComponent<Transform>();
		pos += m_Dest.normalize() * (m_Speed * Time::DeltaTime());

		// 마우스 위치 이동 ( 벡터의 뺄셈 활용 )
		//Transform* plTr = m_Player->GetComponent<Transform>();
		//Vector2 dest = m_Dest - plTr->GetPostion();
		//pos += dest.normalize() * (100.0f * Time::DeltaTime());


		// 삼각함수를 통한 이동 ( 화살이 사용할 이유가 없음 )

		/*m_Radian += 5.0f * Time::DeltaTime();
		pos += Vector2(1.0f, 2.0f * cosf(m_Radian)) * (100.0f * Time::DeltaTime());*/


		// 마우스 위치 방향으로 회전후 마우스 위치 이동 ( 벡터의 뺄셈 활용 )
		// >> 추후 가까운 적 방향 찾아서 유도탄으로 만들 때 사용 ( 화살 방향 회전이 필요함 )
		//Transform* plTr = m_Player->GetComponent<Transform>();
		//Vector2 dest = m_Dest - plTr->GetPostion();
		//dest.normalize();

		//float rotDegree = Vector2::Dot(dest, Vector2::Right); //cos세타
		//rotDegree = acosf(rotDegree);

		//rotDegree = ConvertDegree(rotDegree);

		//pos += dest * (100.0f * Time::DeltaTime());

		transform->SetPosition(pos);
	}

	void ArrowScript::Attack()
	{

	}
}