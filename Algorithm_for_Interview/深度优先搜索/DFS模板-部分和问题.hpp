/*
题目来源：《挑战程序设计竞赛（第二版）》

题目描述：
    给定整数 a1、a2、.......an，判断是否可以从中选出若干数，使它们的和恰好为 K。

思路：
    dfs
    第一层是一个 n 叉树，第二层每个节点为 (n-1)，第三层 (n-2)
*/
#pragma once

#include "../all.h"

#define MAX_N 21        // n <= 20
// 输入
int n, k;
int arr[MAX_N];

// 标记
int OK = 0;             // 标记是否有解
int book[MAX_N];        // 标记哪些数字被用到了

// int sum;
void dfs(int sum, int step) {       // 当前和，当前状态
    // 递归退出条件
    if (step == n || sum == k) {    // step 从 0 开始
        if (sum == k)
            OK = 1;
        return;
    }

    // 搜索下一个状态
    for (int i = step; i < n; i++) {
        if (sum + arr[i] > k) continue;     // 剪枝
        book[i] = 1;                        // 修改标记
        //sum += arr[i];
        dfs(sum + arr[i], i + 1);
        if (OK) return;                     // 防止继续修改状态
        //sum -= arr[i];
        book[i] = 0;                        // 还原标记——回溯，注意：有时不需要还原标记
    }
}

void solve() {

    while (cin >> n >> k) {
        OK = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            book[i] = 0;        // 初始化为 0
        }

        dfs(0, 0);
        if (OK) {
            cout << "Yes: ";
            for (int i = 0; i < n; i++)
                if (book[i]) cout << arr[i] << ' ';
            cout << endl;
        }
        else cout << "No\n";
    }
}
