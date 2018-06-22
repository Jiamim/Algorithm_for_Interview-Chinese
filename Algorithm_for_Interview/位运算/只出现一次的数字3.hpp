/*
只出现一次的数字 III - LeetCode (中国) https://leetcode-cn.com/problems/single-number-iii/description/

题目来源：LeetCode

题目描述：
    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

    示例 :
        输入: [1,2,1,3,2,5]
        输出: [3,5]

    注意：
        结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
        你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

解题思路：
    1. 首先排除需要排序的方法，时间复杂度要求不符

    2. 如果对空间复杂度没有要求，那么最简单的做法显然是利用字典/map

    3. 如果要求空间复杂度为 O(1)，那么可能需要利用到位运算的性质：
        a ^ a = 0
        a ^ 0 = a
        a ^ b ^ a = b

        先考虑简单的情况，如果数组中只有一个数出现一次，那么根据异或运算的性质，很容易就能找到该数；
        于是，下面的问题就是如何将原数组划分，使 a 和 b 分别落在不同的组中

        a != b，所以 a ^ b = c != 0
        也就是说 c 的二进制中必有一位为 1，根据 ^ 的性质，也就是说，在这一位上，a 和 b 必不相同
        根据这一性质来划分整个数组，可保证 a 和 b 落于不同的组中

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
        // 先遍历一遍求出 c
        int c = 0;
        for (auto i : nums)
            c ^= i;

        // 找出 c 的二进制中左起第一个为 1 的位置
        int idx = 0;
        while (c) {
            if (c & 1) {
                idx++;
                break;
            }
            idx++;
            c >>= 1;
        }

        int x = 1 << (idx-1);
        int a = 0, b = 0;
        for (auto i : nums) {
            if (i & x)
                a ^= i;
            else
                b ^= i;
        }

        //return vector<int>{a, b};
        return { a, b };  // 自动转型
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