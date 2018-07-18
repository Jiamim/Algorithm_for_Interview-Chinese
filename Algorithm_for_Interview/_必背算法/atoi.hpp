/*
把字符串转换成整数 https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0

输入描述:
    输入一个字符串,包括数字字母符号,可以为空
输出描述:
    如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
    +2147483647
    1a33

输出
    2147483647
    0

解题思路：
    int t = str[p] - '0';
    n = n*10 + t;

    各种错误条件：
        没有考虑溢出，牛客的用例比较简单
        
提交记录：

    1. tmp >= 0 && tmp <= 9 写成了 ||


*/
#pragma once
#include "../all.h"

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if (len <= 0) return 0;

        int p = 0;
        while (str[p] == ' ') p++;

        bool pos = true;
        if (str[p] == '+') {
            p++;
        }
        else if (str[p] == '-') {
            pos = false;
            p++;
        }

        int n = 0;
        while (p < len) {
            int tmp = str[p] - '0';
            if (tmp >= 0 && tmp <= 9) {
                n = n * 10 + tmp;
                p++;
            }
            else {
                return 0;
            }
        }

        return pos? n : -n;
    }
};

void solve() {
    string str{ "  123  " };

    int ret = Solution().StrToInt(str);
    print(ret);
}
