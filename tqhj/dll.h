#pragma once
/*
	���������þ�II, DLL����ͷ�ļ�
*/
typedef LPCSTR(WINAPI* Api_StrToHex)(LPCSTR str);
typedef LPCSTR(WINAPI* Api_HexToStr)(LPCSTR Hex);
typedef LPCSTR(WINAPI* Api_RobotType)(int type);
typedef int(WINAPI* Api_DataHandle)(int type);
typedef int(WINAPI* Api_SendMsg)(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj, LPCSTR APPID);

Api_StrToHex  DllApi_StrToHex;	//	�ַ���ת16����
Api_HexToStr  DllApi_HexTostr;	//	16����ת�ַ���
Api_RobotType DllApi_RobotType;	//	��ȡ����������
Api_DataHandle DllApi_DataHandle;// ���ݿ���
Api_SendMsg DllApi_SendMsg;		// ������Ϣ