/*
无重复字符的最长子串 - LeetCode (中国) https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/

题目来源：LeetCode

题目描述：
    给定一个字符串，找出不含有重复字符的最长子串的长度。

    示例：

    给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
    给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
    给定 "pwwkew" ，最长子串是 "wke" ，长度是3。
    
    请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。

    时间复杂度： O(n)

解题思路：
    使用一个 map 记录并更新每个字符的位置，一个变量记录当前最长子串长度
    关键是如何更新当前子串的始末位置

    每当碰见一个重复字符时，则**当前**无重复字串长度 m = j - i，其中 j 为重复字符当前的位置，i 为该字符上一次出现的位置
    如果没有重复，那么 j++
    e.g.
        i  j
        abcabcbb  -> m = j-i = 3-0 = 3
         i  j
        abcabcbb  -> m = j-i = 4-1 = 3
            i j
        abcabcbb  -> m = j-i = 6-4 = 2

提交记录：
    1. 用例 abba 未通过，预期：2，实际：3 = 3 - 0 (a)
        修改：只有当 dict[s[j]] > i 时，才更新 i = dict[s[j]];
        本例中：因为 dict['a'] < i_b 所以，不更新 i
    2. 修改后 AC

*/
#pragma once
#include "../all.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 1)
            return 0;

        const int pad = -1;
        vector<int> dict(256, pad);
        int m = 0;
        int i = -1, j = 0; // 开始时 j-i = 1

        while (j < s.length()) {
            if (dict[s[j]] > i) // 关键
                i = dict[s[j]];
            dict[s[j]] = j;
            m = max(m, j - i);
            j++;
        }

        return m;
    }

    // 参考答案
    int lengthOfLongestSubstring_参考(string s) {
        if (s.length() < 1)
            return 0;
        
        vector<int> dict(256, -1);
        int maxLen = 0;
        int start = -1;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }
};


void
solve()
{

}
