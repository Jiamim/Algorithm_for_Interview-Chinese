/*
替换空格 https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

时间限制：1秒 空间限制：32768K 热度指数：539801
本题知识点： 字符串

假设：不能使用 replace函数，且在原字符串上进行替换（长度足够）

提交记录：
    第一次提交失败，没有手动设 '\0'，我以为编译器会将 '\0'之后的内存都设为 '\0'
*/

#pragma once

#include "../all.h"

class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == NULL || length < 0)
            return;

        int l_old = strlen(str);
        //print(l_old);
        int n_space = count(str, str + l_old, ' ');
        //print(n_space);
        int l_new = l_old + n_space * 2;
        //print(l_new);
        str[l_new] = '\0';

        int p_old = l_old-1;
        //print(str[p_old]);
        int p_new = l_new-1;
        while (p_old >= 0) {
            if (str[p_old] != ' ') {
                str[p_new--] = str[p_old--];
            }
            else {
                p_old--;
                str[p_new--] = '0';
                str[p_new--] = '2';
                str[p_new--] = '%';
            }
        }
    }
};

void solve() {
    const int length = 100;
    char cs[length] = "   ";

    Solution().replaceSpace(cs, length);
    print(cs);
}