/*
用两个栈实现队列 https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

时间限制：1秒 空间限制：32768K 热度指数：208146
本题知识点： 队列 栈

解题思路：
    栈1 用来 push，栈2 用来 pop；从栈1 到 栈2 正好变成先进先出
    注意 C++ 中的 pop() 没有返回值，需要先记录 top() 再 pop()

提交记录：
    第一次提交失败：
        没有考虑 栈2 不为空时，不能马上把 栈1 中的元素放进去
*/
#pragma once

#include "../all.h"

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ret;
        if (!stack2.empty()) {
            ret = stack2.top();
            stack2.pop();
            return ret;
        }

        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int solve() {
    return 0;
}