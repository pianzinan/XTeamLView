// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 头文件
#include <Windows.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "TuckTxS.h"
#include "OutPutDebug.h"

	
DWORD WINAPI Strat(LPVOID lpParam)
{
	// 开始
	TuckMsg* MyTuckMsg;
	MyTuckMsg = TuckMsg::Instance();
	MyTuckMsg->Start();
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 入口函数
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		
		CreateThread(NULL, 0, Strat, NULL, 0, NULL);
		
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




