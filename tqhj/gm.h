#pragma once
/*
	这是天启幻境II, 通用Api头文件
*/
#include "dll.h"

/// <summary>
/// 字符串转16进制
/// </summary>
/// <param name="str">要转换的字符串</param>
/// <returns></returns>
LPCSTR tq_StrToHex(LPCSTR str)
{
	return DllApi_StrToHex(str);
}
/// <summary>
/// 16进制字符串
/// </summary>
/// <param name="hex">要转换的16进制</param>
/// <returns></returns>
LPCSTR tq_HexToStr(LPCSTR hex)
{
	return DllApi_HexTostr(hex);
}
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
bool tq_SendMsg(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj)
{
	if (APPID == NULL || APPID == "")return false;
	if (msg == NULL || msg == "")return false;
	return DllApi_SendMsg(type, user, group, msg, from_type, from_obj, APPID) != 0;
}