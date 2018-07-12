/*
队列：
    队列的性质是“先进先出”

    队列包括常规的队列 queue 和双端队列 deque

    queue 的内部就是 deque 实现的，
    因为双端队列包括的队列的所有功能，所以推荐使用 deque —— 它会使用 _front 和 _back 来区分头插和尾插
*/
#pragma once

#include <list>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    void test() {
        // 双端队列
        deque<int> d1 = { 1,2,3 };

        d1.push_front(0);  // {0,1,2,3}
        for (auto i : d1)
            cout << i << ' ';
        cout << endl;

        auto front_val = d1.front();
        d1.pop_front();  // {1,2,3}
        for (auto i : d1)
            cout << i << ' ';
        cout << endl;

        // 一般队列
        queue<int> q1(d1);

        list<int> l = { 1,2,3,4,5 };
        queue<int, list<int>> q2(l);

        //queue<int> q3{ 1,2,3 };  // error
        //queue<int, vector<int>> q4;  // warning

    }

    
};

int solve() {
    Solution().test();

    return 0;
}