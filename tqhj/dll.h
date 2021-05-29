#pragma once
/*
	这是天启幻境II, DLL函数头文件
*/
typedef LPCSTR(WINAPI* Api_StrToHex)(LPCSTR str);
typedef LPCSTR(WINAPI* Api_HexToStr)(LPCSTR Hex);
typedef LPCSTR(WINAPI* Api_RobotType)(int type);
typedef int(WINAPI* Api_DataHandle)(int type);
typedef int(WINAPI* Api_SendMsg)(int type, LPCSTR user, LPCSTR group, LPCSTR msg, int from_type, LPCSTR from_obj, LPCSTR APPID);

Api_StrToHex  DllApi_StrToHex;	//	字符串转16进制
Api_HexToStr  DllApi_HexTostr;	//	16进制转字符串
Api_RobotType DllApi_RobotType;	//	获取机器人类型
Api_DataHandle DllApi_DataHandle;// 数据库句柄
Api_SendMsg DllApi_SendMsg;		// 发送消息