#pragma once
#include "YH_Collider.h"

namespace YH
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		static void DrawOnOff() 
		{ 
			if (isDraw)
				isDraw = false;
			else
				isDraw = true;
		}

	private:
		static bool isDraw;
	};
}

