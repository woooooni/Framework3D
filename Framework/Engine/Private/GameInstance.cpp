#include "..\Public\GameInstance.h"
#include "Timer_Manager.h"
#include "Graphic_Device.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
	: m_pTimer_Manager(CTimer_Manager::GetInstance())
	, m_pGraphic_Device(CGraphic_Device::GetInstance())
{
	Safe_AddRef(m_pGraphic_Device);
	Safe_AddRef(m_pTimer_Manager);
}

HRESULT CGameInstance::Initialize_Engine(const GRAPHIC_DESC& GraphicDesc)
{
	/* �׷��ȵ���̽� �ʱ�ȭ ó��. */
	if (FAILED(m_pGraphic_Device->Ready_Graphic_Device(GraphicDesc.hWnd, GraphicDesc.eWinMode, GraphicDesc.iWinSizeX, GraphicDesc.iWinSizeY, nullptr, nullptr)))
		return E_FAIL;

	/* �������̽� �ʱ�ȭ ó��. */
	/* �Էµ���̽� �ʱ�ȭ ó��. */

	/* ������Ʈ �Ŵ����� ���� ó��. */
	/* ������Ʈ �Ŵ����� ���� ó��. */

	return E_NOTIMPL;
}

void CGameInstance::Tick(_float fTimeDelta)
{
}

_float CGameInstance::Compute_TimeDelta(const wstring & strTimerTag)
{
	if (nullptr == m_pTimer_Manager)
		return 0.f;

	return m_pTimer_Manager->Compute_TimeDelta(strTimerTag);	
}

HRESULT CGameInstance::Add_Timer(const wstring & strTimerTag)
{
	if (nullptr == m_pTimer_Manager)
		return E_FAIL;

	return m_pTimer_Manager->Add_Timer(strTimerTag);
}

HRESULT CGameInstance::Clear_BackBuffer_View(_float4 vClearColor)
{
	return E_NOTIMPL;
}

HRESULT CGameInstance::Clear_DepthStencil_View()
{
	return E_NOTIMPL;
}

HRESULT CGameInstance::Present()
{
	return E_NOTIMPL;
}

void CGameInstance::Free()
{
}
