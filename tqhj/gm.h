#pragma once
/*
	这是天启幻境II, 通用Api头文件
*/
#include "dll.h"
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// <summary>
/// 获取机器人名称
/// </summary>
/// <param name="type">传入机器人类型</param>
/// <returns></returns>
LPCSTR tq_GetRobotName(int type)
{
	return DllApi_RobotType(type);
}
/// <summary>
/// 发送Web消息
/// </summary>
/// <param name="handle">用户句柄</param>
/// <param name="sendJson">要发送的Json, 此Json 会包含在 info这个key内发送至网页端</param>
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
/// 获取数据库句柄
/// </summary>
/// <param name="type">可使用常量get_DBHandle_xx</param>
/// <returns>数据库句柄</returns>
int tq_GetDBHandle(int type)
{
	return DllApi_DataHandle(type);
}
/// <summary>
/// 发送消息
/// </summary>
/// <param name="type">1.私聊 2.群聊</param>
/// <param name="user">来源用户</param>
/// <param name="group">群组/讨论组</param>
/// <param name="msg">消息内容</param>
/// <param name="from_type">来源类型</param>
/// <param name="from_obj">来源对象</param>
/// <returns>是否发送成功</returns>
bool tq_SendMsg(int type, LPCSTR user, LPCSTR group,LPCSTR msg)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendMsg(type, user, group, msg, APPID) != 0;
}
/// <summary>
/// 发送全服消息
/// </summary>
/// <param name="msg">要发送的内容</param>
/// <returns></returns>
bool tq_SendAllMsg(LPCSTR msg)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendAllMsg(2, 0, msg) != 0;
}
/// <summary>
/// 系统检查
/// </summary>
/// <param name="type">-1注册状态可用 0一般状态 1死亡时允许操作 </param>
/// <param name="sub_type">发送消息类</param>
/// <param name="user">用户</param>
/// <param name="group">群组</param>
/// <param name="message">这里是返回的消息拦截(无拦截返回空)</param>
/// <returns>全命令的检查[返回真,说明不允许往下执行,此时请看message返回]</returns>
bool tq_SystemCheck(int type, int sub_type, LPCSTR user, LPCSTR group, LPCSTR& message)
{
	LPCSTR ret;
	ret = DllApi_SystemCheck(type, sub_type, user, group);
	if (ret == NULL)ret = "连接失败";
	else if (strcmp(ret, "封号") == 0)ret = "账号已被封禁";
	message = ret;
	return strcmp(message, "") != 0;
}
/// <summary>
/// 发送调试日志 [需要控制台开启调试模式]
/// </summary>
/// <param name="log">内容</param>
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
/// 发送普通日志
/// </summary>
/// <param name="log">内容</param>
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
/// 写配置项 [直接写入天启拓展数据库内SQLite3储存]
/// </summary>
/// <param name="file">可以认为是ini的文件名称,文件名禁止为'cc.tapdrd.apocalypse',此文件将用于与主程序互动(玩家属性),如果为空或null,则是删除整个拓展数据</param>
/// <param name="sec">配置节[指定],如果为空或null,则是删除整个标示</param>
/// <param name="key">配置项[指定],如果为空或null,则是删除整个配置节</param>
/// <param name="value">如果填写为空则删除,如果不为空,存在则修改,不存在则添加 判断要求:type,服务器,配置节,配置项</param>
/// <returns>操作失败返回假,成功返回真</returns>
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
/// 读配置项 [直接从天启拓展数据库内SQLite3读取]
/// </summary>
/// <param name="file">可以认为是ini的文件名称,文件名禁止为'cc.tapdrd.apocalypse',此文件将用于与主程序互动(玩家属性),如果为空或null,则是删除整个拓展数据</param>
/// <param name="sec">配置节</param>
/// <param name="key">配置项</param>
/// <returns>操作失败返回空</returns>
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
/// 取配置节数
/// </summary>
/// <param name="file"></param>
/// <returns>返回数量</returns>
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
/// 取配置项数
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <returns>返回数量</returns>
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
/// 取配置节名, 如果只想取数量,请使用 tq_GetProfileSecNumber
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <returns>返回配置节名,一行一个</returns>
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
/// 取配置项名, 如果只想取数量,请使用 tq_GetProfileKeyNumber
/// </summary>
/// <param name="file"></param>
/// <param name="sec"></param>
/// <param name="key"></param>
/// <returns>返回配置项名,一行一个</returns>
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
/// 获取插件版本
/// </summary>
/// <returns>例如 3.0.3</returns>
LPCSTR tq_GetPluginVersion()
{
	return DllApi_CallPluginVersion(1);
}
/// <summary>
/// 操作全局变量
/// </summary>
/// <param name="user">玩家,无玩家填写空</param>
/// <param name="msg">消息内容</param>
/// <returns>返回替换后的问题(可让拓展支持天启全局变量)</returns>
LPCSTR tq_MessageVariableProcessing(LPCSTR user, LPCSTR msg)
{
	return DllApi_MessageVariableProcessing(user, msg);
}
/// <summary>
/// 获取插件版本号
/// </summary>
/// <returns>返回的值例如:300300</returns>
int tq_GerPluginVersionNumber()
{
	return atoi(DllApi_CallPluginVersion(2));
}
/// <summary>
/// 返回自定义后的系统命令
/// </summary>
/// <param name="command">请用常量 #系统命令_</param>
/// <returns></returns>
LPCSTR tq_GetCommandMsg(int command)
{
	return DllApi_CallCommandMsg(command);
}