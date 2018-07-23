/*
桶排序

思路：
    将相同的数分配到同一个“桶”中，桶的数量 = 数据范围内离散值的总数 n
    首先遍历一次所有 m 个数据，依次将数据分派到合适的“桶”中，
    然后按顺序遍历所有“桶”，桶中存在几个数据，就输出几次；没有则跳过。

    时间复杂度 O(m+n)，适合 n 不太大的情况，
    缺点是非常空间复杂度高

说明：
    1. 桶排序是稳定的
    2. 桶排序是常见排序里最快的一种,比快排还要快…大多数情况下
    3. 桶排序非常快,但是同时也非常耗空间,基本上是最耗空间的一种排序算法
*/
#pragma once

#include "../all.h"

#define MAXN 1000

void bucketSort(int arr[], int n) {
    int b[MAXN]{ 0 };               // 初始化为 0

    for (int i = 0; i < n; i++)
        b[arr[i]] += 1;

    int cnt{ 0 };
    for (int i = 0; i < MAXN; i++) {
        if (b[i] > 0) {
            for (int j = 0; j < b[i]; j++)
                arr[cnt++] = i;
        }
    }

    assert(cnt == n);
}

void
solve()
{
    int arr[]{ 22,11,2,23,21,1,1 };
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
}