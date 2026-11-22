#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG
#include <assert.h>     
#include<stdio.h>

char* my_strcpy(char* dst, const char* src)
{
	char* p = dst; 	/* 记住起点，最后要返回 */
	assert(dest != NULL);
	assert(src != NULL);
	while ((*p++ = *src++) != '\0')     /* 边搬边检查 */
		;
	return dst;
}
int main()
{
	char dst[] = "hello";
	char str[] = "world";
	char* s=my_strcpy(dst, str);
	printf("%s", s);
	return 0;
}