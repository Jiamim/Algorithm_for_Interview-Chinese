/*
数组中只出现一次的数字 https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

时间限制：1秒 空间限制：32768K 热度指数：106869
本题知识点： 数组

知识点：
    时间换空间

解题思路：
    1. 利用 map 保存出现次数，空间复杂度 O(n)
    2. 先排序，再遍历，时间复杂度 O(nlogn)

    3. （最佳）利用 异或(^) 运算（参考自讨论区）

        异或知识点：
            a ^ 0 = a
            a ^ a = 0 
            a ^ b ^ a = b

        如果只有一个数字出现一次，那么问题很简单，对整个数组求异或，最后的结果就是那个出现一次的数

        但是本题有两个数字出现了一次，有了上面的思路，
            下面要做的就是将原数组拆成两部分，a 和 b 分别在这两部分之中，之后单独处理这两部分即可。
        
        如果你对位运算不熟，那么可能很难想到下面的方法：
            具体过程如下：
                记两个只出现一次的数为 a, b
                1. 先对所有数做异或，最后的结果即 a^b
                2. a^b 必不为 0，即该数的二进制中至少有一位为 1，
                    找出（右起）第一个为 1 的位置，记为 n，有 a 和 b 的第 n 位数不同
                    下面以第 n 位是否为 1 将原数组分为两份
                    到此问题解决

提交记录：
    1. 返回值写法错误：
        应该是 *num = n;
        写成了 num = &n;
    2. 只过了 75%
        未过用例 {1,1,1,1,4,6}
    3. 使用思路 3 pass

*/
#pragma once

#include "../all.h"

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        int cor = 0;
        for (auto i : data) 
            cor ^= i;

        int n1 = 1;
        int tmp = cor;
        while (tmp) {
            if (tmp & 1) break;  // 判断奇偶的常用操作，这里目的是判断最后一位是否为 1
            n1++;
            tmp >>= 1;
        }

        tmp = 1;
        tmp <<= n1-1;
        *num1 = *num2 = 0;  // 防止 num1 和 num2 的初值不为 0
        for (auto i : data) {
            if (i & tmp)  // 想不起这步有什么效果时，手算一遍
                *num1 ^= i;
            else
                *num2 ^= i;
        }
    }
};

void 
solve()
{
    print(123 ^ 123);  // 0
    print(4 ^ 6 ^ 4);
    print(2 ^ 0);

    //vector<int> data{ 2,4,3,6,3,2,5,5 };
    vector<int> data{ 1,1,1,1,4,6 };
    int num1 = 0;
    int num2 = 0;
    Solution().FindNumsAppearOnce(data, &num1, &num2);
    print(num1);
    print(num2);
}
