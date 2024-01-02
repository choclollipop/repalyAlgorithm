#include <stdio.h>

int quickSort(int *array, int start, int end)
{
    if(!array)
    {
        return 0;
    }
    /* 保证开始位置比结束位置小时才可以进行排序 */
    if(start < end)
    {
        int base = array[start];
        int left = start;
        int right = end;

        while(left < right)
        {
            /* 除判断值以外，应该保证左边索引一定比右边小 */
            while(array[right] >= base && left < right)
            {
                right--;
            }
            array[left] = array[right];

            /* 循环则表示都比基准值小 */
            while(array[left] < base && left < right)
            {
                left++;
            }
            /* 此时跳出循环，表示找到比基准值大的数值 */
            array[right] = array[left];
        }

        /* 此时表示完成第一轮排序,将基准值填入最后一个位置 */
        array[left] = base;

        /* 递归分别对左右排序 */
        /* 对左边递归 */
        quickSort(array, start, left - 1);
        /* 对右边递归 */
        quickSort(array, left + 1, end);
    }

    return 0;
}

/* 打印函数 */
int printArray(int * array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }

    return 0;
}

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65, 7, 50, 108, 43, 25};
    int len = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, len - 1);
    printArray(array, len);

    return 0;
}