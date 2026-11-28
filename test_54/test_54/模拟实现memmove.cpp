#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>

void* my_memmove(void* dest, const void* src, size_t n)
{
	assert(dest != NULL && src != NULL);
	unsigned char* d = (unsigned char*)dest;
	const unsigned char* s = (const unsigned char*)src;

	if (d < s)
	{
		// 目标在源前面:从前往后拷,源数据不会被提前覆盖
		for (size_t i = 0; i < n; i++)
			d[i] = s[i];
	}
	else if (d > s)
	{
		// 目标在源后面:从后往前拷
		while (n--)
			d[n] = s[n];
	}
	// d == s 时什么都不用做
	return dest;
}

void print(const int* a, size_t num)
{
	for (size_t i = 0; i < num; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	size_t sz = sizeof(arr1) / sizeof(arr1[0]);

	my_memmove(arr1 + 2, arr1, 5 * sizeof(int));
	print(arr1, sz);    // 1 2 1 2 3 4 5 8 9 10

	my_memmove(arr2, arr2 + 2, 5 * sizeof(int));
	print(arr2, sz);    // 3 4 5 6 7 6 7 8 9 10

	return 0;
}