#pragma once

#include "CommonInclude.h"
#include "..\\Editor_Window\\External\\Include\\Fmod\fmod_studio.hpp"
#include "..\\Editor_Window\\External\\Include\\Fmod\\fmod.hpp"
#include "..\\Editor_Window\\External\\Include\\Fmod\\fmod_common.h"
#include "..\\Editor_Window\\External\\Include\\Fmod\\fmod_codec.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\Editor_Window\\External\\Library\\Fmod\\Debug\\fmodL_vc.lib")
#pragma comment(lib, "..\\Editor_Window\\External\\Library\\Fmod\\Debug\\fmodstudioL_vc.lib")
#else
#pragma comment(lib, "..\\Editor_Window\\External\\Library\\Fmod\\Debug\\fmod_vc.lib")
#pragma comment(lib, "..\\Editor_Window\\External\\Library\\Fmod\\Release\\fmodstudio_vc.lib")
#endif

namespace YH
{
	using namespace math;

	class Fmod
	{
	public:
		static void Initialize();
		static bool CreateSound(const std::string& path, FMOD::Sound** sound);
		static void SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel);
		static void Set3DListenerAttributes(const Vector2* pos);
		static void Release();

	private:
		static FMOD::Studio::System* m_System;
		static FMOD::System* m_CoreSystem;
	};
}