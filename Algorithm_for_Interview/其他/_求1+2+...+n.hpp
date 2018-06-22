/*
求1+2+3+...+n https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

时间限制：1秒 空间限制：32768K 热度指数：84691

解题思路：
    1. 递归
        关键是如何设置结束条件——利用 && 的短路性质
    2. 类似快速幂
    3. 利用 sizeof 运算符

提交记录：
    pass
*/
#pragma once

#include "../all.h"

class Solution {
public:
    // 思路 1
    int Sum_Solution(int n) {
        int sum = n;
        (n - 1) && (sum += Sum_Solution(n - 1));

        return sum;
    }

    // 思路 2 - 快速幂
#define f(x) ((((x) & 1) << 31) >> 31)
    int Sum_Solution_2(int n) {
        int a = n, b = n + 1, s = 0;
        //复制32次。。
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;

        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        s += b & f(a); a >>= 1; b <<= 1;
        return s >> 1;
    }

    // 思路 3 - 利用 sizeof 运算符
    int Sum_Solution(int n) {
        bool a[n][n + 1];
        return sizeof(a) >> 1;
    }
};

void solve()
{

}