/*
树的子结构 https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

时间限制：1秒 空间限制：32768K 热度指数：219165

解题思路：
    1. 先考虑怎么判断 T1 和 T2 是否完全相同
        如果根节点相同，判断两者的左子树和右子树 -> 递归

    2. 判断是不是子结构
        先找到 T1 中根节点 跟 T2 一致的节点，从该节点开始 1 的过程

提交记录：
    1. 递归的结束语句写不对
    2. 写完还觉得不错，一对比自己写的真是太丑了，下面的答案来自讨论区
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL || pRoot1 == NULL)
            return false;

        return isSubTree(pRoot1, pRoot2)
            || HasSubtree(pRoot1->left, pRoot2)
            || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;

        if (pRoot1->val == pRoot2->val) {
            return isSubTree(pRoot1->left, pRoot2->left)
                && isSubTree(pRoot1->right, pRoot2->right);
        }
        else
            return false;
    }
};


void
solve()
{

}