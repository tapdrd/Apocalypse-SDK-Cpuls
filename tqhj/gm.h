#pragma once
/*
	���������þ�II, ͨ��Apiͷ�ļ�
*/
#include "dll.h"

/// <summary>
/// �ַ���ת16����
/// </summary>
/// <param name="str">Ҫת�����ַ���</param>
/// <returns></returns>
LPCSTR tq_StrToHex(LPCSTR str)
{
	return DllApi_StrToHex(str);
}
/// <summary>
/// 16�����ַ���
/// </summary>
/// <param name="hex">Ҫת����16����</param>
/// <returns></returns>
LPCSTR tq_HexToStr(LPCSTR hex)
{
	return DllApi_HexTostr(hex);
}
/// <summary>
/// ��ȡ����������
/// </summary>
/// <param name="type">�������������</param>
/// <returns></returns>
LPCSTR tq_GetRobotName(int type)
{
	return DllApi_RobotType(type);
}
/// <summary>
/// ��ȡ���ݿ���
/// </summary>
/// <param name="type">��ʹ�ó���get_DBHandle_xx</param>
/// <returns>���ݿ���</returns>
int tq_GetDBHandle(int type)
{
	return DllApi_DataHandle(type);
}

/// <summary>
/// ������Ϣ
/// </summary>
/// <param name="type">1.˽�� 2.Ⱥ��</param>
/// <param name="user">��Դ�û�</param>
/// <param name="group">Ⱥ��/������</param>
/// <param name="msg">��Ϣ����</param>
/// <param name="from_type">��Դ����</param>
/// <param name="from_obj">��Դ����</param>
/// <returns>�Ƿ��ͳɹ�</returns>
bool tq_SendMsg(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendMsg(type, user, group, msg, from_type, from_obj, APPID) != 0;
}