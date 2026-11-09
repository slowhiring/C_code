#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char killer;

    /* 依次假设凶手是 A、B、C、D */
    for (killer = 'A'; killer <= 'D'; killer++)
    {
        /* 四个人各自的供词：真为 1，假为 0 */
        int a = (killer != 'A');   /* A 说：不是我        —— 凶手不是 A 就是真话 */
        int b = (killer == 'C');   /* B 说：是 C          —— 凶手是 C 才是真话   */
        int c = (killer == 'D');   /* C 说：是 D          —— 凶手是 D 才是真话   */
        int d = !c;                /* D 说：C 在胡说      —— C 假则 D 真         */

        /* 真话记 1、假话记 0，直接加起来就是真话的句数 */
        int true_count = a + b + c + d;

//#ifdef SHOW_ALL
//        printf("假设凶手是 %c：A=%d B=%d C=%d D=%d  真话 %d 句\n",
//            killer, a, b, c, d, true_count);
//#endif

        /* 题目说：3 个人说真话，1 个人说假话 */
        if (true_count == 3)
        {
            printf("凶手是：%c\n", killer);
        }
    }

    return 0;
}