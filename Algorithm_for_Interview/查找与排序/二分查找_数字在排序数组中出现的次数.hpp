/*
数字在排序数组中出现的次数 https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
统计一个数字在排序数组中出现的次数。

时间限制：1秒 空间限制：32768K 热度指数：108012
本题知识点： 数组

解题思路：
    二分查找搜上下界

提交记录
    1. pass

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        return upper_bound(data.begin(), data.end(), k) - lower_bound(data.begin(), data.end(), k);
    }
};

void
solve()
{
    vector<int> data{ 1,2,2,2,3 };
    int ret = Solution().GetNumberOfK(data, 2);
    print(ret);
}