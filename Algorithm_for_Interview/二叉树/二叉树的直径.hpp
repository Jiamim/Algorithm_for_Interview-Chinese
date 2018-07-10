/*
543. 二叉树的直径 - LeetCode (中国) https://leetcode-cn.com/problems/diameter-of-binary-tree/description/

问题描述：

    给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

    示例 :
        给定二叉树
            1
           / \
          2   3
         / \
        4   5
        返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

        注意：两结点之间的路径长度是以它们之间边的数目表示。

思路：
    任意两点间的路径 = 所在子树的深度相加

    两次递归
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int d = depth(root->left) + depth(root->right);
        return max({ d, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right) });
    }

    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max({ depth(root->left), depth(root->right) });
    }
};

void
solve()
{

}