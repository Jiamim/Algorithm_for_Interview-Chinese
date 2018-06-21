/*
斐波那契数列 https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

示例
    0 1 2 3 5

时间限制：1秒 空间限制：32768K 热度指数：283159

提交记录：
    我自己写的用了辅助数组，空间复杂度为 O(n)
    讨论区发现了 O(1) 的写法

*/
#pragma once

#include "../all.h"

class Solution {
public:
    int Fibonacci(int n) {
        // 空间复杂度 O(n)
        long nums[40];
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i < n; i++)
            nums[i] = nums[i - 1] + nums[i - 2];
        //return nums[n];

        // 空间复杂度 O(1)
        int f = 0;
        int g = 1;
        while (n--) {
            g = g + f;
            f = g - f;
        }
        return f;
    }
};

void solve() {
    int ret;
    ret = Solution().Fibonacci(0);
    print(ret);
    ret = Solution().Fibonacci(1);
    print(ret);
    ret = Solution().Fibonacci(2);
    print(ret);
    ret = Solution().Fibonacci(3);
    print(ret);

}