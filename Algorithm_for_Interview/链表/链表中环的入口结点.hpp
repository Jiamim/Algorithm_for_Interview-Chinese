/*
链表中环的入口结点 https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
一个链表中包含环，请找出该链表的环的入口结点。

时间限制：1秒 空间限制：32768K 热度指数：78895
本题知识点： 链表

解题思路:
    1. 利用 set 存储走过的位置，需要额外的空间
    2. 利用两个移动速度不同的指针，同时前进，它们总会相遇，
        相遇时：快指针比，慢指针多走了 k 圈
        此时，将其中一个指针重新指向链表头，再让它们同步移动
        当他们再次相遇时，所指位置即为环的入口
        不需要额外空间，但是时间会更长一些，复杂度不变

提交记录：
    1. 思路1 pass
    2. 

*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * EntryNodeOfLoop_1(ListNode* pHead)
    {
        ListNode* p = pHead;
        if (p == NULL) return pHead;

        ListNode* ret = NULL;
        set<ListNode*> s;
        while (p) {
            if (s.count(p) > 0) {
                ret = p;
                break;
            }
            s.emplace(p);
            p = p->next;
        }

        return ret;
    }

    ListNode * EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* ret = NULL;
        if (pHead == NULL) return ret;

        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while (fast != NULL && fast->next != NULL)
        {   
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = pHead;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                ret = slow;
                break;
            }
        }
        
        return ret;
    }
};
