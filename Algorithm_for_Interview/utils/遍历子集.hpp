/*
暴力搜索经常需要遍历数组的子集
    比如：../动态规划/划分数组使和之差最小.hpp

思路：
    利用递归/迭代可以方便的遍历所有子集
    > c++ - Finding all the subsets of a set - Stack Overflow https://stackoverflow.com/questions/728972/finding-all-the-subsets-of-a-set

    getAllSubsets()：
    1. For `{1}`, the subsets is `{{}, {1}}`
    2. For `{1, 2}`, add 2 to each subset of `{{}, {1}}` to get `{{2}, {1,2}}`.
       Then union them to get all subsets is `{{}, {1}, {2}, {1, 2}}`
    3. Repeat until reach `n`

    如果有特殊要求，可以在获取所有子集后再操作；或者在循环中加入剪枝
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void getAllSubsets(vector<int>& vs, vector<vector<int>>& subsets) {
        subsets.push_back({});

        vector<vector<int>> tmp;
        for (auto i : vs) {
            for (auto sub : subsets) {
                sub.push_back(i);
                tmp.push_back(sub);
            }
            for (auto sub : tmp) {
                subsets.push_back(sub);
            }
            tmp.clear();
        }
    }
};

void
solve()
{
    vector<vector<int>> subsets;
    vector<int> vs{ 1,2,3 };

    Solution s;

    s.getAllSubsets(vs, subsets);
    for (auto i : subsets) {
        cout << "{ ";
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '}';
        cout << endl;
    }
}