/*
最小的K个数 https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

时间限制：1秒 空间限制：32768K 热度指数：200875
本题知识点： 数组

解题思路：
    优先队列/堆

提交记录：
    1. 没有考虑 k > input.size() 的情况
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> ret;

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size()) return ret;

        priority_queue<int, vector<int>, greater<int>> p;
        for (auto i : input)
            p.push(i);
        while (k--) {
            ret.push_back(p.top());
            p.pop();
        }

        return ret;
    }
};

void solve() {

}