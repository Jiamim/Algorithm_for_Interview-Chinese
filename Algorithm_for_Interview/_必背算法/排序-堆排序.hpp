/*
堆排序
- 堆排序是不稳定排序
- 堆的性质：
    每个节点的值小于等于其父节点 或 大于等于父节点；前者称为“最大堆”，用于升序，后者为“最小堆”，用于降序
- 堆是一棵**完全二叉树**，因此常用数组进行模拟

思路：
    建堆：
        建堆的过程实际上就是从最后一个 非叶子节点 开始不断向前做自顶向下的调整
    堆排序：
        建完堆后，每次交换堆顶和堆尾，
        然后对 a[0..n-1] 重新调整

    每次调整的操作时间复杂度为 O(logn)

*/
#pragma once
#include "../all.h"

// 自顶向下调整——在数组 arr[0..n] 中将 arr[i] 调整到满足要求的位置
void swift_down(int a[], int i, int n) {
    int tmp = i;
    int OK = 0;
    while (!OK) {
        int lc = i * 2 + 1;             // 左孩子
        if (lc < n && a[tmp] < a[lc])   // 在不越界的情况下，如果 a[i] 小于它的左孩子
            tmp = lc;

        int rc = lc + 1;                // 右孩子 = i*2+2 = lc+1
        if (rc < n && a[tmp] < a[rc])   // 在不越界的情况下，如果 a[i] 小于它的右孩子
            tmp = rc;
        // 实际上，以上操作就是为了找出 a[i] 和 a[i*2+1]、a[i*2+2] 之中的最大值
        // 至于为什么不直接使用 max，是因为需要越界判断

        if (tmp != i) {                 // 如果 a[i] 不是最大的，说明还需继续调整
            swap(a[i], a[tmp]);
            i = tmp;
        }
        else {                          // 反之调整完毕
            OK = 1;
        }
    }
    // 注意：自定向下的操作只完成了一个节点的调整，
    // 建堆的过程实际上就是从最后一个 非叶子节点 开始不断往前调整
}

void make_heap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--)
        swift_down(a, i, n);
}

void heap_sort(int a[], int n) {
    // 先建堆
    make_heap(a, n);
    // 建完堆后
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        swift_down(a, 0, i);
    }
}

void
solve()
{
    int arr[]{ 10,6,1,2,2,7,9,3,4,5,8,8,10,11 };
    int n = sizeof(arr) / sizeof(int);
    
    heap_sort(arr, n);

    for (auto i : arr)
        cout << i << ' ';
    print();
}