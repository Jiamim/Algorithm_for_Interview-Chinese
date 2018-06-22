/*
删除链表中重复的结点 https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

时间限制：1秒 空间限制：32768K 热度指数：137194
本题知识点： 链表

解题思路：
    记录前一个节点

    注意：因为头结点也可能重复被删除，所以需要设置一个新的结点，指向原头结点

    因为只是 OJ，所以处理方式为丢弃节点，并没有删除，这点要注意

提交记录：
    1. 头节点处理错误
    2. 没有保持好 pre 和 cur 的相邻关系

*/
#pragma once
#include "../all.h"

class Solution {
public:
    ListNode * deleteDuplication(ListNode* pHead)
    {   
        if (pHead == NULL) return pHead;

        ListNode* head = new ListNode{-1};  // 设置一个头结点
        head->next = pHead;

        ListNode* pre = head;
        ListNode* cur = pHead;
        while (cur != NULL && cur->next != NULL) {
            if (cur->val != cur->next->val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                int val = cur->val;
                while (cur != NULL && cur->val == val)
                    cur = cur->next;
                pre->next = cur;
            }
        }

        return head->next;
    }
};

void solve()
{
    
}
