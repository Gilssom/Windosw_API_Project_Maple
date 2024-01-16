#include "YH_UIManager.h"
#include "YH_UIHUD.h"
#include "YH_UIExp.h"
#include "YH_UIHpBar.h"
#include "YH_UIMpBar.h"
#include "YH_UIButton.h"
#include "YH_UIBossHUD.h"
#include "YH_UIBossHpBar.h"
#include "YH_UIMinimap.h"
#include "YH_UIFadeInOut.h"

namespace YH
{
	std::unordered_map<UIType, UIBase*> UIManager::m_UIs = {};
	std::stack<UIBase*> UIManager::m_UIBases = {};
	std::queue<UIType> UIManager::m_RequestUiQueue = {};
	UIBase* UIManager::m_ActiveUI = nullptr;

	void UIManager::Initialize()
	{
		UIHUD* hud = new UIHUD();
		UIExp* exp = new UIExp();
		UIHpBar* hpbar = new UIHpBar();
		UIMpBar* mpbar = new UIMpBar();
		UIBossHUD* bossHud = new UIBossHUD();
		UIBossHpBar* bossHpbar = new UIBossHpBar();
		UIMinimap* miniMap = new UIMinimap();
		UIFadeInOut* fadeInOut = new UIFadeInOut();

		m_UIs.insert(std::make_pair(UIType::MainUI, hud));
		m_UIs.insert(std::make_pair(UIType::ExpBar, exp));
		m_UIs.insert(std::make_pair(UIType::HpBar, hpbar));
		m_UIs.insert(std::make_pair(UIType::MpBar, mpbar));
		m_UIs.insert(std::make_pair(UIType::BossHpBarBack, bossHud));
		m_UIs.insert(std::make_pair(UIType::BossHpBar, bossHpbar));
		m_UIs.insert(std::make_pair(UIType::Minimap, miniMap));
		m_UIs.insert(std::make_pair(UIType::FadeInOut, fadeInOut));

		UIButton* button = new UIButton();
		m_UIs.insert(std::make_pair(UIType::Button, button));
	}

	void UIManager::OnLoad(UIType type)
	{
		std::unordered_map<UIType, UIBase*>::iterator iter = m_UIs.find(type);

		if (iter == m_UIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = m_UIBases;
		
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}

		if (m_RequestUiQueue.size() > 0)
		{
			UIType requestUI = m_RequestUiQueue.front();
			m_RequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}

	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = m_UIBases;

		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void UIManager::Render(HDC hdc)
	{
		if (m_UIBases.size() <= 0)
			return;

		std::vector<UIBase*> buff;

		UIBase* uibase = nullptr;

		while (m_UIBases.size() > 0)
		{
			uibase = m_UIBases.top();
			m_UIBases.pop();

			buff.push_back(uibase);
		}

		std::reverse(buff.begin(), buff.end());

		for (UIBase* ui : buff)
		{
			ui->Render(hdc);
			m_UIBases.push(ui);
		}
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		// 만약에 현재 추가된 ui가 전체화면이라면
		// 전체화면인 ui 말고 나머지를 전부 비활성화
		if (addUI->IsFullScreen())
		{
			std::stack<UIBase*> uiBases = m_UIBases;

			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->InActive();
				}
			}
		}

		m_UIBases.push(addUI);
		m_ActiveUI = nullptr;
	}

	void UIManager::OnFail()
	{
		m_ActiveUI = nullptr;
	}

	void UIManager::Release()
	{
		for (auto iter : m_UIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::Push(UIType type)
	{
		m_RequestUiQueue.push(type);
	}

	void UIManager::Pop(UIType type)
	{
		if (m_UIBases.size() <= 0)
			return;

		std::stack<UIBase*> tempStack;

		UIBase* uibase = nullptr;

		while (m_UIBases.size() > 0)
		{
			uibase = m_UIBases.top();
			m_UIBases.pop();

			if (uibase->GetType() != type)
			{
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen())
			{
				std::stack<UIBase*> uiBases = m_UIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uibase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uibase = tempStack.top();
			tempStack.pop();
			m_UIBases.push(uibase);
		}
	}
}