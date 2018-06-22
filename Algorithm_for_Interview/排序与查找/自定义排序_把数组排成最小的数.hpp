/*
把数组排成最小的数 https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

时间限制：1秒 空间限制：32768K 热度指数：112505
本题知识点： 数组

解题思路：

提交记录：
    1. 写在类内的比较函数必须是 静态成员 (static)
        bool cmp(int &l, int &r)  -> static bool cmp(int &l, int &r)

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // 需要静态方法
    static bool cmp(int &l, int &r) {
        string ll = to_string(l) + to_string(r);
        string rr = to_string(r) + to_string(l);

        return ll < rr;
    }

    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        stringstream ss;

        for (auto i : numbers) 
            ss << to_string(i);

        return ss.str();
    }
};

void solve()
{
    vector<int> ns{ 34,3,332 };
    sort(ns.begin(), ns.end(), Solution::cmp);

    for (auto i : ns) {
        print(i);
    }
}
