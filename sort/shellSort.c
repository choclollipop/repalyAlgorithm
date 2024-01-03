/* 希尔排序 */
#include <stdio.h>

int printArray(int * array, int arraySize)
{
    for(int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }

    return 0;
}

int shellSort(int * array, int length)
{
    int ret = 0;

    if(!array)
    {
        return -1;
    }

    /* 取分组间隔 */
    int spa = length;
    int sub = 0;
    int copy = 0;

    while(spa >= 1)
    {
        spa = spa / 2;
        /* 执行插入排序 */
        for (int idx = 0; idx < length; idx++)
        {
            sub = idx;
            copy = array[idx];

            while ((sub - spa) >= 0 && copy < array[sub - spa])
            {
                array[sub] = array[sub - spa];
                sub = sub - spa;
            }
            array[sub] = copy;
        }
    }
    
    return ret;
}

int main()
{
    int array[] = {89, 29, 30, 5, 99, 34, 12, 66};
    int len = sizeof(array) / sizeof(array[0]);
    printf("len : %d\n", len);

    shellSort(array, len);

    printf("len1 : %d\n", len);

    // len = sizeof(array) / sizeof(array[0]);
    for(int idx = 0; idx < 8; idx++)
    {
        printf("array[%d] : %d\n", idx, array[idx]);
    }


    return 0;
}