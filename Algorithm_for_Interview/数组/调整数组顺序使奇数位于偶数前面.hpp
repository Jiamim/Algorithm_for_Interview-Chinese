/*
调整数组顺序使奇数位于偶数前面 https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

时间限制：1秒 空间限制：32768K 热度指数：244244
本题知识点： 数组

解题思路：
    原题估计是想考顺移（冒泡排序）
    我直接用两个数组记录奇偶，再重新放进原数组，时间复杂度应该更低，但是空间复杂度高

提交记录：
    一次
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 基本逻辑
        vector<int> odd;
        vector<int> eve;
        for (auto i : array) {
            if (i & 1)
                eve.push_back(i);
            else
                odd.push_back(i);
        }

        array.swap(odd);
        array.insert(array.begin(), eve.begin(), eve.end());
    }
};

void 
solve() {

}