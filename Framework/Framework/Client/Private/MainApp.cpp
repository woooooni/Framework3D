#include "stdafx.h"
#include "..\Public\MainApp.h"



CMainApp::CMainApp()	
{
}


HRESULT CMainApp::Initialize()
{
	/* 1. �� ������ �ʱ�ȭ�� �����Ҳ���. */
	/* 1-1. �׷�����ġ�� �ʱ�ȭ�Ѵ�. */
	/* 1-2. ������ġ�� �ʱ�ȭ�Ѵ�. */
	/* 1-3. �Է���ġ�� �ʱ�ȭ�Ѵ�. */
	/* 1-4. ���ӳ����� ����� ����(��)�� �����Ѵ�.   */
	/* 1-4-1. ���ӳ����� ����� ���� �ڿ�(�ؽ���, ��, ��ü) ���� �غ��Ѵ�.  */

	return S_OK;
}

void CMainApp::Tick()
{
	/* ���ӳ��� �����ϴ� ���� ��ü���� ����. */
	/* ������ ���� */
}

HRESULT CMainApp::Render()
{
	/* ���ӳ��� �����ϴ� ���� ��ü���� ������. */
	return S_OK;
}

void Client::CMainApp::Free()
{	

	__super::Free();
}
