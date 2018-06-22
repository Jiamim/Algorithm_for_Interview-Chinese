/*
第一个只出现一次的字符 https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

时间限制：1秒 空间限制：32768K 热度指数：133015
本题知识点： 字符串

解题思路：
    1. 用一个 链表 按顺序记录字符，用一个 map 记录所有字符及其第一次出现的位置，如果某字符第二次出现就从链表删除之
        最后返回链表头字符的位置
    2. 可以不使用链表，反之，还需要在便利一遍 str

提交记录：
    1. 思路 1 本地测试可以，牛客堆栈溢出
    2. 思路 2 解决

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //if (str == "") return -1;

        //list<char> l;
        //map<char, int> m;

        //for (int i = 0; i < str.length(); i++) {
        //    if (m.count(str[i]) == 0) {
        //        m.emplace(str[i], i);
        //        l.emplace_back(str[i]);
        //    }
        //    else {
        //        auto it = find(l.begin(), l.end(), str[i]);
        //        l.erase(it);
        //    }
        //}

        //return m[l.front()];

        map<char, int> m;
        for (int i = 0; i < str.length(); i++) {
            if (m.count(str[i]) == 0) {
                m.emplace(str[i], 1);
            }
            else {
                m[str[i]] += 1;
            }
        }
        for (int i = 0; i < str.length(); i++) {
            if (m[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

void 
solve()
{
    int ret = Solution().FirstNotRepeatingChar("abcdefabcd");
    print(ret);
}