/*
136. Single Number https://leetcode.com/problems/single-number/description/

题目描述
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

时间限制：1秒 空间限制：32768K 热度指数：106869
本题知识点： 数组

知识点：
    位运算

思路：
    异或(^) 运算

    异或知识点：
        a ^ 0 = a
        a ^ a = 0 
        a ^ b ^ a = b

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto i : nums)
            ret ^= i;
        return ret;
    }
};

void 
solve()
{

}
