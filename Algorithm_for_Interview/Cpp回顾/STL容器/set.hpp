/*
集合 set
    set 和 map 基本一致，相当于没有 value 的 map，或者说的 map 的 key 就是一个 set
    因此，set 跟 map 的 key 一样是不允许重复的

    如果需要重复，可以使用 multiset

    set 的内部实现默认是红黑树——Python 默认是 HashSet
        因此 set 中的元素是默认有序的——升序
        如果需要降序的 set，可以使用仿函数

    ~~STL 也提供了 hash_set 的实现~~
    STL 已经移除了 hash_set，改用 unordered_set 实现 Hash Set（可能）
        注意：使用 unordered_set 并不会改变插入元素的顺序，这一点跟 Python 中的 set 不太一样——注意：但如果使用 Ipython，它会自动帮你有序显示

        C++:
            vector<char> vc{ 'a', 'r', 'b', 'c', 'd' };
            unordered_set<char> hs(v.begin(), v.end());
            for (auto i : hs)
                cout << i << ' ';       // a b r c d
            cout << endl;
            hs.emplace('e');
            for (auto i : hs)
                cout << i << ' ';       // a b r c d e  插入位置不变
            cout << endl;

        Python:
            >>> a = set('abracadabra')
            >>> a
            {'a', 'r', 'b', 'c', 'd'}
            >>> a.add('e')
            >>> a
            {'a', 'e', 'r', 'b', 'c', 'd'}          # 'e' 的插入位置变了，但是无序

        Ipython:
            In [1]: a = set('abracadabra')

            In [2]: a
            Out[2]: {'a', 'b', 'c', 'd', 'r'}

            In [3]: a.add('e')

            In [4]: a
            Out[4]: {'a', 'b', 'c', 'd', 'e', 'r'}  # 'e' 的插入位置变了，有序
*/
#pragma once

#include "../../all.h"
#include <set>
#include <unordered_set>  // #include <hash_set>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator () (int l, int r) {
            return l > r;
        }
    };

    void test() {
        set<int> s1;
        set<int> s2{ 3,1,2 };
        vector<int> v { 3,2,1,5,4 };
        set<int> s3(v.begin(), v.end());
        set<int, cmp> s4(v.begin(), v.end());           // 利用仿函数构造降序集
        set<int, greater<int>> s5(v.begin(), v.end());  // STL 提供的 greater 仿函数

        // 正序遍历
        for (auto i : s3)
            cout << i << ' ';
        cout << endl;

        // 逆序遍历
        for (auto it = s4.rbegin(); it != s4.rend(); it++)
            cout << *it << ' ';
        cout << endl;

        // 增
        s2.insert(4);  // {1,2,3,4}

        // 删
        s2.erase(3);  // {1,2,4}

        // 改
        auto it = s2.find(4);
        if (it != s2.end()) { // 找到了
            //
        }
        // 查
        auto ii = s2.count(4);

        for (auto i : s2)
            cout << i << ' ';
        cout << endl;

        // 允许重复的集合
        multiset<int> ms1{ 1,2,2,2,3,4 };
        auto itp1 = ms1.find(2);  // No.2
        auto itp2 = ms1.lower_bound(2);  // No.2
        cout << (itp1 == itp2) << endl;  // True

        auto itp3 = ms1.upper_bound(2);  // No.5
        cout << *itp3 << endl;  // 3

        // Hash Set
        vector<char> vc{ 'a', 'r', 'b', 'c', 'd' };
        unordered_set<char> hs(vc.begin(), vc.end());
        for (auto i : hs)
            cout << i << ' ';   // a b r c d
        cout << endl;
        hs.emplace('e');
        for (auto i : hs)
            cout << i << ' ';   // a b r c d e
        cout << endl;
    }


};

int solve() {
    Solution().test();

    return 0;
}