/* 选择排序 */
#include <stdio.h>

#define BUFFER_SIZE    7

int main()
{
    int buffer[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    int len = sizeof(buffer) / sizeof(buffer[0]);
    int min = 0;
    /* 寻找pos后最小值的下标 */
    int sub = 0;

    /* 外层循环，控制比较的位置 */
    for(int pos = 0; pos < len; pos++)
    {
        min = buffer[pos];
        sub = pos;
        /* 内层循环，寻找最小值 */
        for(int idx = pos + 1; idx < len; idx++)
        {
            if(buffer[idx] < min)
            {
                min = buffer[idx];
                /* 最小值的数据在数组中的下标 */
                sub = idx;
            }
        }
        /* 交换数据 */
        buffer[sub] = buffer[pos];
        buffer[pos] = min;
    }

    /* 打印排序后的数组 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("data:%d\t", buffer[idx]);
    }
    printf("\n");
    

    return 0;
}