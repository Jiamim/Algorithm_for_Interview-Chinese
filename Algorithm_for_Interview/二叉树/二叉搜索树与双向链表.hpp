/*
二叉搜索树与双向链表 https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

时间限制：1秒 空间限制：32768K 热度指数：115280

解题思路：
    中序遍历的过程中修改指针

提交记录：
    1. 又一次递归失败，答案来自讨论区

*/
#pragma once

#include "../all.h"

class Solution {
public:
    TreeNode * pre;  // 记录上一个节点
    TreeNode * ret;  // 记录中序遍历的第一个节点

    TreeNode * Convert(TreeNode* pRootOfTree) {
        // C++ 小坑，默认初始化不为 NULL
        pre = NULL;
        ret = NULL;
        subCovert(pRootOfTree);
        return ret;
    }
    
    // 中序遍历
    void subCovert(TreeNode* node) {
        if (!node) return;

        subCovert(node->left);
        // 修改指针的逻辑
        if (pre == NULL) {  // 到达中序遍历的第一个位置，即链表头
            pre = node;
            ret = node;
        }
        else {
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        subCovert(node->right);
    }
};
