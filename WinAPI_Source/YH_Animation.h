#pragma once
#include "YH_Resource.h"
#include "YH_Texture.h"

namespace YH
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite() : leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		bool Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLength, float duration);

		void Reset();

		bool IsComplete() { return m_Complete; }
		void SetAnimator(class Animator* animator) { m_Animator = animator; }

	private:
		class Animator* m_Animator;
		graphics::Texture* m_Texture;

		std::vector<Sprite> m_AnimationSheet;
		int m_Index;
		float m_Time;
		bool m_Complete;
	};
}