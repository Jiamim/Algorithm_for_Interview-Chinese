/*
538. 把二叉搜索树转换为累加树 https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/

题目描述：
    给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

    例如：
        输入: 二叉搜索树:
                      5
                    /   \
                   2     13
        输出: 转换为累加树:
                     18
                    /   \
                  20     13

思路：
    递归：（逆中序遍历）
        右子树
        累加
        左子树
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int sum;

    TreeNode * convertBST(TreeNode* root) {
        if (root == NULL) return root;
        sum = 0;
        convert(root);
        return root;
    }

    void convert(TreeNode* cur) {
        if (cur == NULL) return;
        convert(cur->right);
        cur->val += sum;
        //sum += cur->val;  // err
        sum = cur->val;     // cur->val 已经累加过了
        convert(cur->left);
    }
};

void
solve()
{

}