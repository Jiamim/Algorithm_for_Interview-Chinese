/*
数组中出现次数超过一半的数字 https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

时间限制：1秒 空间限制：32768K 热度指数：158471
本题知识点： 数组

解题思路:
    计数排序

提交记录:
    一次

*/
#pragma once

#include "../all.h"

class Solution {
public:
    map<int, int> m;

    int MoreThanHalfNum_Solution(vector<int> numbers) {

        int l = numbers.size() / 2;

        for (auto i : numbers) {
            if (in_map(i))
                m[i] += 1;
            else
                m[i] = 1;
        }

        for (auto i : m) {
            if (i.second > l)
                return i.first;
        }

        return 0;
    }

    bool in_map(int i) {
        auto it = m.find(i);
        if (it != m.end())
            return true;
        return false;
    }
};

void solve()
{

}
{}

