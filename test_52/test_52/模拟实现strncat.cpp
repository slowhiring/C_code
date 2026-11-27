#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* s1, const char* s2, size_t n)
{
	assert(s1 && s2);
	char* start = s1;
	size_t i = 0;
	while (*s1 != '\0')
	{
		s1++;
	}
	while (i < n&& *s2 != '\0')//*s2 != '\0'最多追加 n 个字符，而且遇到源串的 '\0' 就停
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';//记得补上'/0'
	return start;
}
int main(void)
{
	char arr[20] = "abc\0fjdk";
	char str[] = "def";
	//char* pr = strncat(arr, str,2);
	char* pr = my_strncat(arr, str, 4);
	printf("%s\n", pr);
	return 0;
}