#pragma once
/*
	这是天启幻境II, API总入口
*/
#include "dll.h"	// dllApi
LPCSTR APPID;
// 创建Api
bool CreateApi()
{
	HMODULE hDll = GetModuleHandle(L"obtain.dll");
	if (hDll == NULL)return false;
	DllApi_RobotType = (Api_RobotType)GetProcAddress(hDll, "_call_robot_type");
	DllApi_DataHandle = (Api_DataHandle)GetProcAddress(hDll, "_call_data_handle");
	DllApi_SendMsg = (Api_SendMsg)GetProcAddress(hDll, "事件_待处理");
	return true;
}

#include "app_info.h"	// 应用信息
#include "constant.h"	// 常量
#include "gm.h"			// 通用API