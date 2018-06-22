/*
和为S的连续正数序列 https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

时间限制：1秒 空间限制：32768K 热度指数：102416

思路描述：
    1. 暴力搜索
    2. 优化方案（来自讨论区）
        a. 根据公式找出中间值
        b. 双指针移动
        因为感觉这题价值不大，就不深究了

提交记录：
    1. 搜索范围出错，用例 3 没有通过
        修改 i < sum / 2  ->  i < (sum+1) / 2

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;

        for(int i = 1; i < (sum+1) / 2; i++)
        {
            for (int j = i + 1; j < (sum + 1) / 2 + 1; j++)
            {
                if (getSum(i, j) == sum)
                    ret.push_back(getVec(i, j));
            }
        }

        return ret;
    }

    vector<int> getVec(int m, int n) {
        vector<int> ret;
        for (int i = m; i <= n; i++)
            ret.push_back(i);
        return ret;
    }

    int getSum(int m, int n) {
        return (m + n)*(n - m + 1) / 2;
    }
};

void
solve()
{
    Solution().FindContinuousSequence(3);
}
