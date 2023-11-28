#pragma once
#include "CommonInclude.h"

using namespace YH::math;

namespace YH
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { m_Name = name; }
		std::wstring& GetName() { return m_Name; }

	private:
		std::wstring m_Name;
	};
}