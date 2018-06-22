/*
平衡二叉树 https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

时间限制：1秒 空间限制：32768K 热度指数：89960

解题思路：
    平衡树的性质
    递归

    讨论区推荐答案提到了该解答存在的问题：“这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，增加了不必要的开销。”
    解决方案：后序遍历 + 剪枝（做法相当巧妙）
    
    注意：剪枝的做法 Math.abs(leftHeight - rightHeight) > 1 ? -1 : 1 + Math.max(leftHeight, rightHeight);

    public class Solution {
        public boolean IsBalanced_Solution(TreeNode root) {
            return getDepth(root) != -1;
        }

        private int getDepth(TreeNode root) {
            if (root == null) {
                return 0;
            }
            int leftHeight = getDepth(root.left);
            if (leftHeight == -1) {
                return -1;
            }
            int rightHeight = getDepth(root.right);
            if (rightHeight == -1) {
                return -1;
            }
            return Math.abs(leftHeight - rightHeight) > 1 ? -1 : 1 + Math.max(leftHeight, rightHeight);
        }
    }
提交记录：
    1. pass
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        
        return abs(depthTree(pRoot->left) - depthTree(pRoot->right)) <= 1 
            && IsBalanced_Solution(pRoot->left) 
            && IsBalanced_Solution(pRoot->right);
    }

    int depthTree(TreeNode* pRoot) {
        if (pRoot == NULL) return 0;

        return 1 + max(depthTree(pRoot->left), depthTree(pRoot->right));
    }
};

void solve() {

}