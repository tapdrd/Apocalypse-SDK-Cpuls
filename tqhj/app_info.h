#pragma once
/*
	���������þ�II, Ӧ����Ϣͷ�ļ�
*/
#include "cJSON.h"
#include "dll.h"
struct plugin_info
{
	LPCSTR appid;	//��Ҫ���ⲿ�ļ�һ��
	LPCSTR name;		//����
	LPCSTR version;	//�汾,�����ⲿ��ʾ
	int h_version;	//�汾��,ÿ���°汾��+1
	LPCSTR author;	//����
	LPCSTR show;		//����
	LPCSTR contact;	//����QQ
	LPCSTR group;//����Ⱥ
	LPCSTR update_log;//������־
	bool windows;// �Ƿ��п���̨
};
// ��ȡӦ����Ϣ
LPCSTR get_plugin_info(plugin_info info)
{
	APPID = info.appid;
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "APPID", info.appid);
	cJSON_AddStringToObject(json, "����", info.author);
	cJSON_AddStringToObject(json, "��չ����", info.name);
	cJSON_AddStringToObject(json, "����汾", info.version);

	cJSON_AddNumberToObject(json, "����汾��", info.h_version);

	cJSON_AddStringToObject(json, "��ϵ��ʽ1", info.contact);
	cJSON_AddStringToObject(json, "��ϵ��ʽ2", info.group);

	cJSON_AddNumberToObject(json, "����", info.windows == true ? 1 : 0);

	cJSON_AddStringToObject(json, "����", info.show);
	cJSON_AddStringToObject(json, "������־", info.update_log);


	cJSON_AddNumberToObject(json, "SDK", 7);
	cJSON_AddStringToObject(json, "ģ��", "3.0.0");
	cJSON_AddNumberToObject(json, "ģ���", 300000);

	char* ch = cJSON_Print(json);
	cJSON_Delete(json);
	return ch;
};