#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//#include<string.h>

char* my_strcat(char*s1,const char*s2)
{
	char* start = s1;
	while (*s1 != '\0')
	{
		s1++;
	}
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';//²¹³äÒ»¸öÄ©Î²
	return start;
}
int main()
{
	char str[10] = "abc";
	char arr[] = "def";
	char*pr=my_strcat(str, arr);
	printf("%s\n",pr);
	return 0;
}