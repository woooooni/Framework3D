#pragma once

#include "Base.h"

BEGIN(Engine)
class ENGINE_DLL CTimer_Manager : public CBase
{
	DECLARE_SINGLETON(CTimer_Manager)

private:
	CTimer_Manager();
	virtual ~CTimer_Manager() = default;

private:
	class CTimer*			Find_Timer(const _tchar* pTimerTag) const;

public:
	_float			Get_TimeDelta(const _tchar* pTimerTag);
	void			Set_TimeDelta(const _tchar* pTimerTag);

public:
	HRESULT			Ready_Timer(const _tchar* pTimerTag);

private:
	map<const wstring&, class CTimer*>		m_mapTimers;

public:
	virtual void	Free(void);
};

END