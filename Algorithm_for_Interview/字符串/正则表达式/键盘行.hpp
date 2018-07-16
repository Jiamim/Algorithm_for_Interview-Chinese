/*
500. 键盘行 https://leetcode.com/problems/keyboard-row/description/

题目描述：
    给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。

    示例1:
        输入: ["Hello", "Alaska", "Dad", "Peace"]
        输出: ["Alaska", "Dad"]
    注意:
        你可以重复使用键盘上同一字符。
        你可以假设输入的字符串将只包含字母。

思路：
    1. 先判断第一个字母属于哪一行，然后判断后面是否存在字母不属于这一行
    2. 正则表达式

    注意：大小写转换
        char c = (char)tolower(c);
*/
#pragma once

#include "../../all.h"
#include <regex>

class Solution {
public:
    // 1.
    vector<string> findWords(vector<string>& words) {
        string s[]{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };

        vector<string> ret;
        for (auto w : words) {
            // 判断第一个字母属于哪一行
            int k;
            for (k = 0; k < 3; k++)
                if (s[k].find((char)tolower(w[0])) != string::npos)
                    break;

            // 判断后面是否存在字母不属于这一行
            int OK = 1;
            for (auto c : w) {
                if (s[k].find((char)tolower(c)) == string::npos)
                    OK = 0;
            }
            if (OK)
                ret.push_back(w);
        }
        return ret;
    }
    // 2. 正则表达式
    vector<string> findWords_2(vector<string>& words) {
        regex reg{ "[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*" };
        vector<string> ret;
        smatch r;   // match_results<string::const_iterator> r;
        for (auto w : words) {
            if (regex_match(w, r, reg))
                ret.push_back(w);
        }
        return ret;
    }
};
