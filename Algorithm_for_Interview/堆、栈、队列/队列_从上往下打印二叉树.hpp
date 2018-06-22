/*
从上往下打印二叉树 https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

时间限制：1秒 空间限制：32768K 热度指数：169323

解题思路
    二叉树的层序遍历，广度优先，队列

提交记录
    1. 在循环外添加了一次根节点，循环内又加了一次
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;

        //ret.push_back(root->val);
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            ret.push_back(cur->val);

            if (cur->left != NULL)
                q.push(cur->left);
            if (cur->right != NULL)
                q.push(cur->right);
        }

        return ret;
    }
    //stack<TreeNode*> s;
    queue<TreeNode*> q;
};

void 
solve()
{

}