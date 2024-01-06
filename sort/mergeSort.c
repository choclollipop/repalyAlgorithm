/* 归并排序 */
#include <stdio.h>
#include <stdlib.h>

int printArray(int * array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }

    return 0;
}

/* 合并并排序 */
static int merge(int *array, int *pArray, int start, int end, int mid)
{
    /* 左右两边没有排序的第一个数据的位置 */
    int l_pos = start;
    int r_pos = mid + 1;
    /* 记录暂时存放排序后数据的临时数组下标 */
    int pos = start;

    /* 比较排序 */
    while (l_pos <= mid && r_pos <= end)
    {
        if (array[l_pos] < array[r_pos])
        {
            pArray[pos++] = array[l_pos++];
        }
        else
        {
            pArray[pos++] = array[r_pos++];
        }
    }

    /* 左半边有剩余，直接放在临时数组中 */
    while (l_pos <= mid)
    {
        pArray[pos++] = array[l_pos++];
    }

    /* 右半边有剩余 */
    while (r_pos <= end)
    {
        pArray[pos++] = array[r_pos++];
    }

    /* 复制会原来的数组 */
    while (start <= end)
    {
        array[start] = pArray[start];
        start++;
    }

    return 0;
}

/* 分组 */
static int group(int *array, int *pArray, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;
        /* 对左边进行分组 */
        group(array, pArray, 0, mid);
        /* 对右边进行分组 */
        group(array, pArray, mid + 1, end);
        merge(array, pArray, start, end, mid);
    }

    return 0;
}

int mergeSort(int *array, int length)
{
    int * pArray = (int *)malloc(sizeof(int) * length);
    int pos = 0;
    if (pArray)
    {
        /* 分组排序 */
        group(array, pArray, 0, length - 1);
        
        free(pArray);
        pArray = NULL;
    }
    else
    {
        return -1;
    }
    
    return 0;
}

int main()
{
    int array[] = {30, 45, 67, 89, 1, 2, 6, 10, 25};
    int len = sizeof(array) / sizeof(array[0]);

    mergeSort(array, len);

    printArray(array, len);
    
    return 0;
}