/*
二叉树的深度 https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

时间限制：1秒 空间限制：32768K 热度指数：73915

解题思路：
    树的递归定义

提交记录：
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;

        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};

void solve()
{
    TreeNode t1{ 1 };
    TreeNode t2{ 2 };
    TreeNode t3{ 3 };
    TreeNode t4{ 4 };

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;

    int ret = Solution().TreeDepth(&t1);
    print(ret);
}
