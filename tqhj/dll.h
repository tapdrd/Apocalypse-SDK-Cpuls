#pragma once
/*
	���������þ�II, DLL����ͷ�ļ�
*/
typedef LPCSTR(WINAPI* Api_StrToHex)(LPCSTR str);
typedef LPCSTR(WINAPI* Api_HexToStr)(LPCSTR Hex);
typedef LPCSTR(WINAPI* Api_RobotType)(int type);
typedef int(WINAPI* Api_DataHandle)(int type);
typedef int(WINAPI* Api_SendMsg)(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj, LPCSTR APPID);
typedef int(WINAPI* Api_SendAllMsg)(int type, LPCSTR group, LPCSTR msg);
typedef LPCSTR(WINAPI* Api_SystemCheck)(int type, int sub_type, LPCSTR user, LPCSTR group);
typedef LPCSTR(WINAPI* Api_SendEvent)(int type, LPCSTR log);
typedef LPCSTR(WINAPI* Api_CallPluginDataOperate)(LPCSTR json);
typedef LPCSTR(WINAPI* Api_CallPluginDataGet)(LPCSTR json);
typedef LPCSTR(WINAPI* Api_CallPluginVersion)(int type);
typedef LPCSTR(WINAPI* Api_MessageVariableProcessing)(LPCSTR user, LPCSTR msg);
typedef LPCSTR(WINAPI* Api_CallCommandMsg)(int command);

Api_StrToHex  DllApi_StrToHex;	//	�ַ���ת16����
Api_HexToStr  DllApi_HexTostr;	//	16����ת�ַ���
Api_RobotType DllApi_RobotType;	//	��ȡ����������
Api_DataHandle DllApi_DataHandle;// ���ݿ���
Api_SendMsg DllApi_SendMsg;		// ������Ϣ
Api_SendAllMsg DllApi_SendAllMsg;		// ȫ����Ϣ
Api_SystemCheck DllApi_SystemCheck;		// ϵͳ���
Api_SendEvent DllApi_SendEvent;		// �����¼�
Api_CallPluginDataOperate DllApi_CallPluginDataOperate;	// ��չ���ݿ����
Api_CallPluginDataGet DllApi_CallPluginDataGet;			// ��չ���ݿ��ȡ
Api_CallPluginVersion DllApi_CallPluginVersion;			// ��ȡ����汾
Api_MessageVariableProcessing DllApi_MessageVariableProcessing;	// ��Ϣ��������
Api_CallCommandMsg DllApi_CallCommandMsg;	// ��ȡϵͳ����