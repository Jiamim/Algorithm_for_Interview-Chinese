/*
563. Binary Tree Tilt - LeetCode https://leetcode.com/problems/undefined/description/

题目描述：
    给定一个二叉树，计算整个树的坡度。

    一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

    整个树的坡度就是其所有节点的坡度之和。

思路：
    递归
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = abs(getSum(root->left) - getSum(root->right));
        return sum + findTilt(root->left) + findTilt(root->right);
    }

    int getSum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
};

void
solve()
{

}