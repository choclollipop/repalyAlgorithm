/* 冒泡排序 */
#include <stdio.h>

#define BUFFER_SIZE     6

int printArray(int * array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }

    return 0;
}

int swap(int * val1, int * val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;

    return 0;
}

void bubbleSort(int * array, int length)
{
    /* 寻找已经排好序的数据在数组中的位置 */
    int sortedIndex = 1;
    for (int end = length; end > 0; end--)
    {
        sortedIndex = 1;
        for (int pos = 1; pos < end; pos++)
        {   
            /* 后面的数字小就交换 */
            if (array[pos] < array[pos - 1])
            {
                swap(&array[pos], &array[pos - 1]);
                /* 取最后一次交换的数据在数组中的位置，可以避免后续排好序的值再重复遍历 */
                sortedIndex = pos;
            }
        }
        /* 将排序结束位置更新 */
        end = sortedIndex;
    }
}

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65};
    int tmp = 0;
    int len = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, len);

    /* 打印数组 */
    printArray(array, len);

    return 0;
}