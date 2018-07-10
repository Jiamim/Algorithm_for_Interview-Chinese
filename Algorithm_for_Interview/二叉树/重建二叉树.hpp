/*
重建二叉树 https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

时间限制：1秒 空间限制：32768K 热度指数：313348

提交记录：
    参考自讨论区的 Java 代码
    有思路，但写不出（递归太神奇了）

改进建议：
    可以使用传索引的方式避免新建 vector，但这样要新写一个子函数，考虑到测试时没有效率问题，就没这么做

笔记：
    例子 
        前序 {1,2,4,7,3,5,6,8}、 中序 {4,7,2,1,5,3,8,6}
    以前用中序和前序重建二叉树时，每次只关注前序的第一个值，用来分割中序；
        也就是只关注前序中的 1 将中序分成 {4,7,2} 和 {5,3,8,6}
    实际上，{4,7,2} 和 {5,3,8,6} 也帮前序划分成了 {2,4,7} 和 {3,5,6,8}
        手绘的时候这一步并不重要，但是代码重构时，需要知道下一步递归的子树
        这里就是 {4,7,2} 和 {2,4,7}，及 {5,3,8,6} 和 {3,5,6,8}
        它们分别是左右子树的 前序 和 中序 遍历结果
    到这里，递归的思路就明朗多了
*/

#pragma once


#include "../all.h"

class Solution {
public:
    TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() <= 0)
            return NULL;

        TreeNode* root = new TreeNode{ pre[0] };
        for (auto i = 0; i < vin.size(); i++) {
            if (vin[i] == pre[0]) {
                root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + i), vector<int>(vin.begin(), vin.begin() + i));
                root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + i, pre.end()), vector<int>(vin.begin() + 1 + i, vin.end()));
            }
        }
        return root;
    }
};