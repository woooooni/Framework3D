#pragma once

#include "Client_Defines.h"

/* Ŭ������ ����� ���. */
/* 
class CŬ�����̸�
{
private or protected:
	������. 
	�Ҹ���.
public: 
	Getter 
public:	 
	Setter 
public:
	�Լ�
protected:
	����
protected:
	�Լ�
private:
	����
private:
	�Լ�

public:
	���������� �Լ�. (Create, Clone)	
	���������� �Լ�. (Free)
};
*/

/* �� ������ �������� �ʱ�ȭ(Initialize), ����(Tick), ������(Render)�� �����Ѵ�. */

#include "Base.h"

BEGIN(Client)

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize();
	void Tick();
	HRESULT Render();

public:
	virtual void Free() override;
};

END

