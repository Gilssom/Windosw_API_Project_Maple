#pragma once
#include "YH_Fmod.h"
#include "YH_Resource.h"

namespace YH
{
	class AudioClip : public Resource
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		virtual bool Load(const std::wstring& path) override;

		void Play();
		void Stop();
		void Set3DAttributes(const Vector2 pos);
		void SetLoop(bool loop) { isLoop = loop; }

	private:
		FMOD::Sound* m_Sound;
		FMOD::Channel* m_Channel;
		float m_MinDistance;
		float m_MaxDistance;
		bool isLoop;
	};
}