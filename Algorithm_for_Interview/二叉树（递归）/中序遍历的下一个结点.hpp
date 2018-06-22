/*
二叉树的下一个结点 https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

时间限制：1秒 空间限制：32768K 热度指数：71769

解题思路：
    中序遍历的过程，不同的情况讨论
    1.二叉树为空，则返回空；
    2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
    3.如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
    

提交记录：
    1. 情况 3 操作有误

*/
#pragma once

#include "../all.h"

class Solution {
public:
    TreeLinkNode * GetNext(TreeLinkNode* pNode)
    {   
        if (pNode == NULL)
            return pNode;

        if (pNode->right != NULL) {
            auto p = pNode->right;
            while (p->left != NULL)
                p = p->left;
            return p;
        }

        auto c = pNode;     // 当前子节点
        auto p = c->next;   // 当前子节点的父节点
        while (p != NULL)   // 根节点的父节点为 NULL
        {
            if (p->left == c)
                return p;
            c = p;          // 当前子节点指向父节点
            p = p->next;    // 父节点指向下一个父节点
        }

        return NULL;
    }
};

void
solve()
{

}