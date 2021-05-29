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
	DllApi_SendAllMsg = (Api_SendAllMsg)GetProcAddress(hDll, "Admini_Group_Notice");
	DllApi_SystemCheck = (Api_SystemCheck)GetProcAddress(hDll, "系统检查");
	DllApi_SendEvent = (Api_SendEvent)GetProcAddress(hDll, "事件_加入消息");
	DllApi_CallPluginDataOperate = (Api_CallPluginDataOperate)GetProcAddress(hDll, "_call_plugin_data_operate");
	DllApi_CallPluginDataGet = (Api_CallPluginDataGet)GetProcAddress(hDll, "_call_plugin_data_get");
	DllApi_CallPluginVersion = (Api_CallPluginVersion)GetProcAddress(hDll, "_call_plugin_ver");
	DllApi_MessageVariableProcessing = (Api_MessageVariableProcessing)GetProcAddress(hDll, "message_variable_processing");
	DllApi_CallCommandMsg = (Api_CallCommandMsg)GetProcAddress(hDll, "_call_command_msg");
	return true;
}

#include "app_info.h"	// 应用信息
#include "constant.h"	// 常量
#include "gm.h"			// 通用API