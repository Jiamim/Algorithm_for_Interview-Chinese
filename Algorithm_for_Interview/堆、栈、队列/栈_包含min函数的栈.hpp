/*
包含min函数的栈 https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

时间限制：1秒 空间限制：32768K 热度指数：134302
本题知识点： 栈

解题思路：
    基本的栈，就用 STL 容器即可，关键是 min()
    存储所有的 min 也要用到一个栈

提交记录：
    1. top() 和 min() 都忘记 return ...
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s_min.empty()) {
            s_min.push(value);
        }
        if (value <= s_min.top()) {
            s_min.push(value);
        }
    }
    void pop() {
        int tmp = s1.top();
        s1.pop();
        if (tmp == s_min.top())
            s_min.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s_min.top();
    }

    stack<int> s1;
    stack<int> s_min;
};

void solve()
{

}
