/*
二叉搜索树的后序遍历序列 https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

时间限制：1秒 空间限制：32768K 热度指数：185596

解题思路：
    二叉搜索树：左子树都小于根节点，右子树都大于根节点
    后序遍历，最后一个是根节点

提交记录：
    1. 超过限制内存（递归的时候老是忘记结束条件）
    2. 边界判断，结束条件  if (l >= r) return true;

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return isSquenceOfBST(sequence, 0, sequence.size() - 1);
    }

    // 为了避免复制，用一个子函数
    // l, r 是闭区间
    bool isSquenceOfBST(vector<int> &s, int l, int r) {
        if (l >= r) return true;
        int mid;  // 指向第一个大于 s[r] 的数
        // 搜索 mid
        for (mid = l; mid < r && s[mid] < s[r]; mid++);
        // 如果 mid 之后的数也都比 s[r] 大，说明满足二叉搜索树的定义
        bool flag = true;
        for (int i = mid; i < r; i++) {
            if (s[i] < s[r]) {
                flag = false;
                break;
            }
        }
        return flag && isSquenceOfBST(s, l, mid - 1) && isSquenceOfBST(s, mid, r-1);
    }
};

void solve()
{
    vector<int> v{ 2,4,3,6,8,7,5 };
    Solution().VerifySquenceOfBST(v);
}