/*
数组中的最长山谷
> LeetCode 845. 数组中的最长山脉 https://leetcode-cn.com/problems/longest-mountain-in-array/description/
  原题是找山脉，这里改成了山谷

示例：
    输入：
        [4,3,2,5,3,1,4,8]
    输出：
        5
    说明：
        [5,3,1,4,8]

注意：这里的输入就是字符串 "[4,3,2,5,3,1,4,8]"，所以建议使用 Python，直接 `A = eval(input())` 就完事了

    我的答题的时候根本就没注意到这个问题，只过了 20%，还一直没找到原因，坑啊

    任何需要 处理字符串 的问题都建议使用 Python

下面是能在 LeetCode 上 AC 的代码
*/
#pragma once

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void
solve() 
{
    //vector<int> A;
    //int a;
    //while (cin >> a)
    //    A.push_back(a);
    vector<int> A{ 4,3,2,5,3,1,4,8 };
    int n = A.size();
    int maxN = 0;

    if (n < 3) cout << maxN;

    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j + 1 < n && A[j + 1] < A[j])    // 改成 A[j + 1] > A[j] 即找山脉
            j++;
        int k = j;
        while (k + 1 < n && A[k + 1] > A[k])    // 改成 A[k + 1] < A[k] 即找山脉
            k++;
        if (j > i && k > j)                     //  注意只有上坡或下坡不算山谷
            maxN = max(maxN, k - i + 1);
    }
    
    cout << maxN;
}

//int main() {
//
//    solve();
//    return 0;
//}

