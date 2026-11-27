#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strstr(const char* str, const char* sub)
{
	assert(str && sub);// 空指针直接炸出来，比默默崩溃好排查
	// 特殊情况:子串是空串 ↓ 标准规定直接返回 str
	if (*sub == '\0')
		return (char*)str;

	const char* s = str;
	while (*s != '\0')
	{
		const char* p1 = s;
		const char* p2 = sub;

		while (*p1==*p2&&*p1!='\0'&&*p2!='\0')
		{
			p1++;
			p2++;
		}

		if (*p2=='\0')
			return (char*)s;

		s++;
	}
	return NULL;
}
int main()
{
	char str[] = "hello world";
	char arr[] = "world";
	//char*p=strstr(str, arr);
	char* p = my_strstr(str, arr);
	if (p != NULL)
	{
		printf("%s\n", p);
	}
	else
	{
		printf("没找到");
	}
	return 0;
}