/*
583. 两个字符串的删除操作 - LeetCode (中国) https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/

问题描述：

    给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
    示例 1:
        输入: "sea", "eat"
        输出: 2
        解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
    说明:
        给定单词的长度不超过500。
        给定单词中的字符只含有小写字母。

思路：
    动态规划，参考 "./编辑距离.hpp" 的递推公式：
        dp[i][j] = 0                                                i=0, j=0
                 = i                                                i>0, j=0
                 = j                                                i=0, j>0
                 = dp[i-1][j-1]                                     A[i-1] == B[j-1]
                 = min{dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1}  A[i-1] != B[j-1]
    区别在于最后一种情况
        因为当
        dp[i][j] = min{dp[i-1][j]+1,  // 删除 word1 中的一个字符
                       dp[i][j-1]+1,  // 删除 word2 中的一个字符
                       dp[i-1][j-1]+2 // 同时删除 word1 和 word2 中的一个字符，所以需要添加两步
                       }  A[i-1] != B[j-1]

    另一种动态思路是“最长公告子序列”，没有深入，可以参考官方解析
    > 官方解析 (5) https://leetcode.com/problems/delete-operation-for-two-strings/solution/
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (size_t i = 1; i <= m; i++)
            dp[i][0] = i;
        for (size_t i = 1; i <= n; i++)
            dp[0][i] = i;
        for (size_t i = 1; i <= m; i++)
            for (size_t j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2 });
            }

        return dp[m][n];
    }
};

void
solve()
{

}