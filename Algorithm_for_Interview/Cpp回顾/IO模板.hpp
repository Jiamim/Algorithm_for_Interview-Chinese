/*
有些网络笔试不是 LeetCode 的形式，需要手动输入输出，特此记录

常见输入方式：
    1. 输入不说明有多少个 Input，以 EOF 为结束标志
    2. 指示有 N 个 Input
    3. 输入不说明有多少个 Input，以某个特殊输入为结束标志
    4. 多组输入，以某个特殊输入退出（2 与 1 或 3 组合）
    5. 输入是一整行的字符串（带空格）
    6. 输入是多行字符串（带空格）
    7. 从文件中那个读取，而不是 cin 或 cout

输出：
    是否换行，换几行，换行还是空格要看具体问题
    
> ACM学习历程2——ACM题目中常用的输入输出方式 - CSDN博客 https://blog.csdn.net/u010480899/article/details/52280065
*/
#pragma once

#include "../all.h"

#define MAXN 1000

class Solution {
public:
    void foo() {
    /* 1. 输入不说明有多少个 Input，以 EOF 为结束标志*/
        int a, b;
        // C 方式
        while (scanf("%d %d", &a, &b) != EOF) {  // scanf 返回值为读出变量的个数，如果没有返回 -1，EOF 是一个预定义的常亮 -1
            //
        }
        // C++
        while (cin >> a >> b) {
            //
        }

    /*2. 指示有 N 个 Input*/
        // C
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
        }
        // C++
        cin >> n;
        while(n--) {
            cin >> a >> b;
        }

    /*3. 输入不说明有多少个 Input，以某个特殊输入为结束标志*/
        // C
        // 示例 1
        //while (scanf("%d %d", &a, &b) && (a != 0 && b != 0)) {
        while (scanf("%d %d", &a, &b) && (a || b)) {  // 更简洁的写法
            printf("%d\n", a + b);
            // 是否换行，换几行，换行还是空格要看具体问题
        }
        // 示例 2
        while (scanf("%d", &n) != EOF && n != 0) {
            cout << a + b << endl;
        }

        // C++
        // 示例 1
        while (cin >> a >> b) {
            if (a == 0 && b == 0)
                break;
            //
        }
        // 示例 2
        while (cin >> n && n != 0) {
            //
        }

    /*4. 多组输入，以某个特殊输入退出（2 与 3 组合）*/
        // C++
        while (cin >> n && n != 0) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                cin >> a;
                tmp.push_back(a);
            }
        }

    /*5. 输入是一整行的字符串（带空格）*/
        // 1）用 char[] 接收
        // C
        char buff[MAXN];  // MAXN = 1000
        gets(buff);  // VS 2017 中找不到此函数
        // C++
        cin.getline(buff, MAXN);  // 第三个参数默认是 '\n'
        cin.getline(buff, MAXN, '\n');  // 第三个参数默认是 '\n'
        
        // 2）用 string 接收
        string s;
        getline(cin, s);
        getline(cin, s, '\n');  // 类似的，第三个参数也是默认 '\n'，注意，接收的字符串中不会包括该字符

    /*6. 输入是多行字符串（带空格）*/
        cin >> n;
        cin.get();  // 必须，否则，n 也会计入下面的 getline()，导致少一组数据
        while (n--) {
            string s;
            getline(cin, s);
        }

    /*7. 从文件中那个读取，而不是 cin 或 cout*/
        // C
        FILE *cfin = fopen("in.txt", "r");
        FILE *cfout = fopen("out.txt", "w");
        int a, b;
        while (fscanf(cfin, "%d %d", &a, &b) != EOF) { // 类似的，把 scanf 换成 fscanf
            fprintf(cfout, "%d\n", a + b);
        }
        fclose(cfin);
        fclose(cfout);

        // C++
        ifstream fin("in.txt");
        ofstream fout("out.txt");
        int a, b;
        while (fin >> a >> b) {
            fout << a + b;
        }
        fin.close();
        fout.close();
    }
};