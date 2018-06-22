/*
字符流中第一个不重复的字符 https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

时间限制：1秒 空间限制：32768K 热度指数：55599
本题知识点： 字符串

解题思路：
    list<pair<char, int>>

    使用 map 的效率更高，但是 map 不能保存顺序信息；可以使用一个 char[] 保存已知的 str 流

提交记录：
    1. 重复插入

*/
#pragma once

#include "../all.h"

class Solution
{
public:

    list<pair<char, int>> tmp;
    //Insert one char from stringstream
    void Insert(char ch)
    {
        //pair<char, int> ci{ ch, 1 };
        //tmp.emplace_back(ci);

        auto it = tmp.begin();
        while (it != tmp.end()) {
            if (it->first == ch)
            {
                it->second++;
                return;
            }
            it++;
        }
        if (it == tmp.end()) {
            pair<char, int> ci{ ch, 1 };
            tmp.emplace_back(ci);
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        auto it = tmp.begin();
        while (it != tmp.end()) {
            if (it->second == 1)
                return it->first;
            it++;
        }
        return '#';
    }

};

void 
solve()
{

}