/*
二叉树中和为某一值的路径 https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

时间限制：1秒 空间限制：32768K 热度指数：167478

解题思路：
    带记忆的 DFS, 递归

提交记录：
    1. 递归结束条件始终有问题；
        注意路径终点是叶节点，而不是子节点

*/
#pragma once

#include "../all.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> trace;

    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if (root)
            dfs(root, expectNumber);
        return ret;
    }

    void dfs(TreeNode* cur, int n) {
        trace.push_back(cur->val);
        // 结束条件
        if (!cur->left && !cur->right) {
            if (cur->val == n)
                ret.push_back(trace);  // ret 的类型是 vector<int>，所以会传入副本
                                       // 如果是 Java 的话，可能需要手动 new 一个当前路径的副本
        }
        if (cur->left)
            dfs(cur->left, n - cur->val);
        if (cur->right)
            dfs(cur->right, n - cur->val);
        trace.pop_back();
    }
};