/*
二叉树的镜像 https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：
源二叉树
     8
   /  \
  6   10
 / \  / \
5  7 9 11
镜像二叉树
     8
   /  \
  10   6
 / \  / \
11 9 7  5

解题思路：
    1. 层序遍历 + 栈 （pass）
    2. 先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子节点，
        当交换完所有的非叶子结点的左右子结点之后，就得到了树的镜像（讨论区）

提交记录：
    1. 结束标志设置错误
    2. 多余的标记
*/
#pragma once

#include "../all.h"

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) return;
        //if (pRoot->left == NULL && pRoot->right == NULL)
        //    return;
        // 即使左右子树都为 NULL，也不会报错，就是交换两个指向 NULL 的指针
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};