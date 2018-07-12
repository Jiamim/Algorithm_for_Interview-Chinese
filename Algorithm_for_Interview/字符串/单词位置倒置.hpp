/*
单词位置倒置

题目来源：华为笔试
*/
#pragma once

#include "../all.h"

//#include "all.h"
//#include "test.hpp"
//#include "常用子函数/遍历子集（递归）.hpp"
//#include "动态规划/最长回文子串.hpp"
//#include "utils/位运算.hpp"

#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int _main() {

    stack<string> tmp;
    string s;
    getline(cin, s);
    auto it = s.begin();
    while (it != s.end()) {
        auto to = find(it, s.end(), ' ');
        tmp.push(string(it, to));
        if (to != s.end())
            it = to + 1;
        else
            break;
    }

    stringstream ss;
    while (!tmp.empty()) {
        ss << tmp.top() << ' ';
        tmp.pop();
    }

    cout << ss.str();

    system("PAUSE");
    return 0;
}