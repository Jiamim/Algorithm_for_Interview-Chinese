/*
72. 编辑距离 - LeetCode (中国) https://leetcode-cn.com/problems/edit-distance/description/

问题描述：
    给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
    你可以对一个单词进行如下三种操作：
        插入一个字符
        删除一个字符
        替换一个字符
    示例 1:
        输入: word1 = "horse", word2 = "ros"
        输出: 3
        解释:
            horse -> rorse (将 'h' 替换为 'r')
            rorse -> rose (删除 'r')
            rose -> ros (删除 'e')
    示例 2:
        输入: word1 = "intention", word2 = "execution"
        输出: 5
        解释:
            intention -> inention (删除 't')
            inention -> enention (将 'i' 替换为 'e')
            enention -> exention (将 'n' 替换为 'x')
            exention -> exection (将 'n' 替换为 'c')
            exection -> execution (插入 'u')

思路：
    动态规划-经典问题
    > Edit Distance - LeetCode https://leetcode.com/problems/edit-distance/discuss/25846/20ms-Detailed-Explained-C++-Solutions-(O(n)-Space)

    记两个字符串分别为 A[0..m-1] 和 B[0..n-1]
    记 dp[i][j] := 串A 前 i 个字符与 串B 前 j 个字符的编辑距离

    1. 考虑边界情况：其中一个字符串为空串，显然此时从 s[0..i-1] 转换为 "" 至少需要 i次 操作，因此有

        dp[i][0] = i
        dp[0][j] = j

    2. 一般情况，考虑 A串的第 i 个字符和 B串的第 j 个字符
        假设已知 dp[i-1][j-1]，即从 A[0..i-2] 转换为 B[0..j-2] 需要的次数
        1）如果 A[i] == B[j]，那么 dp[i][j] == dp[i-1][j-1]
        2）如果 A[i] != B[j]，对串A 有三种可能的操作（对串B 是对称的）：
            a. 替换一个字符 dp[i][j] = dp[i-1][j-1] + 1
            b. 删除一个字符 dp[i][j] = dp[i-1][j] + 1，此时应有 A[0..i-2] == B[0..j-1]，所以需要从 A 删除中的一个字符
            c. 插入一个字符 dp[i][j] = dp[i][j-1] + 1，此时应有 A[0..i-1] == B[0..j-2]，所以需要向 A 插入中的一个字符
        
        问题的难点在于理解后这 3 种情况

    由此可得递推公式：

        dp[i][j] = 0                                                i=0, j=0
                 = i                                                i>0, j=0
                 = j                                                i=0, j>0
                 = dp[i-1][j-1]                                     A[i-1] == B[j-1]
                 = min{dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1}  A[i-1] != B[j-1]

    原帖还提供了空间优化的方案，只需要 O(m) 或 O(n) 的空间复杂度，这里不再深入。
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
        for (size_t j = 1; j <= n; j++)
            dp[0][j] = j;
        for (size_t i = 1; i <=m; i++)
            for (size_t j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
            }
        return dp[m][n];
    }
};

void
solve()
{

}