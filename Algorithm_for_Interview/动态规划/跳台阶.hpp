/*
跳台阶 https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

时间限制：1秒 空间限制：32768K 热度指数：218636

解题思路：
    跳上 n 级台阶的方法数 = 跳上 (n-1) 级台阶的方法数 + 跳上 (n-2) 级台阶的方法数
    即：f(n) = f(n-1) + f(n-2)  // 斐波那契数列！！只是初始值不同
    动态规划
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int jumpFloor(int number) {
        int f = 1;
        int g = 2;

        number--;  // 为什么有这一步：跟具体输入有关
                   // 我这里默认编号从 0 开始，用例从 1 开始
        while (number--) {
            g = g + f;
            f = g - f;
        }
        return f;
    }
};

void solve()
{

}