#include "stdafx.h"
#include "..\Public\MainApp.h"



CMainApp::CMainApp()	
{
}


HRESULT CMainApp::Initialize()
{
	/* 1. 내 게임의 초기화를 수행할꺼야. */
	/* 1-1. 그래픽장치를 초기화한다. */
	/* 1-2. 사운드장치를 초기화한다. */
	/* 1-3. 입력장치를 초기화한다. */
	/* 1-4. 게임내에서 사용할 레벨(씬)을 생성한다.   */
	/* 1-4-1. 게임내에서 사용할 여러 자원(텍스쳐, 모델, 객체) 들을 준비한다.  */

	return S_OK;
}

void CMainApp::Tick()
{
	/* 게임내에 존재하는 여러 객체들의 갱신. */
	/* 레벨의 갱신 */
}

HRESULT CMainApp::Render()
{
	/* 게임내에 존재하는 여러 객체들의 렌더링. */
	return S_OK;
}

void Client::CMainApp::Free()
{	

	__super::Free();
}
