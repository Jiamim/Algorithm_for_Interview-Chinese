/*
从头到尾打印链表 https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个链表，从尾到头打印链表每个节点的值。

时间限制：1秒 空间限制：32768K 热度指数：473746
本题知识点： 链表

提交记录：
    一次过
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {

        deque<int> tmp;

        ListNode *p = head;
        while (p != NULL) {
            tmp.push_front(p->val);
            p = p->next;
        }

        return vector<int>(tmp.begin(), tmp.end());
    }
};

void solve() {

    //Solution().printListFromTailToHead();
}