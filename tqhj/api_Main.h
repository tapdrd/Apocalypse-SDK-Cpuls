#pragma once
/*
	���������þ�II, API�����
*/
#include "dll.h"	// dllApi
LPCSTR APPID;
// ����Api
bool CreateApi()
{
	HMODULE hDll = GetModuleHandle(L"obtain.dll");
	if (hDll == NULL)return false;
	DllApi_RobotType = (Api_RobotType)GetProcAddress(hDll, "_call_robot_type");
	DllApi_DataHandle = (Api_DataHandle)GetProcAddress(hDll, "_call_data_handle");
	DllApi_SendMsg = (Api_SendMsg)GetProcAddress(hDll, "�¼�_������");
	return true;
}

#include "app_info.h"	// Ӧ����Ϣ
#include "constant.h"	// ����
#include "gm.h"			// ͨ��API