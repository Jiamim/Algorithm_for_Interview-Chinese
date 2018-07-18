/*
栈 stack
    栈的性质是“先进后出”

    其内部是使用双端队列 deque 实现的，屏蔽了部分接口
*/
#pragma once

#include <list>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void test() {
        stack<int> s1;
        s1.push(1);
        s1.push(2);
        s1.push(3);

        // pop() 没有返回值，因此如果需要使用弹出的值，需要先接收
        auto top_val = s1.top();  // 3
        s1.pop();

        // 可以使用 deque 来构造 stack
        deque<int> d1 = { 1,2,3 };
        stack<int> s2(d1);

        s2.push(4);
        top_val = s2.top();  // 4
        s2.pop();  // {1,2,3}

    }

};

int solve() {
    Solution().test();

    return 0;
}