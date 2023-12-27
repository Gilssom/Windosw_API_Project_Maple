#include "YH_AudioListener.h"
#include "YH_Transform.h"
#include "YH_GameObject.h"
#include "YH_Fmod.h"

namespace YH
{
	AudioListener::AudioListener()
		: Component(ComponentType::AudioListener)
	{
	}

	AudioListener::~AudioListener()
	{
	}

	void AudioListener::Initialize()
	{
	}

	void AudioListener::Update()
	{
	}

	void AudioListener::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPostion();

		Fmod::Set3DListenerAttributes(&pos);
	}

	void AudioListener::Render(HDC hdc)
	{
	}
}