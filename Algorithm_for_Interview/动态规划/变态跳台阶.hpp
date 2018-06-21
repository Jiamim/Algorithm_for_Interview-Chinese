/*
变态跳台阶 https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述：
    一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
    求该青蛙跳上一个n级的台阶总共有多少种跳法。

时间限制：1秒 空间限制：32768K 热度指数：169212

解题思路：
    动态规划
    f(n) = f(n-1) + f(n-2) + .. + f(1) + 1
    f(1) = 1
    f(2) = 2
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int jumpFloorII(int number) {
        // 使用一个辅助数组
        /*int tmp[1024];

        tmp[0] = 1;
        tmp[1] = 1;
        int sum = tmp[0] + tmp[1];
        for (int i = 2; i <= number; i++)
        {
            tmp[i] = sum;
            sum += tmp[i];
        }

        return tmp[number];*/

        // 可以不用辅助数组
        int f_0 = 1;
        int f_1 = 1;

        int sum = f_0 + f_1;
        for (int i = 2; i <= number; i++) {
            f_1 = sum;
            sum += f_1;
        }

        return sum;
    }
};

void
solve()
{

}