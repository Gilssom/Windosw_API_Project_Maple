#include "YH_AudioClip.h"

namespace YH
{
	AudioClip::AudioClip()
		: Resource(enums::ResourceType::AudioClip)
		, m_Sound(nullptr)
		, m_Channel(nullptr)
		, m_MinDistance(1.0f)
		, m_MaxDistance(1000.0f)
		, isLoop(false)
	{
	}

	AudioClip::~AudioClip()
	{
		m_Sound->release();
		m_Sound = nullptr;
	}

	bool AudioClip::Load(const std::wstring& path)
	{
		std::string cPath(path.begin(), path.end());
		if (!Fmod::CreateSound(cPath, &m_Sound))
			return false;

		m_Sound->set3DMinMaxDistance(m_MinDistance, m_MaxDistance);

		return true;
	}

	void AudioClip::Play()
	{
		if (isLoop)
			m_Sound->setMode(FMOD_LOOP_NORMAL);
		else
			m_Sound->setMode(FMOD_LOOP_OFF);

		Fmod::SoundPlay(m_Sound, &m_Channel);
	}

	void AudioClip::Stop()
	{
		m_Channel->stop();
	}

	void AudioClip::Set3DAttributes(const Vector2 pos)
	{
		FMOD_VECTOR fmodPos(0.0f, 0.0f, 0.0f);
		FMOD_VECTOR fmodVel(0.0f, 0.0f, 0.0f);

		m_Channel->set3DAttributes(&fmodPos, &fmodVel);
	}
}