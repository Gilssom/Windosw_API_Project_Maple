#pragma once
#include "YH_Entity.h"

namespace YH
{
	// ���� ���� �Լ��� �ϳ��� �����ϴ� Ŭ������ "�߻� Ŭ����" �̴�.
	// �޸� �Ҵ� X , ��� �޾Ƽ� ����ؾ� ��.
	class Resource abstract : public Entity
	{
	public:
		Resource(enums::ResourceType type);
		virtual ~Resource();

		// ���� ���� �Լ� : ���� �޸� �Ҵ� �Ұ���
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

// ���ӿ��� ���Ǵ� �����͵��� ����

// �̹��� , ���� , , , N�������� Ŭ���� ��

// ���� ���� �÷��̵����� > HDD , SteamCloud ,, ��
// �̰� ���� ���ҽ�.