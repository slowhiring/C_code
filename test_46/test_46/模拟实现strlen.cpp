#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int my_strlen(char*str)
{
	int count = 0;
	while (*str != '\0') {
		++count;
		++str;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef\0fg";
	int length=my_strlen(arr);
	printf("%d", length);
	return 0;
}