/*
只出现一次的数字 II - LeetCode (中国) https://leetcode-cn.com/problems/single-number-ii/description/

题目来源：LeetCode

题目描述：
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

    说明：
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

    示例 1:
        输入: [2,2,3,2]
        输出: 3

    示例 2:
        输入: [0,1,0,1,0,1,99]
        输出: 99

解题思路：
    1. 使用额外空间
        1) 使用字典/map，该方法只能满足时间复杂度，空间复杂度为 O(n)
        2) 使用集合 sum(set(nums))*3 - sum(nums) = 2 * x，空间复杂度为 O(n)

    2. 位操作
        目前看到两个思路：
          1) https://leetcode.com/problems/single-number-ii/discuss/43297/Java-O(n)-easy-to-understand-solution-easily-extended-to-any-times-of-occurance
            思路1 比较清晰：若数组中没有x，且其他所有数字都出现了三次，
            那么所有数字二进制表示的第 x 位相加都应该可以被3整除，如果某一位不能，则表明 x 在这一位上是 1
            该方法的时间复杂度位 O(mn)，其中 m 为二进制的位数，一般 m=32，可以看作时间复杂度为 O(n)

            上面只说了思路，实际实现时需要辅以两种位操作。
                1> 判断第 i 位是否为 1 （i=0:n）
                    if ((num >> i & 1) == 1)
                2> 置第 i 位为 1
                    ans != 1 << i

          2) https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
            这个思路本质上跟上面是一样的，也是记录二进制中 1 的所有位置，但是更加依赖“位操作”，导致难以理解（待更新）

提交记录：
    1. if ((num >> i & 1) == 1) 写成了
       if ((num << i & 1) == 1)

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // 思路 2.1
    int singleNumber(vector<int>& nums) {
        const int bit_size = 32;

        int ans = 0;
        for (auto i = 0; i < bit_size; i++) {
            int bit_sum = 0;
            for (auto num : nums) {
                if ((num >> i & 1) == 1)
                    bit_sum++;
            }
            if (bit_sum % 3 != 0)
                ans |= 1 << i;
        }
        
        return ans;
    }
};

void
solve()
{

}