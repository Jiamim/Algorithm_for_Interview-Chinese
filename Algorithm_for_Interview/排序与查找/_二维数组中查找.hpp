/*
二维数组中查找 https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

时间限制：1秒 空间限制：32768K 热度指数：629898
本题知识点： 查找
*/

#pragma once

#include "../all.h"

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = array.size() - 1;
        int j = 0;

        while ((i >= 0) && j < array[0].size())
        {
            if (array[i][j] > target)
                i--;
            else if (array[i][j] < target)
                j++;
            else
                return true;
        }
        
        return false;
    }
};

int solve() {
    int target = 5;
    vector<vector<int> > array{ { 1,2,3,4 },{ 2,3,4,5 } };

    bool flag = Solution().Find(target, array);
    cout << flag << endl;
    return 0;
}