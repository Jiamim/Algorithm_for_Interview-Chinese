#pragma once
#define _CRT_SECURE_NO_WARNINGS  // 必须放在第一行

#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

// 容器
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <list>

#include <functional>
#include <climits>
#include <algorithm>

using namespace std;

template<class T>
void
print(T t) {
    cout << t << endl;
}

// 常亮
#define EPSILON     10e-5
#define INF         0x3f3f3f3f
#define N1000       1000

// 二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 线索树
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

// 链表
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};