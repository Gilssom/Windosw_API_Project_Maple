#include "YH_Animation.h"
#include "YH_Time.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Animator.h"
#include "YH_Renderer.h"
#include "YH_Camera.h"

namespace YH
{
	Animation::Animation() : Resource(enums::ResourceType::Animation)
		, m_Animator(nullptr), m_Texture(nullptr), m_AnimationSheet{}
		, m_Index(-1), m_Time(0.0f), m_Complete(false)
	{

	}
	Animation::~Animation()
	{

	}

	bool Animation::Load(const std::wstring& path)
	{
		return false;
	}

	void Animation::Update()
	{
		if (m_Complete)
			return;

		m_Time += Time::DeltaTime();

		if (m_AnimationSheet[m_Index].duration < m_Time)
		{
			m_Time = 0.0f;

			if (m_Index < m_AnimationSheet.size() - 1)
			{
				m_Index++;
			}
			else
			{
				m_Complete = true;
			}
		}
	}

	void Animation::Render(HDC hdc)
	{
		// 알파블렌드를 쓸 수 있는 조건 : 해당 이미지에 알파채널이 존재해야 한다.
		//AlphaBlend()

		if (m_Texture == nullptr)
			return;

		GameObject* gameObj = m_Animator->GetOwner();
		Transform* transform = gameObj->GetComponent<Transform>();
		Vector2 pos = transform->GetPostion();
		float rot = transform->GetRotation();
		Vector2 scale = transform->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		Sprite sprite = m_AnimationSheet[m_Index];
		graphics::Texture::TextureType type = m_Texture->GetTextureType();

		if (type == graphics::Texture::TextureType::Bmp)
		{
			HDC imgHdc = m_Texture->GetHdc();

			if (m_Texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc, sprite.leftTop.x, sprite.leftTop.y
					, sprite.size.x, sprite.size.y, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 0, 255));
			}
		}
		else if (type == graphics::Texture::TextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬 때 사용
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(m_Texture->GetImage()
				, Gdiplus::Rect(
					  pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x 
				, sprite.leftTop.y 
				, sprite.size.x 
				, sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name
		, graphics::Texture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLength, float duration)
	{
		m_Texture = spriteSheet;

		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			m_AnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		m_Time = 0.0f;
		m_Index = 0;
		m_Complete = false;
	}

	void Animation::AnimFlip()
	{
		m_Texture->GetImage()->RotateFlip(Gdiplus::RotateNoneFlipX);
	}
}