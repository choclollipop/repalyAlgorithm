/* 插入排序 */
#include <stdio.h>

#define BUFFER_SIZE    7

int main()
{
    int buffer[BUFFER_SIZE] = {24, 30, 5, 58, 12, 39, 35};
    /* 取最后一次移动的值的下标即插入位置 */
    int sub = 0;
    /* 取寻找到的应该重新排序的较小值 */
    int copy = 0;

    /* 外层循环需找出需要进行排序的数的下标 */
    for(int idx = 1; idx < BUFFER_SIZE; idx++)
    {
        sub = idx;
        copy = buffer[idx];
        /* 后面的值小于前面，则交换 */
        while (sub > 0 && copy < buffer[sub - 1])
        {
            buffer[sub] = buffer[sub - 1];
            sub--;
        }
        buffer[sub] = copy;
    }

    /* 打印数组 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("data:%d\t", buffer[idx]);
    }
    printf("\n");

    return 0;
}