#pragma once
/*
	这是天启幻境II, DLL函数头文件
*/
typedef LPCSTR(WINAPI* Api_StrToHex)(LPCSTR str);
typedef LPCSTR(WINAPI* Api_HexToStr)(LPCSTR Hex);
typedef LPCSTR(WINAPI* Api_RobotType)(int type);
typedef int(WINAPI* Api_DataHandle)(int type);
typedef int(WINAPI* Api_SendMsg)(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj, LPCSTR APPID);
typedef int(WINAPI* Api_SendAllMsg)(int type, LPCSTR group, LPCSTR msg);
typedef LPCSTR(WINAPI* Api_SystemCheck)(int type, int sub_type, LPCSTR user, LPCSTR group);
typedef LPCSTR(WINAPI* Api_SendEvent)(int type, LPCSTR log);
typedef LPCSTR(WINAPI* Api_CallPluginDataOperate)(LPCSTR json);
typedef LPCSTR(WINAPI* Api_CallPluginDataGet)(LPCSTR json);
typedef LPCSTR(WINAPI* Api_CallPluginVersion)(int type);
typedef LPCSTR(WINAPI* Api_MessageVariableProcessing)(LPCSTR user, LPCSTR msg);
typedef LPCSTR(WINAPI* Api_CallCommandMsg)(int command);

Api_StrToHex  DllApi_StrToHex;	//	字符串转16进制
Api_HexToStr  DllApi_HexTostr;	//	16进制转字符串
Api_RobotType DllApi_RobotType;	//	获取机器人类型
Api_DataHandle DllApi_DataHandle;// 数据库句柄
Api_SendMsg DllApi_SendMsg;		// 发送消息
Api_SendAllMsg DllApi_SendAllMsg;		// 全服消息
Api_SystemCheck DllApi_SystemCheck;		// 系统检查
Api_SendEvent DllApi_SendEvent;		// 发送事件
Api_CallPluginDataOperate DllApi_CallPluginDataOperate;	// 拓展数据库操作
Api_CallPluginDataGet DllApi_CallPluginDataGet;			// 拓展数据库读取
Api_CallPluginVersion DllApi_CallPluginVersion;			// 读取插件版本
Api_MessageVariableProcessing DllApi_MessageVariableProcessing;	// 消息变量处理
Api_CallCommandMsg DllApi_CallCommandMsg;	// 获取系统命令