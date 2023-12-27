#include "YH_AudioSource.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Fmod.h"

namespace YH
{
	AudioSource::AudioSource()
		: Component(ComponentType::AudioSource)
	{
	}

	AudioSource::~AudioSource()
	{
	}

	void AudioSource::Initialize()
	{
	}

	void AudioSource::Update()
	{
	}

	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPostion();

		if(m_AudioClip)
			m_AudioClip->Set3DAttributes(pos);
	}

	void AudioSource::Render(HDC hdc)
	{
	}

	void AudioSource::Play()
	{
		m_AudioClip->Play();
	}

	void AudioSource::Stop()
	{
		m_AudioClip->Stop();
	}

	void AudioSource::SetLoop(bool loop)
	{
		m_AudioClip->SetLoop(loop);
	}
}