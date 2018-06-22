/*
链表中倒数第k个结点 https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个链表，输出该链表中倒数第k个结点。

时间限制：1秒 空间限制：32768K 热度指数：331070
本题知识点： 链表

解题思路：
    1. 栈（测试不通过，但是感觉逻辑应该没有问题）
    2. 双指针（讨论区通用做法）

提交记录：
    1. 没有考虑 k 大于链表长度的情况
    2. 格外小心边界情况，自己手动推两个用例
*/
#pragma once

#include "../all.h"

class Solution {
public:
    ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 栈
        /*
        ListNode * cur = pListHead;
        stack<ListNode*> sl;
        
        while (cur) {
            sl.push(cur);
            cur = cur->next;
        }

        k--;
        while (k--) {
            sl.pop();
        }

        return sl.top();*/

        ListNode * pre = pListHead;
        ListNode * nxt = pListHead;
        //先让 nxt 走 k-1 步
        while (k && nxt) {
            nxt = nxt->next;
            k--;
        }

        // 如果 k > 0，说明 k 比 链表还长，返回 NULL
        if (k > 0) {
            return NULL;
        }

        // 接着让两个指针一起往后走，当 nxt 到最后时，pre 即指向倒数第 k 个
        while (nxt) {
            nxt = nxt->next;
            pre = pre->next;
        }
        
        return pre;
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

    Solution().FindKthToTail(&l1, 6);

}