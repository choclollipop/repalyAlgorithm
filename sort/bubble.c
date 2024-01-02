/* 冒泡排序 */
#include <stdio.h>

#define BUFFER_SIZE     6

int printArray(int * array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }
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
    for (int idx = 0; idx < length - 1; idx++)
    {
        for (int pos = 0; pos < length - 1 - idx; pos++)
        {   
            /* 后面的数字小就交换 */
            if (array[pos] > array[pos + 1])
            {
                swap(&array[pos], &array[pos + 1]);
            }
        }
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