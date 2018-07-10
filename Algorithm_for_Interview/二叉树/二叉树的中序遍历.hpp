/*
二叉树的中序遍历 - LeetCode (中国) https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/

题目来源：LeetCode

题目描述：
    给定一个二叉树，返回它的中序 遍历。

解题思路：
    递归：O(n) 时间 O(n) 空间
    迭代：O(n) 时间 O(n) 空间
    Morris traversal 方法：：O(n) 时间 O(1) 空间

    ref: Clear C++ solutions --- iterative, recursive and Morris traversal (3 different solutions!) - LeetCode Discuss 
    https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/Clear-C++-solutions-iterative-recursive-and-Morris-traversal-(3-different-solutions!)

    关于 Morris 方法的详细解释：
        Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间） - AnnieKim - 博客园 
        https://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html

提交记录：
    1. 搞错了逻辑，应该时 root 不为空时，进入递归
        建议不要直接写 if(root) 和 if(!root)，
        而写成 if (root != NULL) 和 if(root == NULL)

*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root != NULL)
            inorderTraversal(root, ret);
        return ret;
    }

    void inorderTraversal(TreeNode* root, vector<int>& ret) {
        if (root->left != NULL)
            inorderTraversal(root->left, ret);
        ret.push_back(root->val);
        if (root->right != NULL)
            inorderTraversal(root->right, ret);
    }
};