#include "YH_Fmod.h"

namespace YH
{
	FMOD::Studio::System* Fmod::m_System = nullptr;
	FMOD::System* Fmod::m_CoreSystem = nullptr;

	void Fmod::Initialize()
	{
		void* extraDriverData = nullptr;

		FMOD::Studio::System::create(&m_System);

		m_System->getCoreSystem(&m_CoreSystem);
		m_CoreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);

		m_System->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);
	}

	bool Fmod::CreateSound(const std::string& path, FMOD::Sound** sound)
	{
		if (FMOD_OK != m_CoreSystem->createSound(path.c_str(), FMOD_3D, 0, sound))
			return false;

		return true;
	}

	void Fmod::SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel)
	{
		m_CoreSystem->playSound(sound, 0, false, channel);
	}

	void Fmod::Set3DListenerAttributes(const Vector2* pos)
	{
		//-1 ~ 1
		FMOD_VECTOR fmodPos(0.0f, 0.0f, 0.3f);
		FMOD_VECTOR fmodVel(0.0f, 0.0f, 0.0f);
		FMOD_VECTOR fmodForward(0.0f, 0.0f, 1.0f);
		FMOD_VECTOR fmodUp(0.0f, 1.0f, 0.0f);

		m_CoreSystem->set3DListenerAttributes(0, &fmodPos, &fmodVel, &fmodForward, &fmodUp);
	}

	void Fmod::Release()
	{
		m_System->release();
		m_System = nullptr;
	}
}