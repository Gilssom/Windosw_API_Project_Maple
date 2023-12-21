#pragma once
#include "YH_Entity.h"

namespace YH
{
	using namespace enums;

	class UIBase : public Entity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};

		UIBase(UIType type);
		virtual ~UIBase();

		void Initialize();
		void Active();
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();

		UIType GetType() { return m_Type; }
		void SetType(UIType type) { m_Type = type; }
		void SetFullScreen(bool enable) { isFullScreen = enable; }
		bool IsFullScreen() { return isFullScreen; }

		Vector2 GetPos() { return m_Position; }
		void SetPos(Vector2 position) { m_Position = position; }
		Vector2 GetSize() { return m_Size; }
		void SetSize(Vector2 size) { m_Size = size; }

	protected:
		Vector2 m_Position;
		Vector2 m_Size;
		bool isMouseOn;

	private:
		UIType m_Type;
		bool isFullScreen;
		bool isEnabled;

		//std::vector<UIBase*> mChilds;
		UIBase* m_Parent;
	};
}