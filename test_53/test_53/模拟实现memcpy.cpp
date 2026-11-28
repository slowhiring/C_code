#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest&&src);
	void* ret = dest;
	char* d = (char*)dest;
	const char* s = (const char*)src;//养成习惯：源指针转换时把 const 一起带上
	while (num--)
	{
		*d = *s;
		d++;
		s++;
	}
	return ret;
}
int main(void)
{
	char src[] = "abc-----";
	char dest[] = "deffjkd";
	int a[] = { 1,2,3,4,5,6,7,8 };
	int b[] = { 0,0,0,0,0,0 };
	/*memcpy(dest, src, 5);
	memcpy(a, b, 5);*/
	my_memcpy(dest, src, 5);
	my_memcpy(a, b, 5);
	printf("%s\n", dest);
	for (int i = 0;i < 5;i++)
	{
		printf("%d\n", a[i]);
	}
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//         预期：12123458910
	my_memcpy(arr + 2, arr, 5 * sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}