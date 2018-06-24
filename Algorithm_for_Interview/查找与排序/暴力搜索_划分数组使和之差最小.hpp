/*
imhuay/Deep_Learning_Notes_for_Interview-Chinese https://github.com/imhuay/Deep_Learning_Notes_for_Interview-Chinese/tree/master/笔试面经/#1-今日头条-算法工程师-实习

题目来源：今日头条实习面试、编程之美

题目描述：
    将数组元素划分成两部分，使两部分和的差最小，数组顺序可变；
    返回两元素的差值
    （非 OJ 问题，只验证少量用例，可能存在 BUG）

解题思路：
    问题可以等价于“在数组中取出部分元素，使它们的和最接近 sum/2，其中 sum 为整个数组的和。”

    思路 1：
        > 将数组分成两部分使得两部分的和的差最小 - 推酷 https://www.tuicool.com/articles/ZF73Af
        此时可以将原问题看作一个背包问题
        开一个二维数组 dp[i][j] 表示：前 i 个物体装容量为 j 的背包能够装下的最大值
        状态转移方程：
            dp[i][j] = max{dp[i-1][j-ns[i]]+ns[i], dp[i-1][j]}
        其中
            dp[i-1][j-ns[i]]+ns[i] 表示第 i 个物体放入背包的情形；
            dp[i-1][j] 表示第 i 个物体不放入背包的情形

        返回值
            sum - 2 * dp[n-1][sum/2]

        以上方法虽然可行，但是相当浪费空间：容量 j 显然不是连续的自然数，还有可能发生溢出

    思路 2：
        （暴力搜索）遍历数组 N 的所有子集 I，求 2*abs(sum(N)/2 - sum(I))，取最小，即为返回值
        > ../常用子函数/遍历子集

        注意点：
        - sum(N)/2 可能是浮点数，所以中间结果应该存为 double 类型
        - 最后返回值是 2 * abs(sum(N)/2 - sum(I))，而不是 abs(sum(N)/2 - sum(I))

*/
#pragma once

#include "../all.h"

class Solution {
public:
    // 思路 2
    int getMaxDiff(vector<int>& nums) {

        vector<vector<int>> subsets;
        getAllSubsets(nums, subsets);

        double sum = getSum(nums);
        double diff = INF;
        for (auto sub : subsets) {
            diff = min(diff, abs(sum / 2 - getSum(sub)));
        }
        
        return diff * 2;
    }

    double getSum(vector<int>& nums) {
        double sum = 0;
        for (auto i : nums)
            sum += i;
        return sum;
    }

    void getAllSubsets(vector<int>& vs, vector<vector<int>>& subsets) {
        subsets.push_back({});

        vector<vector<int>> tmp;
        for (auto i : vs) {
            for (auto sub : subsets) {
                sub.push_back(i);
                tmp.push_back(sub);
            }
            for (auto sub : tmp) {
                subsets.push_back(sub);
            }
            tmp.clear();
        }
    }
};

void
solve()
{
    vector<int> nums{ 2,5,6,10 };

    auto ret = Solution().getMaxDiff(nums);

    print(ret);
}