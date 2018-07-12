/*
字典 map

注意：
    map 没有内置通过 value 找 key 的方法
        一种当然是迭代器遍历，
        下面还介绍了一种更高级的方法，通过 lambda 表达式查找
*/
#pragma once

#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    void test() {
        // 构造函数
        map<int, int> m1{ { 1,2 },{ 2,3 },{ 3,4 } };
        map<int, int> m2(m1.begin(), m1.end());
        map<int, int> m3(m2);

        m3[1] = 3;  // 更新
        m3[4] = 5;  // 插入，无返回值
        
        // 插入，如果存在则插入失败；注意与 [] 的区别
        pair<map<int, int>::iterator, bool> ret;
        ret = m3.insert(pair<int, int>(1, 4));
        if (ret.second == false)
            cout << "exist" << endl;

        // hint 插入（不常用）
        auto it = m3.begin();
        it = m3.insert(it, pair<int, int>(6, 7));  // 效率不是最高的
        // 这个跟效率有关，不深入
        // > 我在 stack overflow 上的提问：
        //      c++ - Does it matter that the insert hint place which is close the final place is before or after the final place? - Stack Overflow https://stackoverflow.com/questions/49653112/does-it-matter-that-the-insert-hint-place-which-is-close-the-final-place-is-befo

        // C++11 新语法，更快
        ret = m3.emplace(5, 6);  // 插入成功
        ret = m3.emplace(1, 4);  // 插入失败，key=1 存在了
        it = m3.emplace_hint(it, 8, 9);  // hint 插入

        // 删除 by key
        m3.erase(3);  

        // 查找 by key
        it = m3.find(7);  // 删除 by iterator
        if (it == m3.end())
            m3[7] = 77;

        // 查找 by value
        // 遍历方法，略
        // lambda 方法
        int v = 77;
        it = find_if(m3.begin(), m3.end(),
            [v](const std::map<int, int>::value_type item) {
            return item.second == v;
        });
        if (it != m3.end()) {
            int k = (*it).first;
            cout << k << endl; // 7
        }
        // 此外，还有函数对象的方式
        // > C++ map 根据value找key - CSDN博客 https://blog.csdn.net/flyfish1986/article/details/72833001

        for (auto& i : m3)
            cout << i.first << ": " << i.second << endl;
    }

    
};

int solve() {
    Solution().test();

    return 0;
}