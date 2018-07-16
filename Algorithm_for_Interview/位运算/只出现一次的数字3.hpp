/*
260. 只出现一次的数字 III https://leetcode.com/problems/single-number-iii/description/
数组中只出现一次的数字 https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目描述：
    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

    示例 :
        输入: [1,2,1,3,2,5]
        输出: [3,5]

    注意：
        结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
        你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

思路：
    1. 首先排除需要排序的方法，时间复杂度要求不符

    2. 如果对空间复杂度没有要求，那么最简单的做法显然是利用字典/map

    3. 如果要求空间复杂度为 O(1)，那么需要利用到位运算的性质：
        a ^ a = 0
        a ^ 0 = a
        a ^ b ^ a = b

        先考虑简单的情况，如果数组中只有一个数出现一次，那么根据异或运算的性质，很容易就能找到该数；
        于是，下面的问题就是如何将原数组划分，使 a 和 b 分别落在不同的组中

        因为 a != b，所以 a ^ b != 0，也就是说 a ^ b 的二进制中必有一位为 1，
        根据异或 ^ 的性质，在这一位上，a 和 b 必不相同
        于是可以根据这一性质来划分数组，以保证 a 和 b 落于不同的组中

提交记录：
    1. 生成第 n 位为 1 的数，应该是
        int x = 1 << (n-1)，而不是
        int x = 1 << n;
    2. == 的优先级高于 &，所以
        if (i & x != 0)，应该写作 
        if ((i & x) != 0)，或者直接
        if (i & x)
    3. 小改进
        利用上转型，可以直接返回
            return {a, b}; 而不需要
            return vector<int>{a, b};
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 求出 a^b 的值
        int c = 0;
        for (auto i : nums)
            c ^= i;

        // 找出 c 的二进制中左起第一个为 1 的位置
        int offset = 0;
        for (int i = 0; i<8 * sizeof(int); i++) {
            if (c & (1 << i))
                break;
            offset++;
        }
        int a = 0, b = 0;
        for (auto i : nums) {
            if (i & (1 << offset))
                a ^= i;
            else
                b ^= i;
        }

        //return vector<int>{a, b};
        return { a, b };  // // 自动转型
    }

    // 牛客网的接口
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
        tmp <<= n1 - 1;
        *num1 = *num2 = 0;  // 防止 num1 和 num2 的初值不为 0
        for (auto i : data) {
            if (i & tmp)
                *num1 ^= i;
            else
                *num2 ^= i;
        }
    }
};

void 
solve()
{   
    for (auto i : vector<int>{1, 2})
        print(i);

    vector<int> a{ 1, 2, 1, 3, 2, 5 };
    vector<int> ret = Solution().singleNumber(a);

    for (auto i : ret)
        print(i);

    if (3 & 5)
        print("test");
}