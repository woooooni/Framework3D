#include "stdafx.h"
#include "..\Public\MainApp.h"
#include "GameInstance.h"


CMainApp::CMainApp()	
{
}


HRESULT CMainApp::Initialize()
{
	/* 1. 내 게임의 초기화를 수행할꺼야. */
	CGameInstance* pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	GRAPHIC_DESC tGraphicDesc;
	ZeroMemory(&tGraphicDesc, sizeof(GRAPHIC_DESC));

	tGraphicDesc.hWnd = g_hWnd;
	tGraphicDesc.eWinMode = GRAPHIC_DESC::WINMODE::WINMODE_WIN;
	tGraphicDesc.iWinSizeX = g_iWinSizeX;
	tGraphicDesc.iWinSizeY = g_iWinSizeY;
	
	/* 1-1. 그래픽장치를 초기화한다. */
	if(E_FAIL == pGameInstance->Initialize_Engine(tGraphicDesc, &m_pDevice, &m_pContext))
		return E_FAIL;

	
	
	/* 1-2. 사운드장치를 초기화한다. */
	/* 1-3. 입력장치를 초기화한다. */
	/* 1-4. 게임내에서 사용할 레벨(씬)을 생성한다.   */
	/* 1-4-1. 게임내에서 사용할 여러 자원(텍스쳐, 모델, 객체) 들을 준비한다.  */
	Safe_Release(pGameInstance);
	return S_OK;
}

void CMainApp::Tick(_float fTimeDelta)
{
	/* 게임내에 존재하는 여러 객체들의 갱신. */
	CGameInstance* pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);
	pGameInstance->Tick_Engine(fTimeDelta);


	Safe_Release(pGameInstance);
	/* 레벨의 갱신 */
}

HRESULT CMainApp::Render()
{
	/* 게임내에 존재하는 여러 객체들의 렌더링. */
	CGameInstance* pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	if (nullptr == pGameInstance)
		return E_FAIL;

	pGameInstance->Clear_BackBuffer_View(_float4(0.f, 0.f, 1.f, 1.f));
	pGameInstance->Clear_DepthStencil_View();

	// TODO :: Draw & Render
	pGameInstance->Present();

	Safe_Release(pGameInstance);
	return S_OK;
}

CMainApp * CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp;
	if (nullptr == pInstance)
	{
		Safe_Release(pInstance);
		MSG_BOX("Create Failed CMainApp.");
		return nullptr;
	}

	if (E_FAIL == pInstance->Initialize())
	{
		Safe_Release(pInstance);
		MSG_BOX("Initialize Failed CMainApp.");
		return nullptr;
	}

	return pInstance;
}

void Client::CMainApp::Free()
{	

	__super::Free();
}
