/*
两个链表的第一个公共结点 https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入两个链表，找出它们的第一个公共结点。

时间限制：1秒 空间限制：32768K 热度指数：95850
本题知识点： 链表

解题思路：
    先分别遍历一遍得到两者的长度 m n；如果 m>n，则用一个临时指针移动到长链表的 m-n 位置
    接下来当作两个等长的链表找第一个公共位置

提交记录：

*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) return NULL;

        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        int l1 = getListLength(p1);
        int l2 = getListLength(p2);

        if (l1 > l2) {
            p1 = walkStep(p1, l1 - l2);
        }
        else {
            p2 = walkStep(p2, l2 - l1);
        }

        while (p1 != NULL) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }

    int getListLength(ListNode *head) {
        if (head == NULL) return 0;
        int sum = 1;
        while (head = head->next) sum++;
        return sum;
    }

    ListNode * walkStep(ListNode *head, int step) {
        while (step--) {
            head = head->next;
        }
        return head;
    }
};

void
solve()
{

}