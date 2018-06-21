/*
矩形覆盖 https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

时间限制：1秒 空间限制：32768K 热度指数：148824

解题思路
    动态规划
    关键是找到递推公式（可惜没找出来，想复杂了）
    实际上还是斐波那契数列
        f(0) = 0 （不满足，单独讨论）
        f(1) = 1
        f(2) = 2
        f(n) = f(n-1) + f(n-2)
*/
#pragma once

class Solution {
public:
    int rectCover(int number) {
        // f(0) = 0
        // f(1) = 1
        // f(2) = 2
        if (number == 0)
            return 0;

        int pre = 1;
        int nxt = 2;
        int tmp;
        for (int i = 2; i <= number; i++) {
            tmp = nxt + pre;
            pre = tmp - pre;
            nxt = tmp;
        }

        return pre;
    }
};

void 
solve() {

}