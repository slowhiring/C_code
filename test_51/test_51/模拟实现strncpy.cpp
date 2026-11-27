#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>

#include <assert.h>

char* my_strncpy(char* dest, const char* src, size_t n)//size_t比int好，记得给只读指针加const
{
    assert(dest && src);//养成用assert断言的习惯
    char* start = dest;          // 记住起点，最后返回它

    size_t i = 0;
    // 阶段1：搬字符，遇到 src 的 '\0' 或名额用完就停
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    // 阶段2：名额没用完 = src 提前结束，剩下的全填 '\0'
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return start;
}
int main(void)
{
	char arr[10] = { 0 };
	char str[] = "hello";
	//char* pr = strncpy(arr, str, 6);
	char* pr = my_strncpy(arr, str, 6);
	printf("%s\n", pr);
	return 0;
}