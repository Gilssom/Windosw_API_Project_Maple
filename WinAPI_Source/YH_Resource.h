#pragma once
#include "YH_Entity.h"

namespace YH
{
	// 순수 가상 함수가 하나라도 존재하는 클래스는 "추상 클래스" 이다.
	// 메모리 할당 X , 상속 받아서 사용해야 함.
	class Resource abstract : public Entity
	{
	public:
		Resource(enums::ResourceType type);
		virtual ~Resource();

		// 순수 가상 함수 : 실제 메모리 할당 불가능
		virtual bool Load(const std::wstring& path) = 0; 

		const std::wstring& GetPath() { return m_Path; }
		void SetPath(const std::wstring& path) { m_Path = path; }

	private:
		enums::ResourceType m_Type;
		std::wstring m_Path;
	};

	//class Texture : public Resource
	//class AudioClip : public Resource
}

// 게임에서 사용되는 데이터들의 종류

// 이미지 , 사운드 , , , N스테이지 클리어 등

// 저장 게임 플레이데이터 > HDD , SteamCloud ,, 등
// 이것 또한 리소스.