/*
516. 最长回文子序列 - LeetCode (中国) https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/

题目描述：
    给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

    示例 1:
        输入:
            "bbbab"
        输出:
            4
        一个可能的最长回文子序列为 "bbbb"。

    示例 2:
        输入:
            "cbbd"
        输出:
            2
        一个可能的最长回文子序列为 "bb"。

思路：
    经典的动态规划问题
    记：
        dp[i][j] := 子串 s[i..j] 的最长回文子序列的大小
    初始化：
        dp[i][j] = 1    i=j
                 = 0    other
    递推公式：
        dp[i][j] = dp[i+1][j-1] + 2             s[i]==s[j]
                 = max(dp[i+1][j], dp[i][j-1])  other
        如果 `i+1=j` 且 `s[i]=s[j]`时，`dp[i][j] = dp[i+1][j-1] + 2` 依然成立，
        因为 `i != j` 时，有 `dp[i][j] = 0`

    注意，如果按照上面的 dp 定义，返回值应该是 dp[1][n] 而不是 dp[n][n]

    明白状态转移之间的关系是理解所有动态规划问题的关键，也是难点
        s[i]==s[j] 时，s[i..j] 的上一个状态应该是 s[i+1..j-1]，而不是 s[i+1..j+1] 或者其他，明白这一点是理解本题的关键
        s[i]!=s[j] 时，s[i..j] 的上一个状态应该是 s[i+1..j] 或 s[i..j-1]，而不是 s[i+1..j+1] 等等
    暂不考虑 DP 的优化
    > [Straight forward Java DP solution](https://leetcode.com/problems/longest-palindromic-subsequence/discuss/99101/Straight-forward-Java-DP-solution) - LeetCode (EN) 讨论区

    状态更新的顺序也是一个注意点：
    正确示例：
        for (int i = n-1; i >= 0; i--)          // 子串开始位置
            for (int j = i + 1; j < n; j++) {   // 子串结束位置

        for (int j = 1; j < n; j++)             // 子串结束位置
            for (int i = j-1; i >=0; i--) {     // 子串开始位置

    错误示例：
        for (int j = 1; j < n; j++)         // 子串结束位置
            for (int i = 0; i < j; i++) {   // 子串起始位置
        // 但是该顺序在 "./最长回文子串.hpp" 中是正确的

    注意：
        因为 DP 的定义为了便于理解，下标常从 1 开始，这与一般容器的下标不同，所以
        应该使用编码时应该使用 `s[i-1]==s[j-1]` 而不是 `s[i]==s[j]`

        **当然也可以在编码时将 DP 的下标也调整至从 0 开始**
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        /* 更直观的循环方式
        */
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int j = 1; j < n; j++)             // 子串结束位置
            for (int i = j-1; i >=0; i--) {     // 子串开始位置
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }

        return dp[0][n - 1];

        /* 下标从 0 开始
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n-1; i >= 0; i--)
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }

        return dp[0][n-1];
        */

        /*下标从 1 开始
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][i] = 1;
        for (int i = n; i >=1; i--)
            for (int j = i+1; j <= n; j++) {
                if (s[i-1] == s[j-1])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max({ dp[i + 1][j], dp[i][j - 1] });
            }
        
        return dp[1][n];
        */
    }
};

void
solve()
{

}