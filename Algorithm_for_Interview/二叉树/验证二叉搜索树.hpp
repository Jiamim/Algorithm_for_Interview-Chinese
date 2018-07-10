/*
验证二叉搜索树 - LeetCode (中国) https://leetcode-cn.com/problems/validate-binary-search-tree/description/

题目来源：LeetCode

题目描述：
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。

    一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

    示例 1:
    输入:
      2
     / \
    1   3
    输出: true

    示例 2:
    输入:
        5
       / \
      1   4
     / \
    3   6
    输出: false
    解释: 输入为: [5,1,4,null,null,3,6]。
    根节点的值为 5 ，但是其右子节点值为 4 。

解题思路：
    递归

提交记录：
    1. 当前节点要大于/小于整个左子树/右子树
    在判断左右子树时，要同时传入他们的父节点，作为整体的最大值/最小值

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};