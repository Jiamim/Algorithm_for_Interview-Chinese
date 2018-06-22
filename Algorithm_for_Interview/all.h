#pragma once
#pragma once

#include <iostream>
#include <string>
#include <sstream>

// ÈÝÆ÷
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};