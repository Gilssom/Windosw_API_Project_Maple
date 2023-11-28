#include "YH_Animator.h"

namespace YH
{
	Animator::Animator() : Component(enums::ComponentType::Animator),
		m_Animations{}, m_ActiveAnimation(nullptr), isLoop(false)
	{

	}
	Animator::~Animator()
	{

	}

	void Animator::Initialize()
	{

	}
	void Animator::Update()
	{
		if (m_ActiveAnimation)
		{
			m_ActiveAnimation->Update();

			if (m_ActiveAnimation->IsComplete() == true && isLoop == true)
			{
				m_ActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{

	}
	void Animator::Render(HDC hdc)
	{
		if (m_ActiveAnimation)
			m_ActiveAnimation->Render(hdc);
	}

	void Animator::CreateAnimation(const std::wstring& name
		, graphics::Texture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);

		animation->SetAnimator(this);

		m_Animations.insert(std::make_pair(name, animation));
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = m_Animations.find(name);
		if (iter == m_Animations.end())
		{
			return nullptr;
		}

		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		m_ActiveAnimation = animation;
		m_ActiveAnimation->Reset();
		isLoop = loop;
	}
}