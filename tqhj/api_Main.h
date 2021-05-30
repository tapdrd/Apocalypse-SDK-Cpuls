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
	DllApi_SendAllMsg = (Api_SendAllMsg)GetProcAddress(hDll, "Admini_Group_Notice");
	DllApi_SystemCheck = (Api_SystemCheck)GetProcAddress(hDll, "ϵͳ���");
	DllApi_SendEvent = (Api_SendEvent)GetProcAddress(hDll, "�¼�_������Ϣ");
	DllApi_CallPluginDataOperate = (Api_CallPluginDataOperate)GetProcAddress(hDll, "_call_plugin_data_operate");
	DllApi_CallPluginDataGet = (Api_CallPluginDataGet)GetProcAddress(hDll, "_call_plugin_data_get");
	DllApi_CallPluginVersion = (Api_CallPluginVersion)GetProcAddress(hDll, "_call_plugin_ver");
	DllApi_MessageVariableProcessing = (Api_MessageVariableProcessing)GetProcAddress(hDll, "message_variable_processing");
	DllApi_CallCommandMsg = (Api_CallCommandMsg)GetProcAddress(hDll, "_call_command_msg");
	return true;
}

#include "app_info.h"	// Ӧ����Ϣ
#include "constant.h"	// ����
#include "gm.h"			// ͨ��API