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

class CMainApp
{
public:
	CMainApp();
	~CMainApp();

public:
	HRESULT Initialize();
	void Tick();
	HRESULT Render();
};

