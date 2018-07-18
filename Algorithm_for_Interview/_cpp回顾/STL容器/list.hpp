/*
链表常用操作：
    1. 前插
    2. 尾插
    3. 指定位置插入
    4. 查找
    5. 删除
    6. 移除全部某个值

链表的使用频率不高

注意：
    链表的迭代器不支持随机存取，即 `l.begin() + 1` 这种操作
*/
#pragma once

#include "../../all.h"
#include <list>

using namespace std;

class Solution {
public:
    void test() {
        list<int> l1{ 1,2,3,4,5 };

        // 前插
        l1.push_front(0);
        // 获取第一个元素
        auto top = l1.front();
        cout << top << endl;        // 0
        // 弹出第一个元素
        l1.pop_front();
        cout << l1.front() << endl; // 1

        // 尾插
        l1.push_back(6);
        // 获取最后一个元素
        auto back = l1.back();
        cout << back << endl;       // 6
        // 弹出最后一个元素
        l1.pop_back();
        cout << l1.back() << endl;  // 5

        // 删除
        auto ret = find(l1.begin(), l1.end(), 3);
        cout << *ret << endl;
        l1.erase(ret);
        ret = find(l1.begin(), l1.end(), 3);
        if (ret == l1.end())
            cout << "have erase 3" << endl;

        // 移除某个值，会全部移除，如果该值不存在，无返回值
        ret = find(l1.begin(), l1.end(), 5);
        cout << *ret << endl;
        l1.push_back(5);    // 再添加一个 5
        l1.push_back(5);    // 再添加一个 5
        cout << l1.size() << endl;  // 6
        l1.remove(5);       // 移除所有 5
        cout << l1.size() << endl;  // 3
        ret = find(l1.begin(), l1.end(), 5);
        if (ret == l1.end())
            cout << "have remove all 5" << endl;

        // 插入 - 有 4 种插入
        l1.insert(l1.begin(), 3);       // 1. 在开头插入 3
        l1.insert(l1.begin(), 5, 3);    // 2. 在开头插入 5 个 3
        l1.insert(l1.begin(), l1.begin(), l1.end());    // 3. 在指定位置插入一个范围
        l1.insert(l1.begin(), { 1,2,3 });               // 4. 在指定位置插入一个初始化列表

        // 清空
        l1.clear();
    }

    
};

int solve() {

    Solution().test();

    return 0;
}