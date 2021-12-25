#include "pch.h"

#include "api_Main.h"

#include "code.h"
#include "cJSON.h"

#include <stdlib.h>
#include <string>
using namespace std;

/// <summary>
/// 插件信息
/// </summary>
/// <returns></returns>
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

	return get_plugin_info(info);
};

/// <summary>
/// 插件启动
/// </summary>
/// <param name="expandPath">[拓展目录]可将ini文件放在此处</param>
/// <param name="pluginPath">[插件目录]机器人的插件目录</param>
/// <param name="robotID">[机器人QQ]可用作授权验证</param>
/// <param name="dbHandle">[数据库句柄]SQLite3数据库</param>
/// <param name="robotType">[机器人类型]用 机器人类型()可获取机器人名称</param>
/// <param name="pluginType">[插件类型]0.免费版 1.收费版</param>
/// <returns></returns>
int Initialization(LPCSTR expandPath, LPCSTR pluginPath, LPCSTR robotID, int dbHandle, int robotType, int pluginType) {
	return 0;
}

/// <summary>
/// 插件关闭
/// </summary>
/// <returns></returns>
int Plug_in_exit()
{
	/*此处可做插件退出处理
	例如时钟/线程/内存等资源释放*/
	return 0;
}

/// <summary>
/// 数据库句柄改变
/// </summary>
/// <param name="plugin_handle">[拓展]拓展数据库句柄</param>
/// <param name="data_handle">[玩家]玩家数据库句柄</param>
/// <param name="config_handle">[系统]系统数据库句柄</param>
/// <returns></returns>
int Event_datahandle_change(int pluginHandle,int dataHandle,int configHandle){
	return 0;
}

/// <summary>
/// 消息事件
/// </summary>
/// <param name="type">1.私聊 2.群聊</param>
/// <param name="user">来源用户</param>
/// <param name="group">群组/讨论组</param>
/// <param name="msg">消息内容</param>
/// <returns></returns>
int Event_accept(int type,LPCSTR user,LPCSTR group,LPCSTR msg){
	/*
	//这是一个示例, 会发送 复读+用户内容
	string s1(msg), s2("复读");
	s2.append(s1);
	tq_SendMsg(type, user, group, s2.c_str());
	*/
	// 请返回常量 message_Ignore 或 message_Intercept
	return message_Intercept;
}
/// <summary>
/// 网页请求消息
/// 可参考文档:https://d.tapdrd.cn/web/norm/
/// </summary>
/// <param name="handle">用户句柄</param>
/// <param name="info"><用户提交的消息/param>
/// <returns></returns>
int Event_Web_message(int handle, LPCSTR info) {
	return message_Ignore;
}
/// <summary>
/// 玩家消息
/// </summary>
/// <param name="type">类型</param>
/// <param name="msg">消息内容,格式为Json</param>
/// <returns></returns>
int Event_playuser_message(int type,LPCSTR msg)
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

/// <summary>
/// 消息接收事件
///		用于替换接收到的文本
/// </summary>
/// <param name="type">1.私聊 2.群聊</param>
/// <param name="user">来源用户</param>
/// <param name="group">群组/讨论组</param>
/// <param name="msg">消息内容</param>
/// <returns></returns>
LPCSTR Event_get_message_manage(int type, LPCSTR user, LPCSTR group, LPCSTR msg) {
	/*
	返回空文本也将视为未处理发送消息
	如果要取消此消息发送,可返回使用常量 message_Ban
	*/
	return msg;
}
/// <summary>
/// 消息发送事件
///		用于替换接即将发送的文本
/// </summary>
/// <param name="type">1.私聊 2.群聊</param>
/// <param name="user">来源用户</param>
/// <param name="group">群组/讨论组</param>
/// <param name="msg">消息内容</param>
/// <returns></returns>
LPCSTR Event_will_message_manage(int type, LPCSTR user, LPCSTR group, LPCSTR msg) {
	/*
	返回空文本也将视为未处理发送消息
	如果要取消此消息发送,可返回使用常量 message_Ban
	*/
	return msg;
}

/// <summary>
/// 游戏自定义命令修改
/// </summary>
/// <param name="id">使用常量 系统命令_</param>
/// <param name="old_command">修改前的命令</param>
/// <param name="new_command">修改后的命令</param>
/// <returns></returns>
int Event_command_modify(int id,LPCSTR old_command,LPCSTR new_command)
{
	//当用户修改了自定义命令后,会接收到消息

	// 目前返回只能是message_Ignore
	return message_Ignore;
}

/// <summary>
/// 控制台窗口
/// </summary>
/// <returns></returns>
int Event_Console()
{
	MessageBox(NULL, TEXT("你好这是控制台事件"), TEXT("信息"), NULL);
	return 0;
}