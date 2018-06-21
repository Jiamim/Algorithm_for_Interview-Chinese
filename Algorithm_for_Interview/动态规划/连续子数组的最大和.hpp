/*
连续子数组的最大和 https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2

题目来源：剑指Offer

题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:
    在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
    但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
    例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)

时间限制：1秒 空间限制：32768K 热度指数：111925
本题知识点： 数组

解题思路：
    1. 动态规划——关键：状态转移/递推函数
    2. DFS

提交记录：
    1. 存在全为负数的情况，所以初始最小不能设为 0
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        int m = array[0];  // 存在全为负数的情况
                           // 最安全的作法是赋值为数组的第一个数
        for (int i = 0; i < array.size(); i++)
        {
            int s = 0;
            for (int j = i; j < array.size(); j++)
            {
                s += array[j];
                m = max(m, s);
            }
        }

        return m;
    }
};

void
solve()
{

}
