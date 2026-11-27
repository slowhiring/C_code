#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int my_strcmp(const char* s1, const char* s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	unsigned char c1 = (unsigned char)*s1;
	unsigned char c2 = (unsigned char)*s2;

	return c1 - c2;
}

int main()
{
	char arr[] = "abc";
	char str[] = "abcdef";

	int pr = my_strcmp(arr, str);
	if (pr > 0)
		printf("大于\n");
	else if (pr == 0)
		printf("等于\n");
	else
		printf("小于\n");

	return 0;
}