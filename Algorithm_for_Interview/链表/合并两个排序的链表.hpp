/*
合并两个排序的链表 https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

时间限制：1秒 空间限制：32768K 热度指数：222733
本题知识点： 链表

解题思路：
    用两个指针依次顺移，
    循环的条件是两个指针均不为 NULL
    最后必然有一个链表先到尾，注意最后的拼接操作

提交记录
    1. 链表头处理不当，不应该在循环内处理，导致结果总为 NULL；
        应该在循坏外线把第一个位置处理好
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL) {
            return pHead2;
        }
        if (pHead2 == NULL) {
            return pHead1;
        }
        
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* ret;
        if (p1->val < p2->val) {
            ret = p1;
            p1 = p1->next;
        }
        else {
            ret = p2;
            p2 = p2->next;
        }
        ListNode* cur = ret;
        while (p1 && p2) {
            
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }

        if (p1) cur->next = p1;
        if (p2) cur->next = p2;

        return ret;
    }
};

void 
solve()
{

}