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
					m_Event;
			}

			std::function<void()> m_Event;
		};

		struct Events
		{
			Event m_StartEvent;
			Event m_CompleteEvent;
			Event m_EndEvent;
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

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

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