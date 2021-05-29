#include "pch.h"

#include "api_Main.h"

#include "code.h"
#include "cJSON.h"

#include <stdlib.h>
#include <string>
using namespace std;

// 插件初始化信息
LPCSTR information() {
	/*初始化Api,请勿删除*/
	CreateApi();
	plugin_info info{};

	/*APPID, 需与编译后文件名一致, 拓展文件名应为 {appid}.AP.dll*/
	info.appid = "cn.tapdrd.demo";
	/*插件名称*/
	info.name = "示例插件";
	/*版本名称 推荐使用 1.0.0这样的格式*/
	info.version = "1.0.0";
	/*版本号 每次新版本发布后请+1*/
	info.h_version = 1;
	/*作者名称*/
	info.author = "佚名";
	/*插件介绍*/
	info.show = "这里填写插件介绍";
	/*作者联系方式*/
	info.contact = "10000";
	/*插件交流群*/
	info.group = "10000";
	/*更新日志*/
	info.update_log = "这是第一版插件";
	/*是否有控制台*/
	info.windows = false;

	return strToHex(get_plugin_info(info));
};

// 插件启动事件
int Initialization(
	LPCSTR file_exp,	//[拓展目录]可将ini文件放在此处
	LPCSTR file_plugin,	//[插件目录]机器人的插件目录
	LPCSTR qq_robot,	//[机器人QQ]可用作授权验证
	int db_handle,		//[数据库句柄]SQLite3数据库
	int type_robot,		//[机器人类型]用 tq_GetRobotName()可获取机器人名称
	int plugin_charge	//[插件类型]0.免费版 1.收费版
) {
	return 0;
}

// 插件关闭事件
int Plug_in_exit()
{
	/*此处可做插件退出处理
	例如时钟/线程/内存等资源释放*/

	return 0;
}

// 数据库句柄改变消息
int Event_datahandle_change(
	int plugin_handle,	//[拓展]拓展数据库句柄
	int data_handle,	//[玩家]玩家数据库句柄
	int config_handle	//[系统]系统数据库句柄
)
{
	return 0;
}

// 消息事件
int Event_accept(
	int type,		//1.私聊 2.群聊
	LPCSTR user,	//来源用户
	LPCSTR group,	//群组/讨论组
	LPCSTR msg,		//消息内容
	int from_type,	//来源类型
	LPCSTR from_obj	//来源对象
)
{

	/*
	这是一个示例, 会发送 复读+用户内容
	string s1(msg), s2("复读");
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
	// 请返回常量 message_Ignore 或 message_Intercept
	return message_Intercept;
}

// 玩家消息事件
int Event_playuser_message(
	int type,		//类型
	LPCSTR msg		//此处将传入JSON信息
)
{
	/*
	注意：如果玩家删号了,请在拓展数据中同步删除玩家数据,以免出现问题
	注意：请尽快处理消息,如果需要较长时间,请在线程中完成,否则可能卡主插件事件
	事件说明: 事件均是插件处理完了,传入拓展的,暂时无法代替插件自身的效果
	详细文档：https://d.tapdrd.cn/plugin/user_msg/
	*/

	// 目前只能返回message_Ignore
	return message_Ignore;
}

// 消息接收事件 [可改变玩家发送的消息内容]
LPCSTR Event_get_message_manage(
	int type,		//1.私聊 2.群聊
	LPCSTR user,	//来源用户
	LPCSTR group,	//群组/讨论组
	LPCSTR msg,		//消息内容
	int from_type,	//来源类型
	LPCSTR from_obj	//来源对象
)
{
	//此事件可对插件接收到的消息进行处理


	/*
	返回空文本也将视为未处理发送消息
	如果要取消此消息发送,可返回使用常量 message_Ban
	*/
	return msg;
}
// 消息发送事件 [可改变机器人发送的消息内容]
LPCSTR Event_will_message_manage(
	int type,		//1.私聊 2.群聊
	LPCSTR user,	//来源用户
	LPCSTR group,	//群组/讨论组
	LPCSTR msg,		//消息内容
	int from_type,	//来源类型
	LPCSTR from_obj	//来源对象
)
{
	//此事件可对插件发送到的消息进行处理


	/*
	返回空文本也将视为未处理发送消息
	如果要取消此消息发送,可返回使用常量 message_Ban
	*/
	return msg;
}

// 游戏自定义命令修改事件
int Event_command_modify()
{
	//当用户修改了自定义命令后,会接收到消息

	// 目前返回只能是message_Ignore
	return message_Ignore;
}

// 插件控制台
int Event_Console()
{
	MessageBox(NULL, TEXT("你好这是控制台事件"), TEXT("信息"), NULL);
	return 0;
}