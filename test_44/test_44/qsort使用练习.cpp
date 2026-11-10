#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int compar_int(const void *a, const void *b)
{
	return(*((int*)a) > *((int*)b)) - (*((int*)a) < *((int*)b));
}
int main()
{
	int arr[5] = { 5, 2, 3, 1, 4 };
	int sz = sizeof(arr[0]);
	qsort(arr,5,sz,compar_int);
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

int compar_char_1(const void* a, const void* b)
{
	return (*((char*)a) > *((char*)b)) - (*((char*)a) < *((char*)b));
}
int main()
{
	char arr[5] = { 'd', 's', 'a', 'v', 'e' };
	int sz = sizeof(arr[0]);
	qsort(arr, 5, sz, compar_char_1);
	for (int i = 0;i < 5;i++)
	{
		printf("%c ", arr[i]);
	}
	return 0;
}

int compar_char_2(const void* a, const void* b)
{
	return strcmp(*(const char**)a, *(const char**)b);
}
int main()
{
	const char* names[] = { "Zoe", "apple", "Bob", "cat" };
	int sz = sizeof(names[0]);
	qsort(names, 4, sz, compar_char_2);
	for (int i = 0;i < 4;i++)
	{
		printf("%s ", names[i]);
	}
	return 0;
}


#include <ctype.h>

#define ROWS 6
#define COLS 16

/* 打印整张表：一次一行，用 %s 而不是一个字符一个字符地打 */
void print_all(char words[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("  %s\n", words[i]);
	}
}

/* 【第1问】区分大小写：本行就是一个字符串，直接一级指针接住 */
int cmp_ascii(const void* a, const void* b)
{
	return strcmp((const char*)a, (const char*)b);
}

/* 【第2问】忽略大小写：自己手写 strcmp 的“不分大小写版” */
int cmp_nocase(const void* a, const void* b)
{
	const char* x = (const char*)a;
	const char* y = (const char*)b;
	while (*x != '\0' && *y != '\0')
	{
		int cx = tolower((unsigned char)*x);
		int cy = tolower((unsigned char)*y);
		if (cx != cy)
			return cx - cy;
		x++;
		y++;
	}
	return (int)(unsigned char)*x - (int)(unsigned char)*y;
}

/* 【第3问】先比长度，长度相同再比字典序 */
int cmp_len(const void* a, const void* b)
{
	const char* x = (const char*)a;
	const char* y = (const char*)b;
	int lx = (int)strlen(x);
	int ly = (int)strlen(y);
	if (lx != ly)
		return lx - ly;
	return strcmp(x, y);
}

int main(void)
{
	char words[ROWS][COLS] = {
		"pear",
		"Apple",
		"banana",
		"apricot",
		"Cherry",
		"date"
	};

	/* 元素个数 = 总字节 / 一行字节；每行字节数 = sizeof(words[0]) = 16 */
	int rows = (int)(sizeof(words) / sizeof(words[0]));
	int size = (int)sizeof(words[0]);

	printf("=== 原始数据 ===\n");
	print_all(words, rows);

	qsort(words, rows, size, cmp_ascii);
	printf("\n=== 1. 区分大小写（机器字典序） ===\n");
	print_all(words, rows);

	qsort(words, rows, size, cmp_nocase);
	printf("\n=== 2. 忽略大小写（人的字典序） ===\n");
	print_all(words, rows);

	qsort(words, rows, size, cmp_len);
	printf("\n=== 3. 按长度，同长比字典序 ===\n");
	print_all(words, rows);

	return 0;
}