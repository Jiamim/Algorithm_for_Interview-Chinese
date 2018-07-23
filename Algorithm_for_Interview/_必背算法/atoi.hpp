/*
atoi() 的功能:
    将字符串（C风格）转换成整型；
    atoi() 会跳过前面的空格字符，直到遇上数字或正负号才开始做转换，
    而再遇到 非数字 或 结束符('\0') 时结束转化，并将结果返回（返回转换后的整型数）
    *内置 atoi 不会处理 NULL 指针
    
    合法样例：
        "123"           -> 123
        "+123"          -> 123
        "-123"          -> -123
        "123abc"        -> 123
        "   123abc"     -> 123
        "a123"          -> 0

OJ:
    把字符串转换成整数 https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    题目来源：剑指Offer

核心代码：
    while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + (*p - '0');
        p++;
    }

*/
#pragma once
#include "../all.h"

int atoi_my(const char* const cs) {
    if (cs == NULL) return 0;

    int ret = 0;
    int sign = 1;
    auto *p = cs;  // cs 为常指针

    // 跳过前面的空格
    while (isspace(*p)) p++;

    // 判断正负
    if (*p == '-') sign = -1;
    if (*p == '-' || *p == '+') p++;

    // 首个非空字符不是数字，注意与判断正负的顺序
    // if (*p < '0' && *p > '9') return 0;       // 不需要

    // 循环转换整数（核心代码）
    while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + (*p - '0');
        p++;
    }

    return ret * sign;
}

void solve() {
    print(atoi_my("123"));
    print(atoi_my("+123"));
    print(atoi_my("-123"));
    print(atoi_my("   123abc"));
    print(atoi_my("   +123abc"));
    print(atoi_my("   -123abc"));
    print(atoi_my("   123abc   "));
    print(atoi_my("   +123abc   "));
    print(atoi_my("   -123abc   "));
    print();
    print(atoi_my("a123"));
    print(atoi_my("+a123"));
    print(atoi_my("-a123"));
    print(atoi_my("a123   "));
    print(atoi_my("+a123   "));
    print(atoi_my("-a123   "));
    print(atoi_my("   a123"));
    print(atoi_my("   +a123"));
    print(atoi_my("   -a123"));
    print(atoi_my("   a123   "));
    print(atoi_my("   +a123   "));
    print(atoi_my("   -a123   "));
    print(atoi_my("   a+123   "));
    print(atoi_my("   a-123   "));
    print();
    const char p[] = "   123abc";
    print(atoi_my(p));
    print(p);
    print();
    print(atoi_my(NULL));
}
