#pragma once
#include "YH_Component.h"
#include "YH_Animation.h"

namespace YH
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				m_Event = std::move(func);
			}

			void operator()()
			{
				if (m_Event)
					m_Event();
			}

			void operator=(std::function<void(bool)> func)
			{
				m_Event2 = std::move(func);
			}

			void operator()(bool ch)
			{
				if (m_Event2)
					m_Event2(ch);
			}

			//void*(), int
			std::function<void(bool)> m_Event2;
			std::function<void()> m_Event;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLength, float duration);

		void CreateAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);

		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		std::function<void(bool)>& GetCompleteEvent2(const std::wstring& name);

		bool IsComplete() { return m_ActiveAnimation->IsComplete(); }

		// 방향 전환 (테스트) -> m_ActiveAnimation 의 AnimFlip 함수 호출
		void ImageFlip();

	private:
		std::map<std::wstring, Animation*> m_Animations;
		Animation* m_ActiveAnimation;
		bool isLoop;

		std::map<std::wstring, Events*> m_Events;
	};
}