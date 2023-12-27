#pragma once
#include "YH_Component.h"
#include "YH_AudioClip.h"

namespace YH
{
	class AudioSource : public Component
	{
	public:
		AudioSource();
		~AudioSource();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Play();
		void Stop();
		void SetLoop(bool loop);

		void SetClip(AudioClip* clip) { m_AudioClip = clip; }
		AudioClip* GetClip() { return m_AudioClip; }

	private:
		AudioClip* m_AudioClip;
	};
}