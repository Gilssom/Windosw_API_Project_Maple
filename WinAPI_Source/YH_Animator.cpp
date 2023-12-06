#include "YH_Animator.h"
#include "YH_Resources.h"

namespace YH
{
	Animator::Animator() : Component(enums::ComponentType::Animator),
		m_Animations{}, m_ActiveAnimation(nullptr), isLoop(false)
	{

	}
	Animator::~Animator()
	{
		for (auto& iter : m_Animations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : m_Events)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void Animator::Initialize()
	{

	}
	void Animator::Update()
	{
		if (m_ActiveAnimation)
		{
			m_ActiveAnimation->Update();

			Events* events = FindEvents(m_ActiveAnimation->GetName());

			if (m_ActiveAnimation->IsComplete() == true)
			{
				if(events)
					events->completeEvent();

				if(isLoop == true)
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
		, UINT spriteLength, float duration, bool flip)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration, flip);

		animation->SetAnimator(this);

		Events* events = new Events();
		m_Events.insert(std::make_pair(name, events));

		m_Animations.insert(std::make_pair(name, animation));
	}

	void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		int fileCount = 0;
		std::filesystem::path fs(path);
		std::vector<graphics::Texture*> images = {};

		for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();

			graphics::Texture* texture = Resources::Load<graphics::Texture>(fileName, fullName);
			images.push_back(texture);
			fileCount++;
		}

		UINT sheetWidth = images[0]->GetWidth() * fileCount;
		UINT sheetHeight = images[0]->GetHeight();
		graphics::Texture* spriteSheet = graphics::Texture::Create(name, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();

		for (size_t i = 0; i < images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
				, imageWidth, imageHeight
				, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(name, spriteSheet, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight), offset, fileCount, duration);
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

		if (m_ActiveAnimation)
		{
			Events* curEvents = FindEvents(m_ActiveAnimation->GetName());

			if (curEvents)
				curEvents->endEvent();
		}
		
		Events* nextEvents = FindEvents(animation->GetName());

		if(nextEvents)
			nextEvents->startEvent();

		m_ActiveAnimation = animation;
		m_ActiveAnimation->Reset();
		isLoop = loop;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = m_Events.find(name);
		if (iter == m_Events.end())
		{
			return nullptr;
		}

		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->startEvent.m_Event;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->completeEvent.m_Event;
	}

	std::function<void(bool)>& Animator::GetCompleteEvent2(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->completeEvent.m_Event2;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->endEvent.m_Event;
	}

	void Animator::ImageFlip()
	{
		m_ActiveAnimation->AnimFlip();
	}
}