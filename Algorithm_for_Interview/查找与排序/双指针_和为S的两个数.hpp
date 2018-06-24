/*
和为S的两个数字 https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

时间限制：1秒 空间限制：32768K 热度指数：95401

解题思路：
    首尾双指针移动
    乘积最小的条件并没有用，因为距离越大的两个数乘积越小

提交记录：
    1. 堆栈溢出
        return vector<int> {array[lo], array[hi]}; 不能这么写，这不是 Python

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ret;
        int lo = 0, hi = array.size() - 1;

        int tmp;
        while (hi - lo > 1) {
            tmp = array[lo] + array[hi];
            if (tmp < sum)
                lo++;
            else if (tmp > sum)
                hi--;
            else
            {
                ret.push_back(array[lo]);
                ret.push_back(array[hi]);
                break;
            }
        }
        // 改进
        /*
        while (hi - lo > 1) {
            if (array[lo] + array[hi] == sum)
            {
                ret.push_back(array[lo]);
                ret.push_back(array[hi]);
                break;
            }
            while (lo < hi && array[lo] + array[hi] < sum) lo++;
            while (lo < hi && array[lo] + array[hi] > sum) hi--;
        }
        */

        return ret;
        //return vector<int> {array[lo], array[hi]};
    }
};

void solve()
{
    vector<int> a{ 1,2,3,4,5 };
    auto ret = Solution().FindNumbersWithSum(a, 7);
}