/*
左旋转字符串 https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

时间限制：1秒 空间限制：32768K 热度指数：96578
本题知识点： 字符串

思路描述：
    利用环形链表（双端队列）

    讨论区发现了一个十分巧妙的做法

        str = "XYZdefabc", n = 3
        str = "XYZdefabc" + "XYZ" = "XYZdefabcXYZ"
        return str.substr(n, len)

提交记录：
    1. 没有考虑 str = "" 的情况
*/
#pragma once

#include "../all.h"

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty()) return "";

        deque<char> d;
        for (auto i : str)
            d.emplace_back(i);

        int len = str.length();
        int move = n % len;

        stringstream ss;

        for (int i = n; i < len; i++)
            ss << d[i];
        for (int i = 0; i < n; i++)
            ss << d[i];

        return ss.str();

    }
};

void solve()
{
    string s{ "abcXYZdef" };

    string ret = Solution().LeftRotateString(s, 3);
    print(ret);
}
