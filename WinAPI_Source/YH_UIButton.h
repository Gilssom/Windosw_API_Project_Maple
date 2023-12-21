#pragma once
#include "YH_UIBase.h"
#include "YH_Texture.h"

namespace YH
{
	class UIButton : public UIBase
	{
	public:
		UIButton();
		~UIButton();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void ButtonClick();

	private:
		graphics::Texture* m_Texture;
		Event m_OnClick;
	};
}