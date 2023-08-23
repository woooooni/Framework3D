#include "stdafx.h"
#include "..\Public\MainApp.h"
#include "GameInstance.h"


CMainApp::CMainApp()	
{
}


HRESULT CMainApp::Initialize()
{
	/* 1. �� ������ �ʱ�ȭ�� �����Ҳ���. */
	CGameInstance* pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);

	GRAPHIC_DESC tGraphicDesc;
	ZeroMemory(&tGraphicDesc, sizeof(GRAPHIC_DESC));

	tGraphicDesc.hWnd = g_hWnd;
	tGraphicDesc.eWinMode = GRAPHIC_DESC::WINMODE::WINMODE_WIN;
	tGraphicDesc.iWinSizeX = g_iWinSizeX;
	tGraphicDesc.iWinSizeY = g_iWinSizeY;
	
	/* 1-1. �׷�����ġ�� �ʱ�ȭ�Ѵ�. */
	if(E_FAIL == pGameInstance->Initialize_Engine(tGraphicDesc, &m_pDevice, &m_pContext))
		return E_FAIL;

	
	
	/* 1-2. ������ġ�� �ʱ�ȭ�Ѵ�. */
	/* 1-3. �Է���ġ�� �ʱ�ȭ�Ѵ�. */
	/* 1-4. ���ӳ����� ����� ����(��)�� �����Ѵ�.   */
	/* 1-4-1. ���ӳ����� ����� ���� �ڿ�(�ؽ���, ��, ��ü) ���� �غ��Ѵ�.  */
	Safe_Release(pGameInstance);
	return S_OK;
}

void CMainApp::Tick(_float fTimeDelta)
{
	/* ���ӳ��� �����ϴ� ���� ��ü���� ����. */
	CGameInstance* pGameInstance = CGameInstance::GetInstance();
	Safe_AddRef(pGameInstance);
	pGameInstance->Tick_Engine(fTimeDelta);


	Safe_Release(pGameInstance);
	/* ������ ���� */
}

HRESULT CMainApp::Render()
{
	/* ���ӳ��� �����ϴ� ���� ��ü���� ������. */
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
