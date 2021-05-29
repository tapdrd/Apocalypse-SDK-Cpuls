#pragma once
/*
	这是天启幻境II, 应用信息头文件
*/
#include "cJSON.h"
#include "dll.h"
struct plugin_info
{
	LPCSTR appid;	//需要与外部文件一致
	LPCSTR name;		//名称
	LPCSTR version;	//版本,用于外部显示
	int h_version;	//版本号,每次新版本请+1
	LPCSTR author;	//作者
	LPCSTR show;		//介绍
	LPCSTR contact;	//作者QQ
	LPCSTR group;//交流群
	LPCSTR update_log;//更新日志
	bool windows;// 是否有控制台
};
// 获取应用信息
LPCSTR get_plugin_info(plugin_info info)
{
	APPID = info.appid;
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "APPID", info.appid);
	cJSON_AddStringToObject(json, "作者", info.author);
	cJSON_AddStringToObject(json, "拓展名称", info.name);
	cJSON_AddStringToObject(json, "插件版本", info.version);

	cJSON_AddNumberToObject(json, "插件版本号", info.h_version);

	cJSON_AddStringToObject(json, "联系方式1", info.contact);
	cJSON_AddStringToObject(json, "联系方式2", info.group);

	cJSON_AddNumberToObject(json, "窗口", info.windows == true ? 1 : 0);

	cJSON_AddStringToObject(json, "介绍", info.show);
	cJSON_AddStringToObject(json, "更新日志", info.update_log);


	cJSON_AddNumberToObject(json, "SDK", 7);
	cJSON_AddStringToObject(json, "模块", "3.0.0");
	cJSON_AddNumberToObject(json, "模块号", 300000);

	char* ch = cJSON_Print(json);
	cJSON_Delete(json);
	return ch;
};