#include "pch.h"

#include "api_Main.h"

#include "code.h"
#include "cJSON.h"

#include <stdlib.h>
#include <string>
using namespace std;

// �����ʼ����Ϣ
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

	return strToHex(get_plugin_info(info));
};

// ��������¼�
int Initialization(
	LPCSTR file_exp,	//[��չĿ¼]�ɽ�ini�ļ����ڴ˴�
	LPCSTR file_plugin,	//[���Ŀ¼]�����˵Ĳ��Ŀ¼
	LPCSTR qq_robot,	//[������QQ]��������Ȩ��֤
	int db_handle,		//[���ݿ���]SQLite3���ݿ�
	int type_robot,		//[����������]�� tq_GetRobotName()�ɻ�ȡ����������
	int plugin_charge	//[�������]0.��Ѱ� 1.�շѰ�
) {
	return 0;
}

// ����ر��¼�
int Plug_in_exit()
{
	/*�˴���������˳�����
	����ʱ��/�߳�/�ڴ����Դ�ͷ�*/

	return 0;
}

// ���ݿ����ı���Ϣ
int Event_datahandle_change(
	int plugin_handle,	//[��չ]��չ���ݿ���
	int data_handle,	//[���]������ݿ���
	int config_handle	//[ϵͳ]ϵͳ���ݿ���
)
{
	return 0;
}

// ��Ϣ�¼�
int Event_accept(
	int type,		//1.˽�� 2.Ⱥ��
	LPCSTR user,	//��Դ�û�
	LPCSTR group,	//Ⱥ��/������
	LPCSTR msg,		//��Ϣ����
	int from_type,	//��Դ����
	LPCSTR from_obj	//��Դ����
)
{

	/*
	����һ��ʾ��, �ᷢ�� ����+�û�����
	string s1(msg), s2("����");
	s2.append(s1);
	tq_SendMsg(type, user, group, s2.c_str(), from_type, from_obj);
	*/
	tq_SendLog(msg);
	LPCSTR ret = "hgksjafhs";
	if (tq_SystemCheck(0, type, user, group, ret) == true)
		tq_SendMsg(type, user, group, from_type, from_obj, "1");
	else
		tq_SendMsg(type, user, group, from_type, from_obj, "2");

	tq_SendMsg(type, user, group, from_type, from_obj, ret);
	// �뷵�س��� message_Ignore �� message_Intercept
	return message_Intercept;
}

// �����Ϣ�¼�
int Event_playuser_message(
	int type,		//����
	LPCSTR msg		//�˴�������JSON��Ϣ
)
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

// ��Ϣ�����¼� [�ɸı���ҷ��͵���Ϣ����]
LPCSTR Event_get_message_manage(
	int type,		//1.˽�� 2.Ⱥ��
	LPCSTR user,	//��Դ�û�
	LPCSTR group,	//Ⱥ��/������
	LPCSTR msg,		//��Ϣ����
	int from_type,	//��Դ����
	LPCSTR from_obj	//��Դ����
)
{
	//���¼��ɶԲ�����յ�����Ϣ���д���


	/*
	���ؿ��ı�Ҳ����Ϊδ��������Ϣ
	���Ҫȡ������Ϣ����,�ɷ���ʹ�ó��� message_Ban
	*/
	return msg;
}
// ��Ϣ�����¼� [�ɸı�����˷��͵���Ϣ����]
LPCSTR Event_will_message_manage(
	int type,		//1.˽�� 2.Ⱥ��
	LPCSTR user,	//��Դ�û�
	LPCSTR group,	//Ⱥ��/������
	LPCSTR msg,		//��Ϣ����
	int from_type,	//��Դ����
	LPCSTR from_obj	//��Դ����
)
{
	//���¼��ɶԲ�����͵�����Ϣ���д���


	/*
	���ؿ��ı�Ҳ����Ϊδ��������Ϣ
	���Ҫȡ������Ϣ����,�ɷ���ʹ�ó��� message_Ban
	*/
	return msg;
}

// ��Ϸ�Զ��������޸��¼�
int Event_command_modify()
{
	//���û��޸����Զ��������,����յ���Ϣ

	// Ŀǰ����ֻ����message_Ignore
	return message_Ignore;
}

// �������̨
int Event_Console()
{
	MessageBox(NULL, TEXT("������ǿ���̨�¼�"), TEXT("��Ϣ"), NULL);
	return 0;
}