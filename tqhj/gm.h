#pragma once
/*
	���������þ�II, ͨ��Apiͷ�ļ�
*/
#include "dll.h"
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
/// ����Web��Ϣ
/// </summary>
/// <param name="handle">�û����</param>
/// <param name="sendJson">Ҫ���͵�Json, ��Json ������� info���key�ڷ�������ҳ��</param>
/// <returns></returns>
bool tq_SendWebMsg(int handle, LPCSTR sendJson)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "handle", handle);
	cJSON_AddStringToObject(json, "pluginID", APPID);
	cJSON_AddStringToObject(json, "json", sendJson);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);

	return DllApi_SendEvent(10000, ret)!=0;
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
bool tq_SendMsg(int type, LPCSTR user, LPCSTR group,LPCSTR msg)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendMsg(type, user, group, msg, APPID) != 0;
}
/// <summary>
/// ����ȫ����Ϣ
/// </summary>
/// <param name="msg">Ҫ���͵�����</param>
/// <returns></returns>
bool tq_SendAllMsg(LPCSTR msg)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendAllMsg(2, 0, msg) != 0;
}
/// <summary>
/// ϵͳ���
/// </summary>
/// <param name="type">-1ע��״̬���� 0һ��״̬ 1����ʱ������� </param>
/// <param name="sub_type">������Ϣ��</param>
/// <param name="user">�û�</param>
/// <param name="group">Ⱥ��</param>
/// <param name="message">�����Ƿ��ص���Ϣ����(�����ط��ؿ�)</param>
/// <returns>ȫ����ļ��[������,˵������������ִ��,��ʱ�뿴message����]</returns>
bool tq_SystemCheck(int type, int sub_type, LPCSTR user, LPCSTR group, LPCSTR& message)
{
	LPCSTR ret;
	ret = DllApi_SystemCheck(type, sub_type, user, group);
	if (ret == NULL)ret = "����ʧ��";
	else if (strcmp(ret, "���") == 0)ret = "�˺��ѱ����";
	message = ret;
	return strcmp(message, "") != 0;
}
/// <summary>
/// ���͵�����־ [��Ҫ����̨��������ģʽ]
/// </summary>
/// <param name="log">����</param>
/// <returns></returns>
bool tq_SendDeBugLog(LPCSTR log)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "command", APPID);
	cJSON_AddStringToObject(json, "message", log);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_SendEvent(11, ret) != 0;
}
/// <summary>
/// ������ͨ��־
/// </summary>
/// <param name="log">����</param>
/// <returns></returns>
bool tq_SendLog(LPCSTR log)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "command", APPID);
	cJSON_AddStringToObject(json, "message", log);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_SendEvent(4, ret) != 0;
}
/// <summary>
/// д������ [ֱ��д��������չ���ݿ���SQLite3����]
/// </summary>
/// <param name="file">������Ϊ��ini���ļ�����,�ļ�����ֹΪ'cc.tapdrd.apocalypse',���ļ��������������򻥶�(�������),���Ϊ�ջ�null,����ɾ��������չ����</param>
/// <param name="sec">���ý�[ָ��],���Ϊ�ջ�null,����ɾ��������ʾ</param>
/// <param name="key">������[ָ��],���Ϊ�ջ�null,����ɾ���������ý�</param>
/// <param name="value">�����дΪ����ɾ��,�����Ϊ��,�������޸�,����������� �ж�Ҫ��:type,������,���ý�,������</param>
/// <returns>����ʧ�ܷ��ؼ�,�ɹ�������</returns>
bool tq_WriteProfileString(LPCSTR file, LPCSTR sec, LPCSTR key, LPCSTR value)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 1);
	cJSON_AddStringToObject(json, "appid", APPID);

	if (file == "" || file == NULL) cJSON_AddNullToObject(json, "file");
	else cJSON_AddStringToObject(json, "file", file);

	if (sec == "" || sec == NULL) cJSON_AddNullToObject(json, "sec");
	else cJSON_AddStringToObject(json, "sec", sec);

	if (key == "" || key == NULL) cJSON_AddNullToObject(json, "key");
	else cJSON_AddStringToObject(json, "key", key);

	if (value == "" || value == NULL) cJSON_AddNullToObject(json, "value");
	else cJSON_AddStringToObject(json, "value", value);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_CallPluginDataOperate(ret) != "";
}
/// <summary>
/// �������� [ֱ�Ӵ�������չ���ݿ���SQLite3��ȡ]
/// </summary>
/// <param name="file">������Ϊ��ini���ļ�����,�ļ�����ֹΪ'cc.tapdrd.apocalypse',���ļ��������������򻥶�(�������),���Ϊ�ջ�null,����ɾ��������չ����</param>
/// <param name="sec">���ý�</param>
/// <param name="key">������</param>
/// <returns>����ʧ�ܷ��ؿ�</returns>
LPCSTR tq_ReadProfileString(LPCSTR file, LPCSTR sec, LPCSTR key)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 1);
	cJSON_AddStringToObject(json, "appid", APPID);

	cJSON_AddStringToObject(json, "file", file);

	cJSON_AddStringToObject(json, "sec", sec);

	cJSON_AddStringToObject(json, "key", key);

	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_CallPluginDataGet(ret);
}
/// <summary>
/// ȡ���ý���
/// </summary>
/// <param name="file"></param>
/// <returns>��������</returns>
int tq_GetProfileSecNumber(LPCSTR file)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 2);
	cJSON_AddStringToObject(json, "appid", APPID);

	cJSON_AddStringToObject(json, "file", file);

	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return atoi(DllApi_CallPluginDataGet(ret));
}
/// <summary>
/// ȡ��������
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <returns>��������</returns>
int tq_GetProfileKeyNumber(LPCSTR file, LPCSTR sec)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 3);
	cJSON_AddStringToObject(json, "appid", APPID);

	cJSON_AddStringToObject(json, "file", file);

	cJSON_AddStringToObject(json, "sec", sec);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return atoi(DllApi_CallPluginDataGet(ret));
}
/// <summary>
/// ȡ���ý���, ���ֻ��ȡ����,��ʹ�� tq_GetProfileSecNumber
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <returns>�������ý���,һ��һ��</returns>
LPCSTR tq_GetProFileSrcString(LPCSTR file, LPCSTR sec)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 4);
	cJSON_AddStringToObject(json, "appid", APPID);

	cJSON_AddStringToObject(json, "file", file);

	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_CallPluginDataGet(ret);
}
/// <summary>
/// ȡ��������, ���ֻ��ȡ����,��ʹ�� tq_GetProfileKeyNumber
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <param name="key"></param>
/// <returns>������������,һ��һ��</returns>
LPCSTR tq_GetProFileSrcString(LPCSTR file, LPCSTR sec, LPCSTR key)
{
	cJSON* json = cJSON_CreateObject();
	cJSON_AddNumberToObject(json, "type", 5);
	cJSON_AddStringToObject(json, "appid", APPID);

	cJSON_AddStringToObject(json, "file", file);
	cJSON_AddStringToObject(json, "key", key);
	char* ret = cJSON_Print(json);
	cJSON_Delete(json);
	return DllApi_CallPluginDataGet(ret);
}
/// <summary>
/// ��ȡ����汾
/// </summary>
/// <returns>���� 3.0.3</returns>
LPCSTR tq_GetPluginVersion()
{
	return DllApi_CallPluginVersion(1);
}
/// <summary>
/// ����ȫ�ֱ���
/// </summary>
/// <param name="user">���,�������д��</param>
/// <param name="msg">��Ϣ����</param>
/// <returns>�����滻�������(������չ֧������ȫ�ֱ���)</returns>
LPCSTR tq_MessageVariableProcessing(LPCSTR user, LPCSTR msg)
{
	return DllApi_MessageVariableProcessing(user, msg);
}
/// <summary>
/// ��ȡ����汾��
/// </summary>
/// <returns>���ص�ֵ����:300300</returns>
int tq_GerPluginVersionNumber()
{
	return atoi(DllApi_CallPluginVersion(2));
}
/// <summary>
/// �����Զ�����ϵͳ����
/// </summary>
/// <param name="command">���ó��� #ϵͳ����_</param>
/// <returns></returns>
LPCSTR tq_GetCommandMsg(int command)
{
	return DllApi_CallCommandMsg(command);
}