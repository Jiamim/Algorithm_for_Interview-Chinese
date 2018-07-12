/*
堆
常用有两种构建堆的方式：
    1. 使用“优先队列”
    2. 使用`make_heap` (todo)
*/
#pragma once

#include "../../all.h"
#include <queue>
using namespace std;

class Solution {
public:
    struct node {
        int v1;
        int v2;
        //bool operator () (const node &l, const node &r) {
        //    return l.v1 != r.v1 ? l.v1 < r.v1 : l.v2 < r.v2;
        //}
    };

    // 仿函数比较器 - 降序
    struct cmp {
        bool operator () (int l, int r) {
            return l > r;
        }
    };
    // 自定义比较：先比较元素 1，再比较元素 2
    struct cmp2 {
        bool operator () (const node &l, const node &r) {
            return l.v1 != r.v1 ? l.v1 < r.v1 : l.v2 < r.v2;
        }
    };

    void test() {
        // vector 转优先队列
        //   如果是传统 ACM 的数据读取方式，可以不必这么做，在读取数据时，直接传入优先队列
        //   如果是 LeetCode 的方式，如果直接接受的是一个 vec 参数，那么可能需要用到这种方法
        vector<int> v1 = { 1,2,3 };
        //priority_queue<int> p1(v1);  // 没有直接将 vec 转 pri_que 的构造
        priority_queue<int> p1(v1.begin(), v1.end());
        cout << p1.top() << endl;  // 3

        // 添加数据
        p1.push(5);
        // 获取顶部数据
        auto top = p1.top();
        cout << top<< endl;  // 5
        // 弹出顶部数据
        p1.pop();   // 没有返回值，所以如果要使用顶部的数据，需要先接收

        // 数组转优先队列
        int arr[] = { 1,2,3 };
        priority_queue<int, vector<int>, cmp> p2(arr, arr + 3); // 使用仿函数构建最小堆，默认最大堆
        cout << p2.top() << endl;  // 1

        // 自定义结构体
        node arr2[] = { {1, 1}, {2, 2}, {2, 4}, {2, 3}, {1, 2} };
        priority_queue<node, vector<node>, cmp2> p3(arr2, arr2 + 5);
        p3.pop();  // {2, 4}
        p3.pop();  // {2, 3}
        p3.pop();  // {2, 2}
        p3.pop();  // {1, 2}
        p3.pop();  // {1, 1}
    }

    
};

void solve() {
    Solution().test();
}