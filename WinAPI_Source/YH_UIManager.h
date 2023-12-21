#pragma once
#include "CommonInclude.h"
#include "YH_UIBase.h"

namespace YH
{
	using namespace enums;

	class UIManager
	{
	public:
		static void Initialize();
		static void OnLoad(UIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(UIType type);
		static void Pop(UIType type);

	private:
		static std::unordered_map<UIType, UIBase*> m_UIs;
		static std::stack<UIBase*> m_UIBases;
		static std::queue<UIType> m_RequestUiQueue;
		static UIBase* m_ActiveUI;
	};
}