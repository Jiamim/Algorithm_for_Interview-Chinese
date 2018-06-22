/*
加一 - LeetCode (中国) https://leetcode-cn.com/problems/plus-one/description/

题目来源：LeetCode

题目描述：
    给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。

    最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

    你可以假设除了整数 0 之外，这个整数不会以零开头。

    示例 1:

    输入: [1,2,3]
    输出: [1,2,4]
    解释: 输入数组表示数字 123。
    示例 2:

    输入: [4,3,2,1]
    输出: [4,3,2,2]
    解释: 输入数组表示数字 4321。

解题思路：
    1. 依次进位

提交记录：

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits);
        for (int i = ret.size() - 1; i >= 0; i--) {
            if (ret[i] < 9) {
                ret[i]++;
                return ret;
            }
            ret[i] = 0;
        }
        ret.insert(ret.begin(), 1);

        return ret;
    }
};

void
solve()
{

}

