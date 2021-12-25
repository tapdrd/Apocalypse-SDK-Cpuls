#include "pch.h"

#include "api_Main.h"

#include "code.h"
#include "cJSON.h"

#include <stdlib.h>
#include <string>
using namespace std;

/// <summary>
/// �����Ϣ
/// </summary>
/// <returns></returns>
LPCSTR information() {
	/*��ʼ��Api,����ɾ��*/
	CreateApi();
	plugin_info info{};
	/*APPID, ���������ļ���һ��, ��չ�ļ���ӦΪ {appid}.AP.dll*/
	info.appid = "cn.tapdrd.demo";
	/*�������*/
	info.name = "ʾ�����";
	/*�汾���� �Ƽ�ʹ�� 1.0.0�����ĸ�ʽ*/
	info.version = "1.0.0";
	/*�汾�� ÿ���°汾��������+1*/
	info.h_version = 1;
	/*��������*/
	info.author = "����";
	/*�������*/
	info.show = "������д�������";
	/*������ϵ��ʽ*/
	info.contact = "10000";
	/*�������Ⱥ*/
	info.group = "10000";
	/*������־*/
	info.update_log = "���ǵ�һ����";
	/*�Ƿ��п���̨*/
	info.windows = false;

	return get_plugin_info(info);
};

/// <summary>
/// �������
/// </summary>
/// <param name="expandPath">[��չĿ¼]�ɽ�ini�ļ����ڴ˴�</param>
/// <param name="pluginPath">[���Ŀ¼]�����˵Ĳ��Ŀ¼</param>
/// <param name="robotID">[������QQ]��������Ȩ��֤</param>
/// <param name="dbHandle">[���ݿ���]SQLite3���ݿ�</param>
/// <param name="robotType">[����������]�� ����������()�ɻ�ȡ����������</param>
/// <param name="pluginType">[�������]0.��Ѱ� 1.�շѰ�</param>
/// <returns></returns>
int Initialization(LPCSTR expandPath, LPCSTR pluginPath, LPCSTR robotID, int dbHandle, int robotType, int pluginType) {
	return 0;
}

/// <summary>
/// ����ر�
/// </summary>
/// <returns></returns>
int Plug_in_exit()
{
	/*�˴���������˳�����
	����ʱ��/�߳�/�ڴ����Դ�ͷ�*/
	return 0;
}

/// <summary>
/// ���ݿ����ı�
/// </summary>
/// <param name="plugin_handle">[��չ]��չ���ݿ���</param>
/// <param name="data_handle">[���]������ݿ���</param>
/// <param name="config_handle">[ϵͳ]ϵͳ���ݿ���</param>
/// <returns></returns>
int Event_datahandle_change(int pluginHandle,int dataHandle,int configHandle){
	return 0;
}

/// <summary>
/// ��Ϣ�¼�
/// </summary>
/// <param name="type">1.˽�� 2.Ⱥ��</param>
/// <param name="user">��Դ�û�</param>
/// <param name="group">Ⱥ��/������</param>
/// <param name="msg">��Ϣ����</param>
/// <returns></returns>
int Event_accept(int type,LPCSTR user,LPCSTR group,LPCSTR msg){
	/*
	//����һ��ʾ��, �ᷢ�� ����+�û�����
	string s1(msg), s2("����");
	s2.append(s1);
	tq_SendMsg(type, user, group, s2.c_str());
	*/
	// �뷵�س��� message_Ignore �� message_Intercept
	return message_Intercept;
}
/// <summary>
/// ��ҳ������Ϣ
/// �ɲο��ĵ�:https://d.tapdrd.cn/web/norm/
/// </summary>
/// <param name="handle">�û����</param>
/// <param name="info"><�û��ύ����Ϣ/param>
/// <returns></returns>
int Event_Web_message(int handle, LPCSTR info) {
	return message_Ignore;
}
/// <summary>
/// �����Ϣ
/// </summary>
/// <param name="type">����</param>
/// <param name="msg">��Ϣ����,��ʽΪJson</param>
/// <returns></returns>
int Event_playuser_message(int type,LPCSTR msg)
{
	/*
	ע�⣺������ɾ����,������չ������ͬ��ɾ���������,�����������
	ע�⣺�뾡�촦����Ϣ,�����Ҫ�ϳ�ʱ��,�����߳������,������ܿ�������¼�
	�¼�˵��: �¼����ǲ����������,������չ��,��ʱ�޷������������Ч��
	��ϸ�ĵ���https://d.tapdrd.cn/plugin/user_msg/
	*/

	// Ŀǰֻ�ܷ���message_Ignore
	return message_Ignore;
}

/// <summary>
/// ��Ϣ�����¼�
///		�����滻���յ����ı�
/// </summary>
/// <param name="type">1.˽�� 2.Ⱥ��</param>
/// <param name="user">��Դ�û�</param>
/// <param name="group">Ⱥ��/������</param>
/// <param name="msg">��Ϣ����</param>
/// <returns></returns>
LPCSTR Event_get_message_manage(int type, LPCSTR user, LPCSTR group, LPCSTR msg) {
	/*
	���ؿ��ı�Ҳ����Ϊδ��������Ϣ
	���Ҫȡ������Ϣ����,�ɷ���ʹ�ó��� message_Ban
	*/
	return msg;
}
/// <summary>
/// ��Ϣ�����¼�
///		�����滻�Ӽ������͵��ı�
/// </summary>
/// <param name="type">1.˽�� 2.Ⱥ��</param>
/// <param name="user">��Դ�û�</param>
/// <param name="group">Ⱥ��/������</param>
/// <param name="msg">��Ϣ����</param>
/// <returns></returns>
LPCSTR Event_will_message_manage(int type, LPCSTR user, LPCSTR group, LPCSTR msg) {
	/*
	���ؿ��ı�Ҳ����Ϊδ��������Ϣ
	���Ҫȡ������Ϣ����,�ɷ���ʹ�ó��� message_Ban
	*/
	return msg;
}

/// <summary>
/// ��Ϸ�Զ��������޸�
/// </summary>
/// <param name="id">ʹ�ó��� ϵͳ����_</param>
/// <param name="old_command">�޸�ǰ������</param>
/// <param name="new_command">�޸ĺ������</param>
/// <returns></returns>
int Event_command_modify(int id,LPCSTR old_command,LPCSTR new_command)
{
	//���û��޸����Զ��������,����յ���Ϣ

	// Ŀǰ����ֻ����message_Ignore
	return message_Ignore;
}

/// <summary>
/// ����̨����
/// </summary>
/// <returns></returns>
int Event_Console()
{
	MessageBox(NULL, TEXT("������ǿ���̨�¼�"), TEXT("��Ϣ"), NULL);
	return 0;
}