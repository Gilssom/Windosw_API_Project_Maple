#pragma once
#include "YH_Resource.h"

namespace YH
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = m_Resources.find(key);

			if (iter == m_Resources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);

			if (resource)
				return resource;

			resource = new T();

			if ( !(resource->Load(path)))
				assert(false);

			resource->SetName(key);
			resource->SetPath(path);

			m_Resources.insert(std::make_pair(key, resource));

			return resource;
		}

		static void Insert(const std::wstring& key, Resource* resource)
		{
			if (key == L"")
				return;

			if (!resource)
				return;

			m_Resources.insert(std::make_pair(key, resource));
		}

		static void Release()
		{
			for (auto& iter : m_Resources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}

	private:
		static std::map<std::wstring, Resource*> m_Resources;
	};
}