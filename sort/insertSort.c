#include <stdio.h>

#define BUFFER_SIZE    6

int main()
{
    int buffer[BUFFER_SIZE] = {24, 30, 5, 58, 12, 39};
    /* 取最后一次移动的值的下标即插入位置 */
    int sub = 0;
    /* 取寻找到的应该重新排序的较小值 */
    int copy = 0;

    /* 外层循环需找出需要进行排序的数的下标 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        if(buffer[idx] > buffer[idx + 1])
        {
            copy = buffer[idx + 1];
            /* 此时的 [idx + 1] 的数据就是小与前面数据的位置 */
            for(int pos = idx + 1; pos >= 0; pos--)
            {
                if(copy < buffer[pos - 1])
                {
                    buffer[pos] = buffer[pos - 1];
                    /* 插入位置 */
                    sub = pos - 1;
                }
            }
            /* 将此时寻找到的小的数据插入到后移之后的插入位置 */
            buffer[sub] = copy;
        }
    }

    /* 打印数组 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("data:%d\t", buffer[idx]);
    }
    printf("\n");

    return 0;
}