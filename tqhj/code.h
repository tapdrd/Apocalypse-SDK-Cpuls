#pragma once
#include<algorithm>
#include<cstdlib>
#include <iostream>
using namespace std;
unsigned char ch2hex(char ch)
{
	static const char* hex = "0123456789ABCDEF";
	for (unsigned char i = 0; i != 16; ++i)
		if (ch == hex[i])
			return i;
	return 0;
}
/// <summary>
/// 16进制转字符串
/// </summary>
/// <param name="dest">储存字符串的</param>
/// <param name="src">要转的16进制</param>
/// <returns>字符串</returns>
/*
	使用示例
	char src[] = "7B0A09224150504944223A0922636E2E7461706472642E64656D6F222C0A0922D7F7D5DF223A0922D8FDC3FB222C0A0922CDD8D5B9C3FBB3C6223A0922CABEC0FDB2E5BCFE222C0A0922B2E5BCFEB0E6B1BE223A0922312E302E30222C0A0922B2E5BCFEB0E6B1BEBAC5223A09312C0A0922C1AACFB5B7BDCABD31223A09223130303030222C0A0922C1AACFB5B7BDCABD32223A09223130303030222C0A0922B4B0BFDA223A09302C0A0922BDE9C9DC223A0922D5E2C0EFCCEED0B4B2E5BCFEBDE9C9DC222C0A0922B8FCD0C2C8D5D6BE223A0922D5E2CAC7B5DAD2BBB0E6B2E5BCFE222C0A092253444B223A09372C0A0922C4A3BFE9223A0922332E302E30222C0A0922C4A3BFE9BAC5223A093330303030300A7D";
	char* dest = new char[strlen(src)]{ 0 };
	puts(hexToStr(dest, src));
	delete[] dest;
*/
LPCSTR hexToStr(char* dest, const char* src)
{
	int i = 0;
	int cnt = 0;
	unsigned char* d = (unsigned char*)dest;
	while (*src)
	{
		if (i & 1)
		{
			d[cnt++] |= ch2hex(*src);
		}
		else
		{
			d[cnt] = ch2hex(*src) << 4;
		}
		src++;
		i++;
	}
	return dest;
}
LPCSTR strToHex(const string& str)
{
	string ret;
	static const char* hex = "0123456789ABCDEF";
	for (int i = 0; i != str.size(); ++i)
	{
		ret.push_back(hex[(str[i] >> 4) & 0xf]);
		ret.push_back(hex[str[i] & 0xf]);
	}
	return _strdup(ret.c_str());;
}