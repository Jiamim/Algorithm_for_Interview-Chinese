/*
常用位运算操作
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void bitOP() {
    /*计算二进制表示中`1`的个数*/
        vector<int> ns{0, 1, 64, 64-1, 128, 128-1};
        for (auto i : ns)
            cout << numberOfOne(i) << ' ';  // 0 1 1 6 1 7
        cout << endl;

    /*判断第 i 位是否为 1 （i 从 0 开始）*/
        int i = 4;  // 因为 i 从 0 开始，所以这实际上是右起第 5 位
        int n = 16; // 10000
        // 法 1：移动 1
        if (n & (1 << i))
            cout << "true" << endl;
        // 法 2：移动 n
        if ((n >> i) & 1)
            cout << "true" << endl;

    /*判断奇偶*/
        n = 5;
        if (n & 1)
            cout << n << " 是奇数" << endl;

    /*简单快速幂*/
        cout << quickPow(3, 1);
    }

    /* 计算二进制表示中`1`的个数
    */
    int numberOfOne(int n) {
        int cnt = 0;
        /* 法2）更好的方法，O(m) - m 为 1 的个数 */
        while (n > 0) {
            cnt++;
            n &= n - 1;
            /* 说明：
                n-1 后会翻转右数第一个 1 及之后的每一位；
                然后 n&(n-1) 会把该位置的 1 及之后的每一位置零；
                因此每次循环恰好消去一个 1 直到变为 0
                    n       = 100,100
                    n-1     = 100,011
                n = n&(n-1) = 100,000   cnt++
                    n-1     = 011,111
                n = n&(n-1) = 000,000   cnt++
            */
        }
        /* 法1）常规方法，O(n) - n 为二进制的长度
        while (n > 0) {
            if (n & 1)
                cnt++;
            n >>= 1;
        }
        */
        return cnt;
    }

    /*简单快速幂*/
    double quickPow(double base, int p) {
        int ret = 1.0;
        int q = abs(p);
        while (q > 0) {
            if (q & 1)
                ret *= base;
            base *= base;
            q >>= 1;
        }
        return p > 0 ? ret : 1 / ret;
    }
};

void
solve()
{
    Solution().bitOP();
}