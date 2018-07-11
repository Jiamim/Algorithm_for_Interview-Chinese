/*
数值的整数次方 https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

时间限制：1秒 空间限制：32768K 热度指数：204325

知识点：
    快速幂运算

解题思路
    基本解法（连乘连除） - O(n)
    快速幂运算 - O(logN)
*/
#pragma once

#include "../all.h"

class Solution {
public:
    double Power(double base, int exponent) {
        // O(n) 解法
        /*if (base == 0.0)
            return 0;
        if (exponent == 0)
            return 1;

        double ret = 1;
        if (exponent > 0)
            while (exponent--) {
                ret *= base;
            }
        else (exponent < 0)
            while (exponent++)
                ret /= base;

        return ret;*/

        // O(logN) 简单快速幂
        int p = abs(exponent);
        double ret = 1.0;
        while (p != 0) {
            if (p & 1)
                ret *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1 / ret : ret;
    }       
};

void solve() {

}

