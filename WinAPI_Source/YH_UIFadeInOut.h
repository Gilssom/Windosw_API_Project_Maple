#pragma once
#include "YH_UIBase.h"
#include "YH_Texture.h"

namespace YH
{
	class UIFadeInOut : public UIBase
	{
	public:
		UIFadeInOut();
		~UIFadeInOut();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void AlphaCheck();

		static bool GetComplete() { return isComplete;}
		static bool GetNeedPop() { return isNeedPop; }

	private:
		graphics::Texture* m_Texture;

		float m_Alpha;
		static bool isComplete, isNeedPop;
	};
}