#pragma once

#include "Base.h"

/* Ŭ���̾�Ʈ�����ڰ� ������ ����� �̿��ϰ����� �� �����ϴ� ��ü.  */
/* Ŭ���̾�Ʈ�� ��������� �Լ����� ��� �����ϰ� �ִ´�. */

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)
private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public: /* For.GameInstance */
	HRESULT Initialize_Engine(const GRAPHIC_DESC& GraphicDesc);
	void Tick(_float fTimeDelta);

public: /* For.Timer_Manager */
	_float Compute_TimeDelta(const wstring& strTimerTag);
	HRESULT	Add_Timer(const wstring& strTimerTag);

public: /* For.Graphic_Device */
	HRESULT Clear_BackBuffer_View(_float4 vClearColor);	
	HRESULT Clear_DepthStencil_View();	
	HRESULT Present();

private:
	class CTimer_Manager*			m_pTimer_Manager = { nullptr };
	class CGraphic_Device*			m_pGraphic_Device = { nullptr };

public:
	virtual void Free() override;
};

END