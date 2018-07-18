/*
向量/动态数组
    最常用的容器
*/
#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:

    bool is_in(vector<int> v, int target) {
        auto it = v.begin();
        for (; it != v.end(); it++)
            if (*it == target)
                break;
        return it != v.end();
    }

    void test() {

        vector<int> v1;  // {}
        vector<int> v2 = { 1,2,3,4 };
        vector<int> v3(3, 10);  // {10,10,10}
        vector<int> v4(v2.begin() + 1, v2.end());  // {2,3,4}
        vector<int> v5(v4);  // {2,3,4}

        // 尾插
        v1.push_back(3);
        v1.push_back(2);
        v1.push_back(1);
        v1.pop_back();
        for (auto i : v1)
            cout << i << ' ';
        cout << endl;

        // 头插、指定位置插入
        v1.insert(v1.begin() + 1, 0);
        v1.insert(v1.begin() + 1, v2.begin(), v2.end());
        v1.insert(v1.end(), v2.begin(), v2.end());
        auto it = v1.erase(v1.begin() + 1);
        cout << *it << endl;
        for (auto i : v1)
            cout << i << ' ';
        cout << endl;

        // 删除
        vector<int> v6 = { 1,2,3,4,5 };
        v6.erase(v6.begin() + 1);  // { 1,3,4,5 }
        v6.erase(v6.begin() + 1, v6.begin() + 3);  // { 1,5 }
        v6.clear();
        for (auto i : v6)
            cout << i << ' ';
        cout << endl;

        // 查找
        it = find(v2.begin(), v2.end(), 5);
        if (it != v2.end()) {   // 找到了，必须做一次判断，以防空迭代器异常
            //
        }

        // 获取数组大小
        cout << "v4 size: " << v4.size() << endl;

        // 整个数组交换
        v1.swap(v2);
        v2.swap(v1);

        // 交换内部元素
        swap(v2[1], v2[2]);
        swap(v2[1], v2[2]);

        // 不同的遍历方法
        cout << "v3: ";
        for (auto i : v3)
            cout << i << ' ';
        cout << endl;

        cout << "v4: ";
        for (size_t i = 0; i < v4.size(); i++)
            cout << v4[i] << ' ';
        cout << endl;

        cout << "v5: ";
        for (auto it = v5.begin(); it != v5.end(); it++)
            cout << *it << ' ';
        cout << endl;

        cout << "r v5: ";   // 逆序遍历
        for (auto it = v5.rbegin(); it != v5.rend(); it++)
            cout << *it << ' ';
        cout << endl;

        // 获取第一个/最后元素
        v2.front() = 12;            // 因为返回的是引用，所以可以直接修改
        v2.back() -= v2.front();
        cout << v2.front() << ", " << v2.back() << endl;

        // 判断空
        if (v1.empty())
            cout << "v1 is empty" << endl;

        // 排序
        // 默认升序
        sort(v2.begin(), v2.end());
        // 降序
        sort(v2.begin(), v2.end(), greater<int>());

        // 自定义排序
        typedef pair<int, int> ii;
        vector<ii> vp{ { 1,1 },{ 1,2 },{ 2,2 },{ 2,3 },{ 3,3 } };
        sort(vp.begin(), vp.end(), [](const ii &l, const ii &r) {   // 按第一个数字升序，第二个降序
            return l.first != r.first ? l.first < r.first : l.second > r.second;
        });
        for (auto i : vp)
            cout << '{' << i.first << ',' << i.second << "} ";
        cout << endl;
    }
};

void solve() {
    Solution().test();
}