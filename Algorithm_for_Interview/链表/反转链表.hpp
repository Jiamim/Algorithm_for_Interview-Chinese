/*
反转链表 https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个链表，反转链表后，输出链表的所有元素。

时间限制：1秒 空间限制：32768K 热度指数：236616
本题知识点： 链表

解题思路：
    1. 基础考点肯定是指针的移动了
    2. 还是想试一下栈

提交记录：
    1. 尝试栈再次失败（本机调试感觉没问题了）
    2. 指针移动语句顺序出错，导致死循环
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * ReverseList(ListNode* pHead) {
        // 再次失败
        /*stack<ListNode *> sl;
        ListNode* p = pHead;
        while (p) {
            sl.push(p);
            p = p->next;
        }

        ListNode * h = sl.top();
        sl.pop();
        p = h;
        while (!sl.empty()) {
            p->next = sl.top();
            p = p->next;
            sl.pop();
        }
        p->next = NULL;
        return h;*/

        // 常规作法
        if (pHead == NULL)
            return NULL;

        ListNode* cur = pHead;
        ListNode* pre = NULL;
        ListNode* nxt = cur->next;
        cur->next = NULL;
        while (nxt) {
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            cur->next = pre;
        }
        return cur;
    }
};

void
solve()
{
    ListNode l1{ 1 };
    ListNode l2{ 2 };
    ListNode l3{ 3 };
    ListNode l4{ 4 };
    ListNode l5{ 5 };
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode* ret = Solution().ReverseList(&l1);

}