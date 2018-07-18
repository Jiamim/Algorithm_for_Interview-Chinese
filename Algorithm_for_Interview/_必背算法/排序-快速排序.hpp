/*
快排

注意：
    - 快排是不稳定排序

思路：
    选基数，双指针移动/交换，分治

示例：
    > 坐在马桶上看算法：快速排序 - 51CTO.COM http://developer.51cto.com/art/201403/430986.htm
    > 快速排序(三种算法实现和非递归实现) - CSDN博客 https://blog.csdn.net/qq_36528114/article/details/78667034
    
    第一轮
            i                               j
        6   1   2   7   9   3   4   5   10  8
        基数 x=6
        先从 j 往前遍历(j--)，遇到小于 x 的数停下，再从 i 往后遍历，遇到大于 x 的数停下，交换 *j 和 *i
                    i               j
        6   1   2   7   9   3   4   5   10  8
        6   1   2   5   9   3   4   7   10  8（交换后）
        重复以上步骤，继续先移动 j，再移动 i
                        i       j
        6   1   2   5   9   3   4   7   10  8
        6   1   2   5   4   3   9   7   10  8（交换后）
                           ij
        6   1   2   5   4   3   9   7   10  8
        6   1   2   5   4   3   9   7   10  8（交换后）
        此时 i 与 j 相遇，交换 *i 与 *x
                           ij
        3   1   2   5   4   6   9   7   10  8
        第一轮完成，之后递归完成子部分

    基数的选择不固定，一般选择第一个或最后一个，或中位数
*/

#pragma once
#include "../all.h"

void quickSort(int arr[], int l, int r) {

    if (l > r) return;      // 递归基

    int key = arr[l];
    int i = l, j = r;
    while (i < j) {
        while (arr[j] >= key && i < j)      // 先移动 j
            j--;
        while (arr[i] <= key && i < j)      // 后移动 i
            i++;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    // 交换基数
    swap(arr[l], arr[i]);

    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

void
solve()
{   
    int arr[]{ 10,6,1,2,2,7,9,3,4,5,8,8 };
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (auto i : arr)
        cout << i << ' ';
    print();
}