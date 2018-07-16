/*
在线笔试好像很喜欢考 string 相关的问题

C++ 很麻烦的一点是，很多时候 string 和 char* 不能通用

Python 中的字符串处理非常方便，
所以以下相关整理会以 Python 中常用的操作为标准，给出相应的 C++ 处理方式

主要操作：
    1. string 与 char* 的转换           - Python 中没有该问题
        (1). string 转 const char*
        (2). const char* 转 string
        (3). string 转 char*
        (4). char* 转 string
        (5). const char* 转 char*
    2. string/char* 与 int 的转换       - int(str) / str(int)
    3. string/char* 的长度              - len(str)
    （todo）
    4. 字符串拼接
    5. trim(): 去除首尾空白符
    6. split(): 分割字符串

注意点：
    1. const char* 不能用于初始化 char*
*/
#pragma once

#include "../all.h"
#include <string>

class Solution {
public:
    void test() {
    /*1. string 与 char* 的转换*/
        //(1). string 转 const char*
        string s = "abc1";
        // char* c_s = s.c_str();  // err: const char* 不能用于初始化 char*
        const char* cs = s.c_str();
        
        //(2). const char* 转 string
        const char* cs2 = "abc2";
        string s2 = cs2;
        string s3(cs2);
        string s4{ cs2 };  // 以上写法可以认为等价

        //(3). string 转 char*
        string s5 = "abc3";
        int len = s.length();
        char* cs3 = new char[len + 1];
        strcpy(cs3, s.c_str());

        //(4). char* 转 string
        char cs4[64] = "abc4";
        char *cs5 = new char[64]{ "abc5" };
        char cs6[] = "abc6";            // 注意：不能 char *cs6 = "abc6"
        cout << strlen(cs6) << endl;
        string s6(cs6);
        cout << s6 << endl;
        //
        string s7{ "" };
        for (size_t i = 0; i < strlen(cs6); i++)    // char* 转 string 更直观的写法
            s7 += cs6[i];
        cout << s7 << endl;

        //(5). const char* 转 char*
        // 一种方法是使用 strcpy()
        const char* cs7 = "abc7";
        char* cs8 = new char[strlen(cs7) + 1]; // 足够长
        strcpy(cs8, cs7);
        cout << cs8 << endl;
        // 最简单的方法当然就是强转
        char* cs9 = (char*)cs7;
        char* cs10 = (char*)"abc8";      // 这也是将 const char* 转 char*

    /*2. string/char* 与 int 的转换*/
        char c1[] = "123";
        string si{ c1 };
        int i1;

        // char* 转 int
        i1 = atoi(c1);      // char* 转 int
        // i1 = atoi(s1);   // atoi 不能用于 string 转 int

        // string 转 int - C++11
        i1 = stoi(c1);  // stoi 也支持 char* 转 int
        i1 = stoi(si);

        // int 转 char*
        char c2[32];
        //sprintf(c2, "%d", i1);    // 法1
        //itoa(i1, c2, 10);         // 遗弃
        _itoa(i1, c2, 10);          // 法2，不推荐。LeetCode 好像不支持该方法

        // int 转 string
        si = to_string(i1);
        cout << si << endl;

    /*3. string / char* 的长度*/
        // char* 的长度
        len = strlen(cs);
        // string 的长度
        len = s.length();
    }

    vector<string> split(string &s, string &delim) {
        // 假设字符串的开头不会出现 delim
        vector<string> ret;

        auto lo = s.begin();
        while (true) {
            auto hi = find(lo, s.end(), ' ');
            ret.push_back(string(lo, hi));
            if (hi != s.end())
                lo += delim.length();
            else
                break;
        }

        return ret;
    }
};

void
solve()
{
    //Solution().test();
    string s{ "abcbbbabc" };
    string d{ "bbb" };
    auto it = s.find(d);
    cout << it;
    /*
    auto ret = Solution().split(s, d);
    for (auto i : ret)
        cout << i << endl;*/


}