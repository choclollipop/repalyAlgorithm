/* 二分查找 */
#include <stdio.h>

static int binarySearch(int * array, int length, int target, int start, int end)
{
    int mid = 0;
    while (start <= end && mid >= 0)
    {
        mid = start + (end - start) >> 1; 

        if (target > array[mid])
        {
            start = mid + 1;
        }
        else if (target < array[mid])
        {
            end = mid - 1;
        }
        else if (target == array[mid])
        {
            return 1;
        }
    }
    
    return -1;
}

/* 存在返回1，不存在返回0 */
int binarySearchIsExit(int * array, int length, int target)
{
    if(!array)
    {
        return -1;
    }

    return binarySearch(array, length, target, 0, length - 1);
}

int main()
{
    int buffer[] = {1, 3, 7, 16, 27, 29, 30, 31};
    int length = sizeof(buffer) / sizeof(buffer[0]);
    int target = 1;

    int exitVal = 0;
    exitVal = binarySearchIsExit(buffer, length, target);
    printf("val is eixt : %d\n", exitVal);

    return 0;
}